#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H

#include <string>

#include "models/student.h"

void add_student(Students& students, const std::string& student_id, const std::string& student_name);
Student* find_student_by_id(Students& students, const std::string& student_id);
void display_students(const Students& students);
void display_student_history(const Student& student);
void display_active_borrows(const Student& student);
void display_overdue_borrows(const Student& student);

#endif
