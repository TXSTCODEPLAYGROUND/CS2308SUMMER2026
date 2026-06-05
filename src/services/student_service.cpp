#include "services/student_service.h"

#include <iostream>

Student* find_student_by_id(Students& students, const std::string& student_id) {
    for (auto& student : students.items) {
        if (student.student_id == student_id) {
            return &student;
        }
    }
    return nullptr;
}

void add_student(Students& students, const std::string& student_id, const std::string& student_name) {
    if (find_student_by_id(students, student_id) != nullptr) {
        std::cout << "Student with ID " << student_id << " already exists. Skipping add.\n";
        return;
    }

    Student student;
    student.student_id = student_id;
    student.student_name = student_name;
    students.items.push_back(student);
    std::cout << "Added student: " << student_name << " (" << student_id << ")\n";
}

void display_students(const Students& students) {
    std::cout << "Students:\n";
    for (const auto& student : students.items) {
        std::cout << student.student_id << "\t" << student.student_name << "\n";
    }
}

void display_active_borrows(const Student& student) {
    std::cout << "Active borrows for " << student.student_name << " (" << student.student_id << "):\n";
    bool found = false;
    for (const auto& record : student.borrow_history) {
        if (!record.is_completed) {
            found = true;
            std::cout << record.isbn << "\t" << record.book_title << "\t"
                      << record.rent_date << "\t" << record.due_date << "\t"
                      << (record.is_overdue ? "OVERDUE" : "On time") << "\n";
        }
    }
    if (!found) {
        std::cout << "None\n";
    }
}

void display_overdue_borrows(const Student& student) {
    std::cout << "Overdue borrows for " << student.student_name << " (" << student.student_id << "):\n";
    bool found = false;
    for (const auto& record : student.borrow_history) {
        if (!record.is_completed && record.is_overdue) {
            found = true;
            std::cout << record.isbn << "\t" << record.book_title << "\t"
                      << record.rent_date << "\t" << record.due_date << "\n";
        }
    }
    if (!found) {
        std::cout << "None\n";
    }
}

void display_student_history(const Student& student) {
    std::cout << "Borrow history for " << student.student_name << " (" << student.student_id << "):\n";
    if (student.borrow_history.empty()) {
        std::cout << "No borrow records.\n";
        return;
    }

    for (const auto& record : student.borrow_history) {
        std::cout << record.isbn << "\t" << record.book_title << "\t"
                  << record.rent_date << "\t" << record.due_date << "\t";

        if (record.is_completed) {
            std::cout << record.return_date << "\tCompleted";
        } else {
            std::cout << "--\tActive";
        }

        if (record.is_overdue) {
            std::cout << "\tOverdue";
        }
        std::cout << "\n";
    }
}

