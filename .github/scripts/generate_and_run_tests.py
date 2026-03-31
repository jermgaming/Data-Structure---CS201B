import os
import sys
import subprocess
import glob
from openai import OpenAI

client = OpenAI(
    api_key=os.environ["GROQ_API_KEY"],
    base_url="https://api.groq.com/openai/v1",
)

def get_changed_c_files():
    """Get .c files changed in the last commit"""
    result = subprocess.run(
        ["git", "diff", "--name-only", "HEAD~1", "HEAD"],
        capture_output=True, text=True
    )
    files = result.stdout.strip().split("\n")
    c_files = [f for f in files if f.endswith('.c') and os.path.exists(f)]
    return c_files

def get_all_c_files():
    """Fallback: get all .c files (for first commit or full run)"""
    all_files = glob.glob("**/*.c", recursive=True)
    # Exclude already-generated test files
    return [f for f in all_files if not os.path.basename(f).startswith("test_")]

def read_file(path):
    with open(path, 'r', errors='ignore') as f:
        return f.read()

def generate_c_test(source_code, filepath):
    """Ask Ollama 70B via Groq to generate a C test file for the given C source"""
    filename = os.path.basename(filepath)

    prompt = f"""
You are a C testing expert. Given this C data structure implementation, generate a complete test file.

File: {filename}
Source Code:
```c
{source_code}
```

Rules for the test file:
1. It must be a single, self-contained .c file
2. Copy all necessary struct definitions and helper functions from the source — do NOT use #include "{filename}"
3. Use assert() from <assert.h> for all checks
4. Include <stdio.h>, <stdlib.h>, <assert.h>, <string.h> as needed
5. Write a main() that runs all tests and prints "ALL TESTS PASSED" at the end
6. Test: normal cases, edge cases (empty list/stack/queue, single element), and boundary conditions
7. If the code uses dynamic memory (malloc/free), test for memory correctness
8. Do NOT use any external testing framework
9. Return ONLY valid C code — no markdown, no explanation, no backticks

The output must compile cleanly with: gcc -std=c99 -Wall test_file.c -o test_binary
"""

    response = client.chat.completions.create(
        model="llama2-70b",
        messages=[{"role": "user", "content": prompt}],
        max_tokens=3000,
    )
    return response.choices[0].message.content.strip()

def compile_and_run_c_test(test_code, source_filepath):
    """Write, compile with gcc, and run the C test"""
    base_name = os.path.basename(source_filepath).replace('.c', '')
    test_filename = f"test_{base_name}.c"
    binary_name = f"test_{base_name}_bin"

    # Write the generated test file
    with open(test_filename, 'w') as f:
        f.write(test_code)

    print(f"\n{'='*60}")
    print(f"📄 Source:    {source_filepath}")
    print(f"🧪 Test file: {test_filename}")

    # Compile with gcc
    compile_result = subprocess.run(
        ["gcc", "-std=c99", "-Wall", "-o", binary_name, test_filename, "-lm"],
        capture_output=True, text=True
    )

    if compile_result.returncode != 0:
        print(f"❌ COMPILE FAILED:\n{compile_result.stderr}")
        return False

    print(f"✅ Compiled successfully")

    # Run the test binary
    try:
        run_result = subprocess.run(
            [f"./{binary_name}"],
            capture_output=True, text=True, timeout=15
        )
    except subprocess.TimeoutExpired:
        print("❌ TEST TIMED OUT (infinite loop?)")
        return False

    if run_result.stdout:
        print(f"Output:\n{run_result.stdout}")
    if run_result.stderr:
        print(f"Stderr:\n{run_result.stderr}")

    if run_result.returncode != 0:
        print(f"❌ TEST FAILED (exit code {run_result.returncode})")
        return False

    print(f"✅ ALL TESTS PASSED for {base_name}")
    return True

def cleanup(binary_name):
    try:
        os.remove(binary_name)
    except:
        pass

def main():
    print("🔍 Detecting changed C files...")
    changed_files = get_changed_c_files()

    if not changed_files:
        print("No changed .c files found in last commit — scanning all .c files...")
        changed_files = get_all_c_files()

    if not changed_files:
        print("⚠️  No .c files found to test.")
        sys.exit(0)

    print(f"\n📂 Files to test ({len(changed_files)} total):")
    for f in changed_files:
        print(f"   → {f}")

    results = {}

    for filepath in changed_files:
        print(f"\n🤖 Asking Ollama 70B via Groq to generate tests for: {filepath}")
        source_code = read_file(filepath)

        if len(source_code.strip()) < 20:
            print(f"⚠️  Skipping {filepath} — file too short or empty")
            continue

        try:
            test_code = generate_c_test(source_code, filepath)
        except Exception as e:
            print(f"❌ Ollama 70B via Groq API error for {filepath}: {e}")
            results[filepath] = False
            continue

        passed = compile_and_run_c_test(test_code, filepath)
        results[filepath] = passed

        # Cleanup binary
        base_name = os.path.basename(filepath).replace('.c', '')
        cleanup(f"test_{base_name}_bin")

    # Final summary
    print(f"\n{'='*60}")
    print("📊 TEST SUMMARY")
    print(f"{'='*60}")
    passed_count = sum(1 for v in results.values() if v)
    failed_count = sum(1 for v in results.values() if not v)

    for filepath, passed in results.items():
        icon = "✅" if passed else "❌"
        print(f"  {icon}  {filepath}")

    print(f"\n  Passed: {passed_count} / {len(results)}")

    if failed_count > 0:
        print(f"\n❌ {failed_count} file(s) failed. Pipeline FAILED.")
        sys.exit(1)
    else:
        print(f"\n🎉 All tests passed! Pipeline SUCCEEDED.")
        sys.exit(0)

if __name__ == "__main__":
    main()