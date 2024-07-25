# C++ Structure and Organization

## Running C++ in VS Code

To run C++ in Visual Studio Code, modify the `tasks.json` file as follows:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "C/C++: g++ build active file",
      "command": "/usr/bin/g++",
      "args": [
        "-g",
        "${fileDirname}/*.cpp",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "options": {
        "cwd": "/usr/bin"
      },
      "problemMatcher": [
        "$gcc"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}

To compile your C++ code, run the following command in the terminal:

```sh
g++ *.cpp

After compiling, execute the program with:
./a.exe

## Structure of C++ Files

### Header Files

Header files (`.h` or `.hpp`) contain:

- **Declarations** of classes or variables.
- **Inline implementations** (if necessary).

### Source Files

Source files (`.cpp`) contain:

- **Definitions and implementations** of the classes and functions declared in the header files.

### Driver File

The driver file, typically a `.cpp` file, includes all the necessary header files and contains the `main` function:

```cpp
#include "header1.h"
#include "header2.h"

int main() {
    // Your code here
    return 0;
}
