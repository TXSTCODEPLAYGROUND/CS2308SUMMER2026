#include "services/rental_service.h"

#include <iostream>

#include "services/book_service.h"
#include "services/student_service.h"

bool rent_book(Books& books, Students& students, const std::string& student_id,
               const std::string& isbn, const std::string& rent_date, const std::string& due_date) {
    Student* student = find_student_by_id(students, student_id);
    if (student == nullptr) {
        std::cout << "Student " << student_id << " not found. Cannot rent book.\n";
        return false;
    }

    Book* book = find_book_by_isbn(books, isbn);
    if (book == nullptr) {
        std::cout << "Book " << isbn << " not found. Cannot rent book.\n";
        return false;
    }

    if (book->available_count <= 0) {
        std::cout << "Book " << book->title << " is not available for rent.\n";
        return false;
    }

    for (const auto& record : student->borrow_history) {
        if (!record.is_completed && record.isbn == isbn) {
            std::cout << student->student_name << " already has an active borrow for " << book->title << ".\n";
            return false;
        }
    }

    book->available_count -= 1;
    book->rented_count += 1;

    BorrowRecord record;
    record.isbn = isbn;
    record.book_title = book->title;
    record.rent_date = rent_date;
    record.due_date = due_date;
    record.return_date = "";
    record.is_completed = false;
    record.is_overdue = false;
    student->borrow_history.push_back(record);

    std::cout << "Rented book " << book->title << " to " << student->student_name << " on " << rent_date << ".\n";
    return true;
}

bool return_book(Books& books, Students& students, const std::string& student_id,
                 const std::string& isbn, const std::string& return_date) {
    Student* student = find_student_by_id(students, student_id);
    if (student == nullptr) {
        std::cout << "Student " << student_id << " not found. Cannot return book.\n";
        return false;
    }

    Book* book = find_book_by_isbn(books, isbn);
    if (book == nullptr) {
        std::cout << "Book " << isbn << " not found. Cannot return book.\n";
        return false;
    }

    for (auto& record : student->borrow_history) {
        if (!record.is_completed && record.isbn == isbn) {
            record.return_date = return_date;
            record.is_completed = true;
            record.is_overdue = (return_date > record.due_date);

            if (book->available_count < book->total_count) {
                book->available_count += 1;
            }
            if (book->rented_count > 0) {
                book->rented_count -= 1;
            }

            std::cout << "Returned book " << book->title << " from " << student->student_name << " on " << return_date << ".\n";
            if (record.is_overdue) {
                std::cout << "Return is overdue. Due was " << record.due_date << ".\n";
            }
            return true;
        }
    }

    std::cout << student->student_name << " does not have an active borrow for book " << isbn << ".\n";
    return false;
}
