# Install C/C++ Compiler in Windows

## Overview
This guide shows how to install MinGW-W64 C/C++ compiler for Windows to enable VS Code to execute Makefile.bat and compile C/C++ programs.

## Step 1: Download MinGW-W64

1. Visit the [MinGW-W64 releases page](https://github.com/niXman/mingw-builds-binaries/releases)
2. Download the latest release (recommended: `x86_64-posix-seh` for 64-bit Windows)
3. Extract the downloaded archive to `C:\mingw64\` (or your preferred location)

## Step 2: Set Environment Variables

1. Open **System Properties** → **Advanced** → **Environment Variables**
2. In **System Variables**, find and select **PATH**
3. Click **Edit** and add: `C:\mingw64\bin`
4. Click **OK** to save changes

## Step 3: Verify Installation

Open Command Prompt and test:
```bash
gcc --version
g++ --version
make --version
```

## Step 4: Configure VS Code

1. Install the **C/C++** extension in VS Code
2. Create or open your project with Makefile
3. Use **Terminal** → **Run Task** to execute Makefile.bat
4. Or run directly in terminal: `make` or `./Makefile.bat`

## Troubleshooting

- Restart VS Code after PATH changes
- Ensure no spaces in MinGW installation path
- Check that `mingw32-make.exe` is available for Makefile execution
