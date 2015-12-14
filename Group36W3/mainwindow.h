#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "services/linkservice.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    //void on_button_scientists_to_table_clicked();

    void on_Input_Filter_Scientists_textChanged(const QString &arg1);
    void on_table_showAllScientists_clicked(const QModelIndex &index);

    void on_button_delete_scientist_clicked();

    void on_button_add_scientist_clicked();

private:
    Ui::MainWindow *ui;
    ScientistService sciServ;//Sverrir, To be able to call class from mainWindow.cpp.
    void displayAllScientists();//Sverrir, Get all Scientists from sqlite to vector, will call on display Scientists.
    void displayScientists(std::vector<Scientist> scientists);//Sverrir, Display all Scientists from vector.
    std::vector <Scientist> currentScientists;
};

#endif // MAINWINDOW_H
