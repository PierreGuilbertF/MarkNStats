#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//standard lib include
#include <iostream>
//Qt include
#include <QMainWindow>
#include <QtWidgets>
//Structure include
#include "src/structure/classroom.hpp"
//Gui include
#include "gradeenterdialog.h"

class MWInternal
{
public:
    std::vector<ClassRoom> classRooms;
    GradeEnterDialog* gradeEnterdialog;
    bool isAFileLoaded;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MWInternal internal;

private:
    Ui::MainWindow *ui;

public slots:
    void bOpen();
    void bSave();
    void bEnterGrade();
    void bGradeEntered();
};

#endif // MAINWINDOW_H
