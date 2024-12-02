#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>
#include "Course.h"



class Student {
private:
    std::string name;
    std::string address;
    double gpa = 0.0;
    std::vector<Course> takenCourses;

public:


    Student() {
        name = "";
        address = "";
        gpa = 0.0;
        takenCourses.clear();
    }

    

    // Copy constructor
    Student(const std::string& newName, const std::string& newAddress) {
        name = newName;
        address = newAddress;
        gpa = 0.0; // Default GPA
        takenCourses.clear(); // Initialize with no courses
    }

    

    //makes it so student can derive off other student
    Student& operator=(const Student& other) {
        if (this != &other) {
            name = other.name;
            address = other.address;
            gpa = other.gpa;
            takenCourses = other.takenCourses;
        }
        return *this;
    }


    // Member function to calculate GPA
    void gpa_calc() {
        if (takenCourses.empty()) {
            gpa = 0.0;
            return;
        }

        double totalPoints = 0.0;
        int totalCredits = 0;

        for (const Course& course : takenCourses) {
            int credits = course.getHours();
            char grade = course.getGrade();

            // Convert grades to GPA points
            double gradePoints = 0.0;
            switch (grade) {
            case 'A': gradePoints = 4.0; break;
            case 'B': gradePoints = 3.0; break;
            case 'C': gradePoints = 2.0; break;
            case 'D': gradePoints = 1.0; break;
            case 'F': gradePoints = 0.0; break;
            default: gradePoints = 0.0; break; // Handle ungraded courses
            }

            totalPoints += gradePoints * credits;
            totalCredits += credits;
        }

        gpa = (totalCredits > 0) ? totalPoints / totalCredits : 0.0;
        //ternarary stament, if the first thing is false it automatically goes to the second one.
        //its an if statmnet for lazy peple
    }

    void gpa_override(double newGPA) {
        gpa = newGPA;
    }

    //AAAA
    void setAddress(const std::string& newAddress) {
        address = newAddress;
    }
    void setName(const std::string& newName) {
        name = newName;

    }
    //I HATE DOING REFRENCESSS why are they always so confusing :sob:
    void addCourse(const Course& course) {
        takenCourses.push_back(course);
    }

    void print() const {
        std::cout << "Name: " << name << ", Address: " << address << ", GPA: " << gpa << std::endl;
        std::cout << "Courses:" << std::endl;
        for (const Course& course : takenCourses) {
            course.print();
        }
    }

    // Overload << operator for student output
    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        out << "Name: " << student.name << ", Address: " << student.address << ", GPA: " << student.gpa << std::endl;
        out << "Courses:" << std::endl;
        for (const Course& course : student.takenCourses) {
            out << course << std::endl;
        }
        return out;
    }
};

#endif // STUDENT_H
