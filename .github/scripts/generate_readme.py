import os
import requests
import json

OPENROUTER_API_KEY = os.environ["OPENROUTER_API_KEY"]

# ── Collect all code files ──────────────────────────────────────────
EXTENSIONS = {".py", ".cpp", ".c", ".h", ".java", ".js", ".ts", ".cs"}
IGNORE_DIRS = {".git", ".github", "node_modules", "__pycache__"}

code_snippets = []

for root, dirs, files in os.walk("."):
    dirs[:] = [d for d in dirs if d not in IGNORE_DIRS]
    for file in files:
        if any(file.endswith(ext) for ext in EXTENSIONS):
            filepath = os.path.join(root, file)
            with open(filepath, "r", errors="ignore") as f:
                content = f.read()
            code_snippets.append(f"### File: `{filepath}`\n```\n{content}\n```")

all_code = "\n\n".join(code_snippets)

if not all_code.strip():
    print("⚠️ No code files found!")
    exit(1)

# ── Build the prompt ────────────────────────────────────────────────
prompt = f"""
You are a technical documentation expert.

Analyze the following source code files from a GitHub repository and generate a comprehensive, well-structured README.md file.

Include:
- Project title and description
- What the project does / its purpose
- File/folder structure explanation
- Explanation of each file and key functions/classes
- How to run or use the code
- Data structures or algorithms used (if any)
- Key concepts demonstrated

Here are the source files:

{all_code}

Generate a clean, professional README.md in Markdown format.
"""

# ── Call OpenRouter API ─────────────────────────────────────────────
payload = {
    "model": "mistralai/mistral-7b-instruct:free",  # use :free tag
    "messages": [
        {"role": "user", "content": prompt}
    ],
    "max_tokens": 2000,
}

print("📡 Calling OpenRouter API...")

response = requests.post(
    "https://openrouter.ai/api/v1/chat/completions",
    headers={
        "Authorization": f"Bearer {OPENROUTER_API_KEY}",
        "Content-Type": "application/json",
        "HTTP-Referer": "https://github.com",
        "X-Title": "README Generator",
    },
    json=payload,
    timeout=60,
)

print(f"Status Code: {response.status_code}")

data = response.json()

# ── Debug: print full response if something goes wrong ──────────────
if "choices" not in data:
    print("❌ Unexpected API response:")
    print(json.dumps(data, indent=2))
    exit(1)

readme_content = data["choices"][0]["message"]["content"]

# ── Write README.md ─────────────────────────────────────────────────
with open("README.md", "w") as f:
    f.write(readme_content)

print("✅ README.md generated successfully!")