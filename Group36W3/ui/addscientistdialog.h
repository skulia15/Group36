#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include <QDialog>

namespace Ui {
class AddScientistDialog;
}

class AddScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistDialog(QWidget *parent = 0);
    ~AddScientistDialog();

private slots:
   void on_button_add_Scientist_box_clicked();

private:
    Ui::AddScientistDialog *ui;
};

#endif // ADDSCIENTISTDIALOG_H
