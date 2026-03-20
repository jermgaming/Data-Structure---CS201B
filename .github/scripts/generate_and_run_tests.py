import os
import sys
import subprocess
import glob
from openai import OpenAI  

# Grok client setup
client = OpenAI(
    api_key=os.environ["GROK_API_KEY"],
    base_url="https://api.x.ai/v1",
)

def get_changed_files():
    """Get list of .cpp/.h files changed in the last commit"""
    result = subprocess.run(
        ["git", "diff", "--name-only", "HEAD~1", "HEAD"],
        capture_output=True, text=True
    )
    files = result.stdout.strip().split("\n")
    return [f for f in files if f.endswith(('.cpp', '.h', '.c'))]

def read_file(path):
    with open(path, 'r') as f:
        return f.read()

def generate_tests(source_code, filename):
    """Ask Grok to generate test cases for the given source code"""
    prompt = f"""
You are a C++ testing expert. Given this data structure implementation, generate 
comprehensive test cases using simple assert statements (no external frameworks needed).

File: {filename}
Code:
{source_code}

Generate a complete, compilable C++ test file that:
1. Includes the necessary headers
2. Tests edge cases, normal cases, and boundary conditions
3. Uses assert() for validation
4. Has a main() function that runs all tests
5. Prints "ALL TESTS PASSED" if successful

Return ONLY the C++ code, no markdown, no explanation.
"""
    response = client.chat.completions.create(
        model="grok-3",
        messages=[{"role": "user", "content": prompt}],
        max_tokens=2000,
    )
    return response.choices[0].message.content.strip()

def compile_and_run(test_code, test_filename):
    """Write, compile, and run the generated test"""
    # Write test file
    with open(test_filename, 'w') as f:
        f.write(test_code)

    # Compile
    compile_result = subprocess.run(
        ["g++", "-std=c++17", "-o", "test_binary", test_filename],
        capture_output=True, text=True
    )
    if compile_result.returncode != 0:
        print(f"❌ Compilation failed:\n{compile_result.stderr}")
        return False

    # Run
    run_result = subprocess.run(["./test_binary"], capture_output=True, text=True, timeout=30)
    print(run_result.stdout)
    if run_result.returncode != 0:
        print(f"❌ Tests failed:\n{run_result.stderr}")
        return False

    print(f"✅ Tests passed for {test_filename}")
    return True

def main():
    changed_files = get_changed_files()

    if not changed_files or changed_files == ['']:
        # Fallback: test all .cpp files if no diff found (e.g., first commit)
        changed_files = glob.glob("**/*.cpp", recursive=True)
        changed_files = [f for f in changed_files if "test" not in f.lower()]

    print(f"📂 Files to test: {changed_files}")

    all_passed = True
    for filepath in changed_files:
        if not os.path.exists(filepath):
            continue
        print(f"\n🔍 Generating tests for: {filepath}")
        source_code = read_file(filepath)
        test_code = generate_tests(source_code, filepath)
        test_file = f"generated_test_{os.path.basename(filepath)}"
        passed = compile_and_run(test_code, test_file)
        if not passed:
            all_passed = False

    sys.exit(0 if all_passed else 1)

if __name__ == "__main__":
    main()