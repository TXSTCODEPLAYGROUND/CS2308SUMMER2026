#ifndef RENTAL_SERVICE_H
#define RENTAL_SERVICE_H

#include <string>

#include "models/book.h"
#include "models/student.h"

bool rent_book(Books& books, Students& students, const std::string& student_id,
               const std::string& isbn, const std::string& rent_date, const std::string& due_date);
bool return_book(Books& books, Students& students, const std::string& student_id,
                 const std::string& isbn, const std::string& return_date);

#endif
