import os

EXCLUDE_DIRS = {'Scripts', '.github', 'node_modules', '.git', '__pycache__'}

def generate_index(path, base_url, indent=0):
    index = []
    items = sorted(os.listdir(path))
    for item in items:
        item_path = os.path.join(path, item)
        if os.path.isdir(item_path):
            if item in EXCLUDE_DIRS:
                continue
            index.append("  " * indent + f"- 📁 **[{item}]({base_url}/{item})**")
            index.extend(generate_index(item_path, f"{base_url}/{item}", indent + 1))
        else:
            index.append("  " * indent + f"- 📄 [{item}]({base_url}/{item})")
    return index

def main():
    repo_path = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    readme_path = os.path.join(repo_path, "README.md")
    base_url = "https://github.com/HimanshuMude/CSES/blob/main"  # Update with your repo URL

    index_content = ["# Repository Index\n"]
    index_content.extend(generate_index(repo_path, base_url))

    with open(readme_path, "w", encoding='utf-8') as readme_file:
        readme_file.write("\n".join(index_content))

if __name__ == "__main__":
    main()