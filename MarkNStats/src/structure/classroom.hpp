#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP

#ifndef WRONG_VALUE
#define WRONG_VALUE -128
#endif

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
    //Average grade of the student
    float meanGrade;
	// Age of the student
	float age;
	// Behavior of the student
	float behavior;

    void ComputeMeanGrade();
private:
};

class ClassRoom
{
public:
    ClassRoom();
	ClassRoom(std::string fileName);

    //Save the information of the classroom
    void SaveInfo(std::string fileName);

	//information available in the class
	std::vector<std::string> informationPattern;
	// List of the students in the classroom
	std::vector<Student> students;
	// Number of student in the classroom
	unsigned int numberOfStudent;
    //Average age of the class
    float meanAge;
    //Average grade of the students (the mean of all mean)
    float meanGrade;
    //Average grade of the class (the mean of all grades)
    float hardMeanGrade;
    //Average behavior of the class
    float meanBehavior;

protected:
    void ComputeMeanAge();
    void ComputeMeanGrade();
    void ComputeMeanBehavior();
    void ComputeVariousMean();
    void ComputeHardMeanGrade();
};

#endif
