#include "services/student_service.h"

#include <iostream>

// implement this file
void add_student(Students& students, const std::string& student_id, const std::string& student_name) {
    Student student;
    student.student_id = student_id;
    student.student_name = student_name;
    students.items.push_back(student);
}

Student* find_student_by_id(
    Students& students,
    const std::string& student_id) {

    for (Student& student : students.items) {
        if (student.student_id == student_id) return &student;
    }
    return nullptr;
};

