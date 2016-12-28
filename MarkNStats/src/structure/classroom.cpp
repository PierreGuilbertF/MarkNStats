#include "classroom.hpp"

//--------------------------------------
void Student::ComputeMeanGrade()
{
    int count = 0;
    this->meanGrade = 0;
    for(size_t k=0;k<this->marks.size();++k)
    {
        if(this->marks[k] != WRONG_VALUE)
        {
            this->meanGrade = this->meanGrade + this->marks[k];
            count++;
        }
    }
    this->meanGrade = this->meanGrade / count;
    this->numberOfMarks = count;

    return;
}

//--------------------------------------
ClassRoom::ClassRoom()
{

}

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
    std::string behavior = "Behavior";
    std::string grade = "Grade";

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
            else if (behavior.compare(this->informationPattern[count]) == 0)
            {
                currentStudent.behavior = std::atof(cell.c_str());
            }
            else if (grade.compare(this->informationPattern[count]) == 0)
            {
                currentStudent.marks.push_back(std::atof(cell.c_str()));
            }
            count++;
        }
        currentStudent.ComputeMeanGrade();
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
    this->meanGrade = 0;
    for(size_t k=0; k<this->numberOfStudent;++k)
    {
        this->meanGrade = this->meanGrade + this->students[k].meanGrade;
    }
    this->meanGrade = this->meanGrade / this->numberOfStudent;
}

//--------------------------------------
void ClassRoom::ComputeHardMeanGrade()
{
    int count = 0;
    this->hardMeanGrade = 0;
    for(size_t i=0; i<this->numberOfStudent;++i)
    {
        for(size_t j=0; j<this->students[i].marks.size();++j)
        {
            if(this->students[i].marks[j] != WRONG_VALUE)
            {
                this->hardMeanGrade = this->hardMeanGrade + this->students[i].marks[j];
                count++;
            }
        }
    }
    this->hardMeanGrade = this->hardMeanGrade / (count);
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
    this->ComputeHardMeanGrade();
}

//--------------------------------------
void ClassRoom::SaveInfo(std::string fileName)
{
    std::ofstream outputFile;
    outputFile.open(fileName);

    // If the file is not open
    if(!outputFile.is_open())
        return;

    // Write the template information
    outputFile << "FirstName,Name,Age,Behavior,";
    for(size_t k=0;k<this->students[0].marks.size();++k)
    {
        outputFile << "Grade,";
    }
    outputFile << std::endl;
    for(unsigned int k=0; k<this->numberOfStudent; ++k)
    {
        outputFile << this->students[k].firstName << ",";
        outputFile << this->students[k].name << ",";
        outputFile << this->students[k].age << ",";
        outputFile << this->students[k].behavior << ",";
        for(unsigned int i=0; i<this->students[k].marks.size();++i)
        {
            outputFile << this->students[k].marks[i] << ",";
        }
        outputFile << std::endl;
    }
}
