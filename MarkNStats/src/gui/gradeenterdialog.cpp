#include "gradeenterdialog.h"
#include "ui_gradeenterdialog.h"

GradeEnterDialog::GradeEnterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GradeEnterDialog)
{
    ui->setupUi(this);
}

//--------------------------------------
void GradeEnterDialog::SetUpForm(const ClassRoom classRoom)
{
    //Initialize the size of the vectors
    this->names.resize(classRoom.numberOfStudent);
    this->grades.resize(classRoom.numberOfStudent);
    //instanciate the QWidgets pointers
    for(size_t k=0; k<classRoom.numberOfStudent;++k)
    {
        //TODO : make it with sstream
        QString extension(" : ");
        QString space(" ");
        QString firstName = QString::fromUtf8(classRoom.students[k].firstName.c_str());
        QString name = QString::fromUtf8(classRoom.students[k].name.c_str());
        QString str = firstName + space + name + extension;
        this->names[k] = new QLabel(str);
        this->grades[k] = new QLineEdit();
    }
    //Add the widget to the layout
    for(size_t k=0; k<this->grades.size();++k)
    {
        this->ui->formLayout->insertRow(k,this->names[k],this->grades[k]);
    }
}

//--------------------------------------
GradeEnterDialog::~GradeEnterDialog()
{
    delete ui;
}

//--------------------------------------
void GradeEnterDialog::accept()
{
    //Get the values in a array
    bool ok[1];
    for(size_t k =0;k<this->grades.size(); ++k)
    {
        QString gradeQStr = this->grades[k]->text();
        float grade = gradeQStr.toFloat(ok);
        //if an entered value is not a float or is empty -> put the predefine value
        if(ok[0] == false)
            grade = WRONG_VALUE;
        this->gradesEnter.push_back(grade);
    }
    //Close the window
    QDialog::accept();
}
