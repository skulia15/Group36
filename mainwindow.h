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
    void on_button_display_scientists_clicked();

private:
    Ui::MainWindow *ui;
    ScientistService sciServ; //To be able to call class from mainWindow.cpp.
    void displayAllScientists(); //Get all Scientists from sqlite to vector, will call on display Scientists.
    void displayScientists(std::vector<Scientist> scientists); //Display all Scientists from vector.
};

#endif // MAINWINDOW_H
