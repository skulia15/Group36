#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include "utilities/utils.h"
#include "string"
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

        ui->table_showAllScientists->setRowCount(scientists.size());
        ui->table_showAllScientists->setColumnCount(5);


             for(unsigned int row=0;row<scientists.size();row++){

                 Scientist currentScientists = scientists.at(row);
                 QTableWidgetItem* newItem = new QTableWidgetItem();
                newItem->setText(QString::fromStdString(currentScientists.getName()));

                 ui->table_showAllScientists->setItem(row,1,newItem);


             }
}


void MainWindow::on_button_display_scientists_clicked()
{
    displayAllScientists();//Sverrir, Calls display.
    qDebug() << "Date:" << QDate::currentDate(); //Sverrir, Confirmation of button pusshed works
}
