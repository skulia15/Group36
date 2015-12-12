#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()//Sverrir, Sets all scientists to vector and calls display.
{
    vector<Scientist>scientists = sciServ.getAllScientists("name",true);

    displayScientists(scientists);
}

void MainWindow::displayScientists(std::vector<Scientist> scientists)//Sverrir, clears display list and then shows scientists.at(i).
{
    ui->list_display_scientists->clear();
    for(unsigned int i=0; i<scientists.size();i++)
    {
        Scientist currentScientists = scientists.at(i);

        ui->list_display_scientists->addItem(QString::fromStdString(currentScientists.getName()));

    }
}


void MainWindow::on_button_display_scientists_clicked()
{
    displayAllScientists();//Sverrir, Calls display.
}
