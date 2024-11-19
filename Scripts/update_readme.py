import os

def generate_fancy_index(directory='.'):
    # List to hold lines of the index
    index_lines = []
    
    # Traverse the directory and subdirectories
    for root, dirs, files in os.walk(directory):
        # Filter out directories like .git, logs, and others that aren't relevant
        dirs[:] = [d for d in dirs if not d.startswith(('.', 'logs', 'refs', 'hooks'))]
        
        # Create a relative path from the current root
        relative_path = os.path.relpath(root, directory)
        
        # If it's the root directory, display it with an emoji
        if relative_path == '.':
            index_lines.append("📂 Repository Index")
            index_lines.append("📁 ./")
            index_lines.append("📄 [README.md](README.md)")
            index_lines.append("")  # Add a blank line
        
        # Display subdirectories and files
        elif files or dirs:
            # Display directories
            if dirs:
                index_lines.append(f"📁 {relative_path}/")
                for d in dirs:
                    index_lines.append(f"📁 {relative_path}/{d}")
            # Display files with links
            for file in files:
                # Ignore non-Python files or other irrelevant files
                if file.lower().endswith(('.py', '.md', '.txt', '.yml', '.yaml', '.json')):
                    file_path = os.path.join(relative_path, file)
                    # Add file with a link to the GitHub file path
                    index_lines.append(f"🛠️ [{file}]({f'https://github.com/HimanshuMude/CSES/blob/main/{file_path}})")
    
    # Join the lines into a string and return the result
    return '\n'.join(index_lines)

# Generate the fancy index and write it to the README
with open('README.md', 'w', encoding='utf-8') as readme:
    readme.write(generate_fancy_index())
