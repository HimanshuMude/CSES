import os

def generate_fancy_index():
    base_url = "https://github.com/HimanshuMude/CSES/blob/main"
    lines = ["# 📂 Repository Index\n\n"]
    for root, dirs, files in os.walk("."):
        level = root.replace(".", "").count(os.sep)
        indent = " " * 2 * level
        folder_path = root.replace("./", "")
        if folder_path:
            lines.append(f"{indent}- 📁 **[{os.path.basename(root)}/]({base_url}{folder_path}/)**\n")
        else:
            lines.append(f"{indent}- 🏠 **[Root Directory](https://github.com/<username>/<repository-name>/)**\n")
        for file in files:
            file_path = os.path.join(folder_path, file).replace("\\", "/")
            file_emoji = "📄" if file.endswith((".md", ".txt")) else "🛠️"
            lines.append(f"{indent}  - {file_emoji} [{file}]({base_url}{file_path})\n")
    return "".join(lines)

if __name__ == "__main__":
    with open("README.md", "w",encoding='utf-8') as readme:
        readme.write(generate_fancy_index())
