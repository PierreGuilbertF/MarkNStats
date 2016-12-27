#ifndef GRADEENTERDIALOG_H
#define GRADEENTERDIALOG_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class GradeEnterDialog;
}

class GradeEnterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GradeEnterDialog(QWidget *parent = 0);
    ~GradeEnterDialog();

    void SetUpForm();

    std::vector<QLabel*> names;
    std::vector<QLineEdit*> grades;

private:
    Ui::GradeEnterDialog *ui;
};

#endif // GRADEENTERDIALOG_H
