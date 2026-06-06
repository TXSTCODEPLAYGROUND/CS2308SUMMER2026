#ifndef BORROW_RECORD_H
#define BORROW_RECORD_H

#include <string>

struct BorrowRecord {
    std::string isbn;
    std::string book_title;
    std::string rent_date;
    std::string due_date;
    std::string return_date;
    bool is_completed;
    bool is_overdue;
};

#endif
