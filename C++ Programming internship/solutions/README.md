C++ Programming Internship — Solutions

This folder contains reference implementations for the C++ tasks from the internship sheet. Each program is a small, self-contained console application.

Files and brief descriptions:
- `task1_cgpa.cpp` — Read a list of courses, grades and credit hours, compute total credits, total grade points and final CGPA.
- `task2_auth.cpp` — Minimal registration/login demo storing `username:hash` lines in `users.txt`. Note: uses `std::hash` for demonstration only (not secure for production).
- `task3_sudoku.cpp` — Backtracking-based Sudoku solver. Accepts 9 lines of input (use 0 for blanks) or uses a sample puzzle if you press Enter.

How to compile (from workspace root):
```bash
g++ -std=c++17 -O2 -Wall "C++ Programming internship/solutions/task1_cgpa.cpp" -o "C++ Programming internship/solutions/task1_cgpa"
g++ -std=c++17 -O2 -Wall "C++ Programming internship/solutions/task2_auth.cpp" -o "C++ Programming internship/solutions/task2_auth"
g++ -std=c++17 -O2 -Wall "C++ Programming internship/solutions/task3_sudoku.cpp" -o "C++ Programming internship/solutions/task3_sudoku"
```

Basic usage notes:
- `task1_cgpa`: follow prompts to enter course name, grade points and credit hours. The program prints per-course points and the computed CGPA.
- `task2_auth`: choose `1` to register (appends to `users.txt`), `2` to login. Passwords are hashed with a simple non-cryptographic hash for demo purposes only.
- `task3_sudoku`: either press Enter at the prompt to run the included sample puzzle or paste 9 rows (space-separated digits) to solve custom puzzles.

Submission guidance:
- Include source files and a README at the repository root explaining how to build and run each program.
- Do not store real passwords in plain text in any submission; the provided auth demo is educational only.

Contact: services@codealpha.tech

