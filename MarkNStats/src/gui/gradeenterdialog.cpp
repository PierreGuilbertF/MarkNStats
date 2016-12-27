#include "gradeenterdialog.h"
#include "ui_gradeenterdialog.h"

GradeEnterDialog::GradeEnterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GradeEnterDialog)
{
    ui->setupUi(this);
}

//--------------------------------------
void GradeEnterDialog::SetUpForm()
{
    for(size_t k=0; k<this->grades.size();++k)
    {
        this->ui->formLayout->addWidget(this->names[k]);
    }
}

//--------------------------------------
GradeEnterDialog::~GradeEnterDialog()
{
    delete ui;
}
