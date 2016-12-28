#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    this->internal.classRooms.push_back(c);

    this->ui->fileNameLineEdit->setText(fileName);
    this->ui->averageAgeLineEdit->setText(QString::number(this->internal.classRooms[0].meanAge));
    this->ui->numberOfStudentLineEdit->setText(QString::number(this->internal.classRooms[0].numberOfStudent));
    this->ui->averageGradeLineEdit->setText(QString::number(this->internal.classRooms[0].meanGrade));
}

//--------------------------------------
void MainWindow::bSave()
{
    QString filter = "CSV (*.csv)";
    QString fileName = QFileDialog::getSaveFileName(this, "Save File",QDir::homePath(),filter);

    if(this->internal.classRooms.size()>0)
        this->internal.classRooms[0].SaveInfo(fileName.toStdString());
}

//--------------------------------------
void MainWindow::bEnterGrade()
{
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
    std::cout << "Dialog accepted" << std::endl;
    for(size_t k=0; k<this->internal.classRooms[0].numberOfStudent; ++k)
    {
        this->internal.classRooms[0].students[k].marks.push_back(this->internal.gradeEnterdialog->gradesEnter[k]);
    }
}
