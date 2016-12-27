#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class Student
{
public:
	// first name of the student
	std::string firstName;
	// Name of the student
	std::string name;
	// Numbver of marks recorded for this student
	unsigned int numberOfMarks;
	// Marks obtained by the student
	std::vector<float> marks;
	// Age of the student
	float age;
	// Behavior of the student
	float behavior;
private:
};

class ClassRoom
{
public:
	ClassRoom(std::string fileName);

	//information available in the class
	std::vector<std::string> informationPattern;
	// List of the students in the classroom
	std::vector<Student> students;
	// Number of student in the classroom
	unsigned int numberOfStudent;
    //Average age of the class
    float meanAge;
    //AverageGrade of the class
    float meanGrade;
    //Average behavior of the class
    float meanBehavior;

protected:
    void ComputeMeanAge();
    void ComputeMeanGrade();
    void ComputeMeanBehavior();
    void ComputeVariousMean();
};

#endif
