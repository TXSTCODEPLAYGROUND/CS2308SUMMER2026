#include <iostream> // Includes the standard input/output stream library for console printing

#include "models/librarian.h"       // Includes the data structure definition for a Librarian
#include "models/book.h"            // Includes the data structure definitions for Book and Books collections
#include "models/student.h"         // Includes the data structure definitions for Student and Students collections
#include "services/book_service.h"   // Includes the function prototypes for managing books (add, find, display)
#include "services/student_service.h"// Includes the function prototypes for managing students (add, find, history)
#include "services/rental_service.h" // Includes the function prototypes for core rental transactions (rent, return)

int main() { // Entry point of the C++ execution flow
    // Run following simulation, do this one step at a time

    Librarian librarian{"L001", "Ms. Rivera"}; // Instantiates a single Librarian object named Ms. Rivera with ID L001

    Books books;       // Instantiates an empty collection object to hold all available library books
    Students students; // Instantiates an empty collection object to track all registered students

    std::cout << "Library managed by " << librarian.librarian_name << "\n"; // Prints an introductory message acknowledging the manager

    add_student(students, "S001", "Alice");   // Registers a new student named Alice with ID S001 into the student database
    add_student(students, "S002", "Bob");     // Registers a new student named Bob with ID S002 into the student database
    add_student(students, "S003", "Charlie"); // Registers a new student named Charlie with ID S003 into the student database

    add_book(books, "978-0321714114", "C++ Primer", 2);      // Adds "C++ Primer" (2 total copies) to inventory under its unique ISBN
    add_book(books, "978-0132350884", "Clean Code", 1);      // Adds "Clean Code" (1 total copy) to inventory under its unique ISBN
    add_book(books, "978-0201633610", "Design Patterns", 1); // Adds "Design Patterns" (1 total copy) to inventory under its unique ISBN

    Student* alice = find_student_by_id(students, "S001"); // Searches the database for Alice's record using her student ID and stores the pointer

    rent_book(books, students, "S001", "978-0321714114", "2026-06-01", "2026-06-15"); // Processes Alice's initial rental transaction for "C++ Primer"
    rent_book(books, students, "S001", "978-0321714114", "2026-06-02", "2026-06-16"); // Attempts a duplicate rent for the same ISBN; this transaction must fail

    rent_book(books, students, "S001", "978-0132350884", "2026-06-03", "2026-06-17"); // Processes Alice's rental of "Clean Code"; should succeed (different ISBN)

    return_book(books, students, "S001", "978-0321714114", "2026-06-10"); // Processes the return of Alice's first copy of "C++ Primer", making it available again

    rent_book(books, students, "S001", "978-0321714114", "2026-06-11", "2026-06-25"); // Re-rents "C++ Primer" to Alice; should succeed since her previous active lease was closed

    display_books(books); // Prints out a status list of all books in the inventory along with their real-time availability numbers

    if (alice != nullptr) { // Verifies that the pointer targeting Alice's account is valid and safe to access before printing
        display_student_history(*alice); // Prints Alice's detailed transaction list (showing successful checkouts and current states)
    } // Closes the protective safety conditional block

    return 0; // Signals to the runtime environment that the library simulation program executed successfully
} // Closes the definition of the main function block