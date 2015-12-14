#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include "utilities/utils.h"
#include "services/scientistservice.h"
#include "string"
#include <iostream>
#include <iomanip>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ScientistService scientistService;

    ui->Input_Scientist_Name->text();
    ui->input_sex->text();
    ui->input_year_of_birth->text();
    ui->input_year_of_death->text();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()//Sverrir, Sets all scientists to vector and calls display.
{
    ScientistService scientistService;
    vector<Scientist>scientists = scientistService.getAllScientists("name",true);

    displayScientists(scientists);
}

void MainWindow::displayScientists(std::vector<Scientist> scientists)//Sverrir, clears display list and then shows scientists.at(i).
{

        //ui->table_showAllScientists->clear();
        ui->table_showAllScientists->setRowCount(scientists.size());
        ui->table_showAllScientists->setColumnCount(5);

             for(unsigned int row = 0; row < scientists.size(); row++)
             {
                Scientist currentScientists = scientists.at(row);

                QTableWidgetItem* newItem = new QTableWidgetItem();
                newItem->setText(QString::number(currentScientists.getId()));
                ui->table_showAllScientists->setItem(row,0,newItem);

                QTableWidgetItem* newItem1 = new QTableWidgetItem();
                newItem1->setText(QString::fromStdString(currentScientists.getName()));
                ui->table_showAllScientists->setItem(row,1,newItem1);

                //Tekst ekki að breyta Enum í int.
                //þarf að nota =static_cast<int>
                QTableWidgetItem* newItem2 = new QTableWidgetItem();
                newItem2->setText(QString::number(currentScientists.getSex()));
                ui->table_showAllScientists->setItem(row,2,newItem2);

                QTableWidgetItem* newItem3 = new QTableWidgetItem();
                newItem3->setText(QString::number(currentScientists.getYearBorn()));
                ui->table_showAllScientists->setItem(row,3,newItem3);

                QTableWidgetItem* newItem4 = new QTableWidgetItem();
                newItem4->setText(QString::number(currentScientists.getYearDied()));
                ui->table_showAllScientists->setItem(row,4,newItem4);


                //courtsey of https://forum.qt.io/topic/27584/fill-a-qtablewidget/10
              }
}





void MainWindow::on_button_scientists_to_table_clicked()
{
    ScientistService scientistService;

    QString name = ui->Input_Scientist_Name->text();
    QString sex = ui->input_sex->text();
    QString YoB = ui->input_year_of_birth->text();
    QString YoD = ui->input_year_of_death->text();

    if (name.isEmpty()){
        //error message
        return;
    }


    bool success = scientistService.addScientist(Scientist(name.toStdString(), utils::stringToSex(sex.toStdString()), YoB.toInt(), YoD.toInt())); //, sex.toStdString(), YoB.toInt(), YoD.toInt());

    if (success){
        displayAllScientists();
        ui->Input_Scientist_Name->setText("");
        ui->input_sex->setText("");
        ui->input_year_of_birth->setText("");
        ui->input_year_of_death->setText("");
    }
    else{
        //error
       qDebug() << QDate::currentDate();
    }
}
