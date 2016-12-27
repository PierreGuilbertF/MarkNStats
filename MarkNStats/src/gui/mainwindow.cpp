#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this->ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(bOpen()));
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
}

//--------------------------------------
void MainWindow::bSave()
{

}
