#include <iostream>

#include "models/librarian.h"
#include "models/book.h"
#include "models/student.h"
#include "services/book_service.h"
#include "services/student_service.h"
#include "services/rental_service.h"

int main() {
    // Run following simulation, do this one step at a time
    Librarian librarian{"L001", "Ms. Rivera"};

    Books books;
    Students students;

    std::cout << "Library managed by " << librarian.librarian_name << "\n";
    add_student(students, "S001", "Alice");
    add_student(students, "S002", "Bob");
    add_student(students, "S003", "Charlie");

    add_book(books, "978-0321714114", "C++ Primer", 2);
    add_book(books, "978-0132350884", "Clean Code", 1);
    add_book(books, "978-0201633610", "Design Patterns", 1);

    Student* alice = find_student_by_id(students, "S001");
    /*

    rent_book(books, students, "S001", "978-0321714114", "2026-06-01", "2026-06-15");
    rent_book(books, students, "S001", "978-0321714114", "2026-06-02", "2026-06-16");

    rent_book(books, students, "S001", "978-0132350884", "2026-06-03", "2026-06-17");

    return_book(books, students, "S001", "978-0321714114", "2026-06-10");

    rent_book(books, students, "S001", "978-0321714114", "2026-06-11", "2026-06-25");

    display_books(books);

    if (alice != nullptr) {
        display_student_history(*alice);
    }
    */
    return 0;
}
