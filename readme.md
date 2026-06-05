# Mini Library Management System (C++)

Build a small, module-based library system. **Read [designdocs.md](designdocs.md)** for architecture, data models, business rules, and the simulation flow.

## What you implement

- `src/services/book_service.cpp`
- `src/services/student_service.cpp`
- `src/services/rental_service.cpp`

Headers in `include/` and model stubs in `src/models/` are provided. Do not put large logic in headers or `main.cpp`.

## Steps

1. Skim `designdocs.md` (models, services, borrowing rules, `main.cpp` flow).
2. Implement the three service files to match prototypes in `include/services/`.
3. In `main.cpp`, uncomment the simulation **one block at a time**, build, and fix errors before continuing.
4. When done, the program should run the full scenario in `main.cpp` (duplicate rent fails; return then re-rent succeeds; final book list and Alice’s history print).

## Build and Run

From the project root, use either:

```bash
./build.sh
./run.sh
```

or the direct commands:

```bash
g++ -std=c++20 -I include main.cpp src/models/*.cpp src/services/*.cpp -o main
./main
```

## Submission
**Option01.** Download a zip file from canvas, complete as much as you can. Upload this to the canvas.

**Option02.** Follow the pattern in Labs01 and open a PR, provide comments in submission with your branchname

Note: Please use aiusagedisclosure.md, for those who are making PR, do not share your email and sensitive information.