Here is the module-based version.

# Mini Library Management System - Module-Based Design Document

## Goal

We are building a small Library Management System in C++.

The goal is not to build the next Texas State library software. The goal is to learn how a C++ project can be organized into modules instead of one giant `main.cpp` monster.

---

# Project Structure

```text
LibraryManagementSystem/
│
├── include/
│   ├── models/
│   │   ├── librarian.h
│   │   ├── book.h
│   │   ├── student.h
│   │   └── borrow_record.h
│   │
│   └── services/
│       ├── book_service.h
│       ├── student_service.h
│       └── rental_service.h
│
├── src/
│   ├── models/
│   │   ├── librarian.cpp
│   │   ├── book.cpp
│   │   ├── student.cpp
│   │   └── borrow_record.cpp
│   │
│   └── services/
│       ├── book_service.cpp
│       ├── student_service.cpp
│       └── rental_service.cpp
│
└── main.cpp
```

---

# Big Picture

The system has four main data ideas:

```text
LIBRARIAN
BOOK
STUDENT
BORROW_RECORD
```

Plain English:

```text
One librarian manages all books.

Books store inventory information.

Students borrow and return books.

Each student stores their own borrow history.

Each borrow record represents one borrowing event.
```

Important borrowing rule:

```text
A student can borrow multiple books with different ISBNs.

A student cannot borrow the same ISBN twice at the same time.

A student can borrow the same ISBN again after returning it.
```

---

# models/ Module

The `models/` module stores the shape of the data.

Think of this as the library paperwork department. It does not do much. It just defines what information exists.

---

## `librarian.h`

Contains the `Librarian` structure.

Fields:

```text
librarian_id
librarian_name
```

Since this project has only one librarian, we only need one librarian object in `main.cpp`.

---

## `book.h`

Contains:

```text
Book
Books
```

`Book` fields:

```text
isbn
title
total_count
available_count
rented_count
```

`Books` represents a collection of books.

Plain English:

```text
Book = one book record

Books = the whole shelf
```

---

## `borrow_record.h`

Contains the `BorrowRecord` structure.

Fields:

```text
isbn
book_title
rent_date
due_date
return_date
is_completed
is_overdue
```

Notes:

```text
return_date is empty if the book is not returned yet.

is_completed is false while the book is still borrowed.

is_overdue is true if the book is late.
```

Plain English:

```text
BorrowRecord remembers one borrowing event.
```

---

## `student.h`

Contains:

```text
Student
Students
```

`Student` fields:

```text
student_id
student_name
borrow_history
```

`borrow_history` stores multiple `BorrowRecord` items.

Example:

```text
Alice
- C++ Primer, returned
- Clean Code, active
- Algorithms, overdue
```

Plain English:

```text
Student = one student

Students = the whole class

borrow_history = the student's personal library receipt folder
```

---

# services/ Module

The `services/` module contains actions.

Models describe things. Services do things.

---

## `book_service.h`

Contains prototypes for book-related operations.

Functions:

```text
add_book
delete_book
find_book_by_isbn
display_books
```

Rules:

```text
The librarian can add books.

The librarian can delete a book only if rented_count is 0.

If rented_count is not 0, someone still has the book. Do not delete a book while it is spiritually and physically outside the library.
```

---

## `student_service.h`

Contains prototypes for student-related operations.

Functions:

```text
add_student
find_student_by_id
display_students
display_student_history
display_active_borrows
display_overdue_borrows
```

Purpose:

```text
Create students.

Find students.

Show what a student has borrowed.

Show active or overdue records.
```

---

## `rental_service.h`

Contains prototypes for borrowing and returning operations.

Functions:

```text
rent_book
return_book
```

Renting a book should:

```text
1. Check if the student exists.
2. Check if the book exists.
3. Check if available_count > 0.
4. Check if the student does not already have an active borrow record for the same ISBN.
5. Decrease available_count.
6. Increase rented_count.
7. Add a borrow record to the student.
```

Returning a book should:

```text
1. Find the student.
2. Find the book.
3. Find the student's active borrow record for that ISBN.
4. Mark the borrow record as completed.
5. Store the return date.
6. Update overdue status if needed.
7. Increase available_count.
8. Decrease rented_count.
```

---

# main.cpp Usage

`main.cpp` should only simulate the system.

Do not write the entire project inside `main.cpp`.

Use it like a short movie script.

Example flow:

```text
1. Create one librarian.

2. Create a Books collection.

3. Create a Students collection.

4. Add students:
   - Alice
   - Bob
   - Charlie

5. Librarian adds books:
   - C++ Primer
   - Clean Code
   - Design Patterns

6. Alice rents C++ Primer.

7. Alice tries to rent C++ Primer again.
   This should fail because she already has an active copy.

8. Alice rents Clean Code.
   This should work because it has a different ISBN.

9. Alice returns C++ Primer.

10. Alice rents C++ Primer again.
    This should work because the previous record is completed.

11. Display all books.

12. Display Alice's borrowing history.
```

---

# Header File Focus

Header files should contain:

```text
Struct definitions

Collection struct definitions

Function prototypes
```

Header files should not contain:

```text
Large function implementations

Random testing code

A secret second main function

using namespace std;
```

---

# Final Mental Model

```text
models/
Defines what exists.

services/
Defines what the system can do.

src/
Contains the actual implementation.

main.cpp
Runs the simulation.
```

The project is small, but the design idea is serious:

```text
A larger program is easier to understand when each file has one clear responsibility.
```

The books are fake. The librarian is fake. The compiler errors will be painfully real.