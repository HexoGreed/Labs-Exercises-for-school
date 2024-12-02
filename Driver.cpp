#include <iostream>
#include <vector>
#include "course.h"
#include "Student.h"
using namespace std;

int main() {
	
/*
Check things:

To be Done:
Student() 
Course()
operator=
operator<<
operator<<

Student functions:

Done:
Student(string, string)
gpa_calc()
gpa_override(double)
setAddress(string)
addCourse(Course)
print()
Student(Student&)
print()
Course(string, int)
changeGrade(char)
getGrade()
getHours()

*/


	Course blankCourse; 
	Student blankStudent; 

	std::cout << "Blank Course:\n";
	blankCourse.print();
	std::cout << "\nBlank Student:\n";
	blankStudent.print();

	
	

	Student student1("Alice Johnson", "123 Main St");


	//init the courses
	

	Course math("Mathematics", 3);
	Course history("History", 4);
	Course physics("Physics", 3);

	//set the grades
	math.changeGrade('A');
	history.changeGrade('B');
	physics.changeGrade('A');


	//adding the courses to student1
	student1.addCourse(math);
	student1.addCourse(history);
	student1.addCourse(physics);


	Student student2(student1);
	student2.setAddress("1234 driver street");
	student2.setName("Jhonny Joestar");

	Student NonDerivedStudent("Joe Biden", "1234asdasdk street");


	Student assignedStudent;
	assignedStudent = student1; // Test the assignment operator
	std::cout << "Assigned Student:\n" << assignedStudent << std::endl;


	math.changeGrade('C');
	math.getGrade();
	math.print();
	history.changeGrade('C');
	math.getHours();

	NonDerivedStudent.addCourse(physics);
	NonDerivedStudent.addCourse(math);
	NonDerivedStudent.addCourse(history);

	student1.gpa_calc();
	student2.gpa_calc();
	NonDerivedStudent.gpa_calc();
	cout << NonDerivedStudent << endl;

	NonDerivedStudent.gpa_override(6.2);

	std::cout << "Output for students" << "\n\n\n//////////////////\n";
	cout << student1 << "\n";
	std::cout << student2 << endl;
	cout << NonDerivedStudent << endl;

	return 0;
}