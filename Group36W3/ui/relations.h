#ifndef RELATIONS_H
#define RELATIONS_H
#include "services/scientistservice.h"
#include "services/linkservice.h"
#include "services/computerservice.h"
#include <QStatusBar>
#include <QDialog>

namespace Ui {
class relations;
}

class relations : public QDialog
{
    Q_OBJECT

public:
    explicit relations(QWidget *parent = 0);
    ~relations();

private slots:
    void on_pushButton_clicked();

private:
    Ui::relations *ui;
    ScientistService sciServ;//Sverrir, To be able to call class from mainWindow.cpp.
    void displayScientistsRelations(std::vector<Scientist> scientists);
    void displayAllScientistsRelations();

    ComputerService computer;
    void displayAllScientists();//Sverrir, Get all Scientists from sqlite to vector, will call on display Scientists.
    void displayScientists(std::vector<Scientist> scientists);
    void displayAllComputersRelations();
    void displayComputersRelations(std::vector<Computer> Computers);
    std::vector <Scientist> currentScientists;
    std::vector <Computer> currentComputers;
};

#endif // RELATIONS_H
