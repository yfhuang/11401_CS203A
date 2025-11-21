# Assignment IV: Hash Function Design & Observation

## Important Dates
- **Due Date**: 2025.11.23 23:59:59  
- **Submission**: Submit your code in C and C++ along with `README.md` in your course repository (`11401_CS203A/Assignment/AssignmentIV/`).

## Learning Objectives
- Understand how the **choice of hash function** and **table size** (m) affects index distribution.
- Design and implement hash functions for both **integer keys** and **string keys**.
- Gain practical experience in creating and testing **hash functions** in C and C++.
- Analyze **index patterns**, **collision rates**, and **distribution uniformity** for various table sizes (m).
- Learn how to use [Visual Studio Code to connect to your GitHub repository](./VSCode.md) for seamless version control and collaboration.

## Repository Structure
```
AssignmentIV
├── C                       # C implementation directory
│   ├── hash_fn.c           # Hash function implementation in C
│   ├── hash_fn.h           # Header file for C hash functions
│   └── main.c              # Main program calling hash functions
├── CXX                     # C++ implementation directory
│   ├── hash_fn.cpp         # Hash function implementation in C++
│   ├── hash_fn.hpp         # Header file for C++ hash functions
│   └── main.cpp            # Main program calling hash functions
├── Makefile                # Build configuration file for Linux platform
├── Makefile.bat            # Build configuration file for Windows platform
├── README.md               # Assignment documentation
├── README_template.md      # Template for README documentation
└── VSCode.md               # VS Code setup instructions
```

## Getting Started

1. **Clone the Repository**  
    Clone the repository to your local machine (new folder not your repository folder, e.g. /tmp/):
    ```bash
    git clone <repository-url>
    ```

2. **Create the Folder in your Respoitory**  
    Navigate to your repository and create the assignment folder:
    ```bash
    cd Assignment
    mkdir AssignmentIV
    ```

3. **Copy Template Files**  
    Copy the provided templates and example code:
    ```bash
    cp /tmp/11401_CS203A/Assignment/AssignmentIV/README_template.md README.md
    cp /tmp/11401_CS203A/Assignment/AssignmentIV/Makefile .
    cp /tmp/11401_CS203A/Assignment/AssignmentIV/Makefile.bat .
    cp /tmp/11401_CS203A/Assignment/AssignmentIV/VSCode.md .
    rsync -av /tmp/11401_CS203A/Assignment/AssignmentIV/C .
    rsync -av /tmp/11401_CS203A/Assignment/AssignmentIV/CXX .
    ```

4. **Verify Folder Structure**  
    Ensure the folder structure is correct:
    ```bash
    cd Assignment
    tree -L 2 AssignmentIV
    ```
    Expected output:
    ```
    AssignmentIV
    ├── C
    │   ├── hash_fn.c
    │   ├── hash_fn.h
    │   └── main.c
    ├── CXX
    │   ├── hash_fn.cpp
    │   ├── hash_fn.hpp
    │   └── main.cpp
    ├── Makefile                # Build configuration file for Linux platform
    ├── Makefile.bat            # Build configuration file for Windows platform
    ├── README.md               # README documentation
    └── VSCode.md               # VS Code setup instructions
    ```

5. **Understand the Code**  
    - **C**:
      - `main.c`: Calls your hash function.
      - `hash_fn.c`: Implement your hash functions here.
    - **C++**:
      - `main.cpp`: Calls your hash function.
      - `hash_fn.cpp`: Implement your hash functions here.

6. **Develop, Test, and Document**  
    - Implement and test your hash functions.
    - Document your development process and observations in `README.md`.

## Folder Structure in Your Course Repository
```
AssignmentIV/
├── C/                      # C implementation directory
│   ├── hash_fn.c           # Hash function implementation in C
│   ├── hash_fn.h           # Header file for C hash functions
│   └── main.c              # Main program calling hash functions
├── CXX/                    # C++ implementation directory
│   ├── hash_fn.cpp         # Hash function implementation in C++
│   ├── hash_fn.hpp         # Header file for C++ hash functions
│   └── main.cpp            # Main program calling hash functions
├── Makefile                # Build configuration file for Linux platform
├── Makefile.bat            # Build configuration file for Windows platform
├── README.md               # README documentation
└── VSCode.md               # VS Code setup instructions
```

## Assignment Instructions
- **Objective**: Design and implement a hash function in C/C++ and analyze its index distribution.
- **Steps**:
  1. Implement the hash function in `hash_fn.c` and `hash_fn.cpp`.
  2. Use the hash function in `main.c` and `main.cpp`.
- **Submission**: Push your code and testing results to the repository.

## Source Code Commit

- Make at least three commits for this assignment:
    1. Initial commit: Add `README.md`, `Makefile`, `Makefile.bat`, `VSCode.md` and the example C and C++ template files (`C/hash_fn.c`, `C/hash_fn.h`, `C/main.c`, `CXX/hash_fn.cpp`, `C/hash_fn.hpp`, `CXX/main.cpp`).
    2. Development commits: Include one or more intermediate commits that record your implementation progress, tests, bug fixes, and small iterative changes. Use descriptive messages (e.g., "implement integer hash", "add string-hash tests", "fix collision handling").
    3. Final commit: Include the finished code, updated `README.md` with observations, test results, and final evaluation.

- Commit guidelines:
    - Write clear, concise commit messages that summarize the change.
    - Ensure the `README.md` documents the development history (brief commit log or references to commit IDs) and highlights the final evaluation.
    - Update `VSCode.md` with your setup experience and any additional configuration steps you discovered during development.
    - Push all commits to the course repository under `AssignmentIV` before the deadline.

## Coding and Documentation Style

To ensure your code is readable, maintainable, and adheres to best practices, follow these guidelines:

### 1. Code Style
- **Indentation**: Use consistent indentation (e.g., 4 spaces per level).
- **Naming Conventions**:
    - Use `snake_case` for variable and function names in C. Refer to [ISO C Style Guidelines](https://en.cppreference.com/w/c/language/identifier) for more details.
    - Use `camelCase` or `PascalCase` for variable and function names in C++. Refer to [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-naming) for best practices.
- **Comments**:
    - Add meaningful comments to explain the purpose of functions, complex logic, and key sections of code.
    - Avoid redundant comments that merely restate the code.
- **Line Length**: Limit lines to 80-100 characters for better readability.

### 2. Documentation
- **Function Headers**:
    - Include a brief description, input parameters, and return values for each function.
    - Example:
        ```c
        /**
         * @brief Computes the hash index for an integer key.
         * @param key The integer key to hash.
         * @param m The table size.
         * @return The computed hash index.
         */
        int myHashInt(int key, int m);
        ```
- **File Headers**:
    - Add a header comment at the top of each file with the file's purpose, author, and modification history.

### 3. Testing and Observations
- Test your hash functions with a variety of inputs and table sizes.
- Document your findings in the `README.md`:
    - Include tables or charts showing index distributions.
    - Analyze collision rates and uniformity of the hash function.

### 4. Error Handling
- Ensure your code handles edge cases gracefully (e.g., empty strings, zero table size).
- Validate inputs where necessary and provide meaningful error messages.

By adhering to these practices, you will develop clean, professional, and well-documented code that is easy to understand and maintain.

## Notes
- Ensure your code is well-documented and adheres to the provided coding standards.
- Include observations and analysis in your `README.md`.

## References
- [Learning Git](https://github.com/doggy8088/Learn-Git-in-30-days/tree/master)
