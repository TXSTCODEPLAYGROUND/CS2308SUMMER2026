#include "services/rental_service.h"

#include <iostream>

#include "services/book_service.h"
#include "services/student_service.h"

// Complete this file
bool rent_book(Books& books, Students& students, const std::string& student_id,
               const std::string& isbn, const std::string& rent_date, const std::string& due_date) {

    Student* rentStudent = find_student_by_id(students, student_id);
    if (rentStudent == nullptr) return false;

    Book* rentBook = find_book_by_isbn(books, isbn);
    if (rentBook == nullptr) return false;

    if (rentBook->available_count <= 0) return false;

    for (BorrowRecord& record: rentStudent->borrow_history) {
        if (record.isbn == isbn && record.is_completed == false) return false;
    }

    rentBook->available_count--;
    rentBook->rented_count++;
    BorrowRecord record;
    record.isbn = isbn;
    record.book_title = rentBook->title;
    record.rent_date = rent_date;
    record.due_date = due_date;
    record.is_completed = false;
    rentStudent->borrow_history.push_back(record);

    return true;
}
;