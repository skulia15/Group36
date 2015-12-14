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

    void on_button_scientists_to_table_clicked();
<<<<<<< HEAD

    void on_Input_Filter_Scientists_textChanged(const QString &arg1);
=======
>>>>>>> 57083271d1868766dc427e16d474e269a1c3c9cf

private:
    Ui::MainWindow *ui;
    ScientistService sciServ;//Sverrir, To be able to call class from mainWindow.cpp.
    void displayAllScientists();//Sverrir, Get all Scientists from sqlite to vector, will call on display Scientists.
    void displayScientists(std::vector<Scientist> scientists);//Sverrir, Display all Scientists from vector.
};

#endif // MAINWINDOW_H
