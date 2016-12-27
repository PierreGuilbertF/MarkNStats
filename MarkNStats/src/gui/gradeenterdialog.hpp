#ifndef GRADEENTERDIALOG_HPP
#define GRADEENTERDIALOG_HPP

//standard lib include
#include <iostream>
//Qt include
#include <QMainWindow>
#include <QtWidgets>
//Structure include
#include "src/structure/classroom.hpp"

class GradeEnterDialog : public QDialog
{
    Q_OBJECT
public:
    GradeEnterDialog(QWidget *p=0);
    //virtual ~GradeEnterDialog();

public slots:
    virtual void accept();
};

#endif // GRADEENTERDIALOG_HPP
