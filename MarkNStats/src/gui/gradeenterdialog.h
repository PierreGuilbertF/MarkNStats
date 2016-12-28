#ifndef GRADEENTERDIALOG_H
#define GRADEENTERDIALOG_H

#ifndef WRONG_VALUE
#define WRONG_VALUE -128
#endif

#include <QDialog>
#include <QtWidgets>
#include "../structure/classroom.hpp"

namespace Ui {
class GradeEnterDialog;
}

class GradeEnterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GradeEnterDialog(QWidget *parent = 0);
    ~GradeEnterDialog();

    void SetUpForm(const ClassRoom classRoom);

    std::vector<QLabel*> names;
    std::vector<QLineEdit*> grades;
    std::vector<float> gradesEnter;

private:
    Ui::GradeEnterDialog *ui;

public slots:
    void accept();
};

#endif // GRADEENTERDIALOG_H
