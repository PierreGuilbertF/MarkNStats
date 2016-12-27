#include "classroom.hpp"

//--------------------------------------
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
    this->ComputeVariousMean();
}

//--------------------------------------
void ClassRoom::ComputeMeanAge()
{
    this->meanAge = 0;
    for(unsigned int k = 0; k < this->numberOfStudent; ++k)
    {
        this->meanAge = this->meanAge + this->students[k].age;
    }
    this->meanAge = this->meanAge / this->numberOfStudent;
}

//--------------------------------------
void ClassRoom::ComputeMeanGrade()
{

}

//--------------------------------------
void ClassRoom::ComputeMeanBehavior()
{

}

//--------------------------------------
void ClassRoom::ComputeVariousMean()
{
    this->ComputeMeanAge();
    this->ComputeMeanGrade();
    this->ComputeMeanBehavior();
}
