# Assignment IV: Hash Function Design & Observation

## Important Dates
- **Due Date**: 2025.11.23 23:59:59  
- **Submission**: Submit your code in C and C++ along with `README.md` in your course repository (`11401_CS203A/Assignment/AssignmentIV/`).

## Learning Objectives
- Understand how the **choice of hash function** and **table size** (m) affects index distribution.
- Design and implement hash functions for both **integer keys** and **string keys**.
- Gain practical experience in creating and testing **hash functions** in C and C++.
- Analyze **index patterns**, **collision rates**, and **distribution uniformity** for various table sizes (m).

## Repository Structure
```
AssignmentIV
├── C                       # Template code in C
│   ├── hash_fn.c           # Implement your hash function here
│   └── main.c              # Calls your hash function
├── CXX                     # Template code in C++
│   ├── hash_fn.cpp         # Implement your hash function here
│   └── main.cpp            # Calls your hash function
├── README_template.md      # Template for your README
└── README.md               # Assignment README
```

## Getting Started

1. **Clone the Repository**  
    Clone the repository to your local machine:
    ```bash
    git clone <repository-url>
    ```

2. **Create the Folder**  
    Navigate to your repository and create the assignment folder:
    ```bash
    cd Assignment
    mkdir AssignmentIV
    ```

3. **Copy Template Files**  
    Copy the provided templates and example code:
    ```bash
    cd Assignment/AssignmentIV/
    cp README_template.md README.md
    rsync -av C .
    rsync -av CXX .
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
    │   └── main.c
    ├── CXX
    │   ├── hash_fn.cpp
    │   └── main.cpp
    └── README.md

    3 directories, 5 files
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
AssignmentIV
├── C                       # Template code in C
│   ├── hash_fn.c           # Implement your hash function here
│   └── main.c              # Calls your hash function
├── CXX                     # Template code in C++
│   ├── hash_fn.cpp         # Implement your hash function here
│   └── main.cpp            # Calls your hash function
└── README.md               # Assignment README
```

## Assignment Instructions
- **Objective**: Design and implement a hash function in C/C++ and analyze its index distribution.
- **Steps**:
  1. Implement the hash function in `hash_fn.c` and `hash_fn.cpp`.
  2. Use the hash function in `main.c` and `main.cpp`.
- **Submission**: Push your code and testing results to the repository.

## Source Code Commit

- Make at least three commits for this assignment:
    1. Initial commit: add README.md and the example C and C++ template files (C/hash_fn.c, C/main.c, CXX/hash_fn.cpp, CXX/main.cpp).
    2. Development commits: include one or more intermediate commits that record your implementation progress, tests, bug fixes, and small iterative changes. Use descriptive messages (e.g., "implement integer hash", "add string-hash tests", "fix collision handling").
    3. Final commit: include the finished code, updated README.md with observations, test results, and final evaluation.

- Commit guidelines:
    - Write clear, concise commit messages that summarize the change.
    - Ensure the README.md documents the development history (brief commit log or references to commit IDs) and highlights the final evaluation.
    - Push all commits to the course repository under AssignmentIV before the deadline.

## Notes
- Ensure your code is well-documented and adheres to the provided coding standards.
- Include observations and analysis in your `README.md`.
