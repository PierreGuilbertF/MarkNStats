#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize paraleters
    this->internal.isAFileLoaded = false;
    this->internal.classRooms.resize(1);
    //Initialized the dialogBox
    this->internal.gradeEnterdialog = new GradeEnterDialog(this);
    this->internal.gradeEnterdialog->setWindowTitle("Grade enter");

    connect(this->ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(bOpen()));
    connect(this->ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(bSave()));
    connect(this->ui->actionEnterGrade,SIGNAL(triggered(bool)),this,SLOT(bEnterGrade()));
    connect(this->internal.gradeEnterdialog,SIGNAL(accepted()),this,SLOT(bGradeEntered()));
}

//--------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}

//--------------------------------------
void MainWindow::bOpen()
{
    QString filter = "CSV (*.csv)";
    QString fileName = QFileDialog::getOpenFileName(this,"Select a file...", QDir::homePath(),filter);
    ClassRoom c(fileName.toStdString());
    this->internal.classRooms[0] = c;

    if(c.students.size()>0)
        this->internal.isAFileLoaded = true;
    else
        return;

    this->ui->fileNameLineEdit->setText(fileName);
    this->ui->averageAgeLineEdit->setText(QString::number(this->internal.classRooms[0].meanAge));
    this->ui->numberOfStudentLineEdit->setText(QString::number(this->internal.classRooms[0].numberOfStudent));
    this->ui->averageGradeLineEdit->setText(QString::number(this->internal.classRooms[0].hardMeanGrade));
    this->ui->meanGradeLineEdit->setText(QString::number(this->internal.classRooms[0].meanGrade));

    //this->ui->displayGroupBoxLayout->addWidget()
    for(size_t k=0;k<this->internal.classRooms[0].numberOfStudent;++k)
    {
        //firstName
        QLabel* temp = new QLabel(this->internal.classRooms[0].students[k].firstName.c_str());
        this->ui->displayGroupBoxLayout->addWidget(temp,k,0,1,1);
        //Name
        temp = new QLabel(this->internal.classRooms[0].students[k].name.c_str());
        this->ui->displayGroupBoxLayout->addWidget(temp,k,1,1,1);
        //Age
        temp = new QLabel(QString::number(this->internal.classRooms[0].students[k].age));
        this->ui->displayGroupBoxLayout->addWidget(temp,k,2,1,1);
        //Behavior
        temp = new QLabel(QString::number(this->internal.classRooms[0].students[k].behavior));
        this->ui->displayGroupBoxLayout->addWidget(temp,k,3,1,1);
        //rades
        for(size_t i=0;i<this->internal.classRooms[0].students[k].marks.size();++i)
        {
            float mark = this->internal.classRooms[0].students[k].marks[i];
            if(mark != WRONG_VALUE)
            {
                temp = new QLabel(QString::number(mark));
                this->ui->displayGroupBoxLayout->addWidget(temp,k,i+3,1,1);
            }
        }
    }
}

//--------------------------------------
void MainWindow::bSave()
{
    if(!this->internal.isAFileLoaded)
        return;

    QString filter = "CSV (*.csv)";
    QString fileName = QFileDialog::getSaveFileName(this, "Save File",QDir::homePath(),filter);
    this->internal.classRooms[0].SaveInfo(fileName.toStdString());
}

//--------------------------------------
void MainWindow::bEnterGrade()
{
    if(!this->internal.isAFileLoaded)
        return;

    // We need at least one classRoom
    if(this->internal.classRooms.size() < 1)
        return;
    // setup the dialog box
    this->internal.gradeEnterdialog->SetUpForm(this->internal.classRooms[0]);
    this->internal.gradeEnterdialog->show();
}

//--------------------------------------
void MainWindow::bGradeEntered()
{
    if(!this->internal.isAFileLoaded)
        return;

    std::cout << "Dialog accepted" << std::endl;
    for(size_t k=0; k<this->internal.classRooms[0].numberOfStudent; ++k)
    {
        this->internal.classRooms[0].students[k].marks.push_back(this->internal.gradeEnterdialog->gradesEnter[k]);
    }
}
