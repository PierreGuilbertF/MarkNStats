#include <fstream>
#include "Eigen\Core"
#include "DataReader.h"
#include "ClasseScolaire.h"
#include "Menu.h"

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
};

ClassRoom::ClassRoom(std::string fileName)
{
	std::ifstream inputFile;
	inputFile.open(fileName);

	// If the file is not reachable
	if (!inputFile.is_open())
		return;

	std::string line;

	// First line contains the information pattern
	std::getline(inputFile, line);
	{
		std::stringstream lineStream(line);
		std::string cell;
		while (std::getline(lineStream, cell, ','))
		{
			this->informationPattern.push_back(cell);
		}
	}

	std::string firstName = "FirstName";
	std::string name = "Name";
	std::string age = "Age";

	while (std::getline(inputFile,line))
	{
		std::stringstream lineStream(line);
		std::string cell;
		
		Student currentStudent;
		unsigned int count = 0;
		// This checks for a trailing comma with no data after it.
		while (std::getline(lineStream, cell, ','))
		{
			// Check the kind of input information
			if (firstName.compare(this->informationPattern[count]) == 0)
				currentStudent.firstName = cell;
			else if (name.compare(this->informationPattern[count]) == 0)
				currentStudent.name = cell;
			else if (age.compare(this->informationPattern[count]) == 0)
			{
				currentStudent.age = std::atof(cell.c_str());
			}
			count++;
		}
		this->students.push_back(currentStudent);
	}

	this->numberOfStudent = this->students.size();
}