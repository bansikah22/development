# C Programming Setup Guide for IntelliJ IDEA 🚀

## What You Need to Install 📥

### For macOS:

#### 1. Install Xcode Command Line Tools (Recommended)
```bash
xcode-select --install
```
This gives you:
- `gcc` compiler
- `clang` compiler  
- All necessary development tools

#### 2. Alternative: Install Homebrew + GCC
```bash
# Install Homebrew first
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Then install GCC
brew install gcc
```

### For Windows:

#### Option 1: MinGW-w64
1. Download from: https://www.mingw-w64.org/
2. Install and add to PATH
3. Provides `gcc` compiler

#### Option 2: Microsoft Visual Studio Build Tools
1. Download Visual Studio Community
2. Install C++ build tools
3. Provides `cl` compiler

### For Linux (Ubuntu/Debian):
```bash
sudo apt update
sudo apt install build-essential
sudo apt install gcc
```

## IntelliJ IDEA Setup 🛠️

### 1. Install Required Plugins

Go to **File → Settings → Plugins** and install:

1. **C/C++** plugin by JetBrains
   - Provides syntax highlighting
   - Code completion
   - Error detection

2. **CLion Nova** (if available)
   - Advanced C/C++ support
   - Better debugging

### 2. Configure C Compiler

1. **File → Settings → Build, Execution, Deployment → Toolchains**
2. Click **"+"** to add new toolchain
3. Set:
   - **Name**: "C Compiler"
   - **Environment**: System (or WSL for Windows)
   - **C Compiler**: `/usr/bin/gcc` (or your gcc path)
   - **C++ Compiler**: `/usr/bin/g++` (optional)
   - **Debugger**: `/usr/bin/gdb`

### 3. Create C Project

1. **File → New → Project**
2. Choose **"C Executable"** or **"Empty Project"**
3. Set project location
4. Choose your toolchain

### 4. Configure Run Configuration

1. **Run → Edit Configurations**
2. Click **"+"** → **"C/C++ Application"**
3. Set:
   - **Name**: "Run C Program"
   - **Target**: Your executable
   - **Program arguments**: (if needed)

## Alternative: Using Terminal 💻

### Compile and Run Commands

```bash
# Navigate to your C file directory
cd /path/to/your/c/files

# Compile a single file
gcc filename.c -o filename
./filename

# Example:
gcc hello.c -o hello
./hello

# Compile with debugging info
gcc -g filename.c -o filename

# Compile with warnings (recommended)
gcc -Wall -Wextra filename.c -o filename
```

### Useful GCC Flags

- `-Wall`: Enable all warnings
- `-Wextra`: Extra warnings
- `-g`: Include debug information
- `-O2`: Optimize code
- `-std=c99`: Use C99 standard
- `-std=c11`: Use C11 standard

## Recommended VS Code Alternative 🆚

If IntelliJ doesn't work well, try **VS Code**:

1. Install **VS Code**
2. Install extensions:
   - **C/C++** by Microsoft
   - **Code Runner**
   - **C/C++ Compile Run**

3. Create `.vscode/tasks.json`:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "compile C",
            "type": "shell",
            "command": "gcc",
            "args": ["-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

## Testing Your Setup ✅

Create a test file `test.c`:

```c
#include <stdio.h>

int main() {
    printf("Hello, C Programming!\n");
    printf("Setup is working! 🎉\n");
    return 0;
}
```

Compile and run:
```bash
gcc test.c -o test
./test
```

You should see:
```
Hello, C Programming!
Setup is working! 🎉
```

## Troubleshooting 🔧

### Common Issues:

1. **"gcc command not found"**
   - Install Xcode Command Line Tools (macOS)
   - Install build-essential (Linux)
   - Install MinGW (Windows)

2. **"Permission denied"**
   - Make file executable: `chmod +x filename`

3. **IntelliJ can't find compiler**
   - Check toolchain settings
   - Verify gcc installation: `gcc --version`

### Getting Help:
- Check compiler version: `gcc --version`
- Check installation: `which gcc`
- Test simple compilation: `gcc --help`

## Learning Path 📚

1. Start with simple programs in terminal
2. Get comfortable with gcc commands
3. Then move to IntelliJ for larger projects
4. Learn debugging with gdb
5. Explore advanced compiler features

Happy coding! 🚀
