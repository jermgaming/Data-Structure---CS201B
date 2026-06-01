import os
from openai import OpenAI

OPENROUTER_API_KEY = os.environ["OPENROUTER_API_KEY"]

client = OpenAI(
    base_url="https://openrouter.ai/api/v1",
    api_key=OPENROUTER_API_KEY,
)

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

print(f"📁 Found {len(code_snippets)} code file(s). Sending to AI...")

# ── Trim if too large ───────────────────────────────────────────────
if len(all_code) > 12000:
    print("⚠️ Code too large, trimming to 12000 chars...")
    all_code = all_code[:12000]

# ── Build the prompt ────────────────────────────────────────────────
prompt = f"""
You are a technical documentation expert.

Analyze the following source code files from a GitHub repository and generate a comprehensive, well-structured README.md.

Include:
- Project title and description
- What the project does and its purpose
- File/folder structure explanation
- Explanation of each file and key functions/classes
- How to compile and run the code
- Data structures or algorithms used
- Key concepts demonstrated

Source files:

{all_code}

Generate a clean, professional README.md in Markdown format only. No extra commentary.
"""

# ── Call OpenRouter via OpenAI SDK ──────────────────────────────────
print("📡 Calling OpenRouter API...")

response = client.chat.completions.create(
    model="nvidia/nemotron-3-nano-omni-30b-a3b-reasoning:free",
    messages=[
        {"role": "user", "content": prompt}
    ],
    extra_body={"reasoning": {"enabled": True}}
)

readme_content = response.choices[0].message.content

# ── Write README.md ─────────────────────────────────────────────────
with open("README.md", "w") as f:
    f.write(readme_content)

print("✅ README.md generated successfully!")