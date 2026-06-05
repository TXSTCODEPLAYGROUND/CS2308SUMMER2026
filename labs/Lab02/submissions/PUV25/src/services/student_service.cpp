#include "services/student_service.h"

#include <iostream>

// implement this file
void add_student(Students& students, const std::string& student_id, const std::string& student_name)
{
    Student student;
    student.student_id = student_id; // added a student after creating a 'class'
    student.student_name = student_name;

    students.items.push_back(student); // The pushback sends the information back to the items 'class' in the student struct?
};

Student* find_student_by_id(Students& students, const std::string& student_id)
{
    for(int i = 0; i < students.items.size(); i++)
    {
        if (students.items[i].student_id== student_id)
        {
            return &students.items[i];
        }
    }
    return nullptr;
};
