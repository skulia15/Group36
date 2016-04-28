#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "mainwindow.h"
#include "addscientistdialog.h"

namespace Ui {
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerDialog(QWidget *parent = 0);
    ~AddComputerDialog();

private slots:
    void on_button_add_computer_box_clicked();

private:
    Ui::AddComputerDialog *ui;
    ComputerService computerService;
};

#endif // ADDCOMPUTERDIALOG_H
