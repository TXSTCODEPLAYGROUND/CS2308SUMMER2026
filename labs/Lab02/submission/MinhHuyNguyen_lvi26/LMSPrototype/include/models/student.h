#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

#include "borrow_record.h"

struct Student {
    std::string student_id;
    std::string student_name;
    std::vector<BorrowRecord> borrow_history;
};

struct Students {
    std::vector<Student> items;
};

#endif
