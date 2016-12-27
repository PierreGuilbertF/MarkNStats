#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this->ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(bOpen()));
    connect(this->ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(bSave()));
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
    std::cout << this->internal.classRooms[0].meanAge << std::endl;
}

//--------------------------------------
void MainWindow::bSave()
{
    QString filter = "CSV (*.csv)";
    QString fileName = QFileDialog::getSaveFileName(this, "Save File",QDir::homePath(),filter);

    if(this->internal.classRooms.size()>0)
        this->internal.classRooms[0].SaveInfo(fileName.toStdString());
}
