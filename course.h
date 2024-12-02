#pragma once
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course {
private:
    std::string courseName;
    int creditHours;
    char grade;

public:
    // Default constructor
    Course() {
        courseName = "";
        creditHours = 0;
        grade = '0';
    }


    // Parameterized constructor
    Course(const std::string& name, int hours) {
        courseName = name;
        creditHours = hours;
        grade = '0'; // Default grade
    }

        

    // Change grade
    void changeGrade(char newGrade) {
        grade = newGrade;
        
    }

    // Get grade
    char getGrade() const {
        return grade;
    }

    // Get credit hours
    int getHours() const {
        return creditHours;
    }

    // Print course details
    void print() const {
        std::cout << "Course Name: " << courseName
            << ", Credit Hours: " << creditHours
            << ", Grade: " << (grade == '\0' ? "Not Assigned" : std::string(1, grade))
            << std::endl;
    }

    // Overload << operator for course output
    friend std::ostream& operator<<(std::ostream& out, const Course& course) {
        out << "Course Name: " << course.courseName
            << ", Credit Hours: " << course.creditHours
            << ", Grade: " << (course.grade == '\0' ? "Not Assigned" : std::string(1, course.grade));
        return out;
    }
};

#endif 