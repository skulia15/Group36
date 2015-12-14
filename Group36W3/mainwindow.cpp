#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include "utilities/utils.h"
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "string"
#include "addscientistdialog.h"
#include <iostream>
#include <iomanip>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ComputerService computerService;
    ScientistService scientistService;
    displayAllScientists();
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


void MainWindow::displayScientists(std::vector<Scientist> scientists)//Sverrir, shows scientists.at(i).
{
    //ui->table_showAllScientists->clear();

    ui->table_showAllScientists->setRowCount(scientists.size());
    ui->table_showAllScientists->setColumnCount(5);
    QStringList header;
    header<<"ID"<<"Name"<<"Sex"<<"YoB"<<"YoD";
    ui->table_showAllScientists->setHorizontalHeaderLabels(header);
     ui->table_showAllScientists->hideColumn(0);

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
    currentScientists = scientists; //Sverrir, Hvað gerir þetta ?
}

void MainWindow::displayAllComputers()//Sverrir, Sets all scientists to vector and calls display.
{
    ComputerService cpuService;

    vector<Computer>computer = cpuService.getAllComputers("name",true);
qDebug()<<computer.size();
    displayComputers(computer);

}

void MainWindow::displayComputers(std::vector<Computer> computer)//Sverrir,  shows computer.at(i).
{


    ui->table_showAllScientists->setRowCount(computer.size());
    ui->table_showAllScientists->setColumnCount(5);
    QStringList header;
    header<<"ID"<<"Name"<<"Type"<<"Year Built"<<"Was built";
    ui->table_showAllScientists->setHorizontalHeaderLabels(header);
    ui->table_showAllScientists->hideColumn(0);


    for(unsigned int row = 0; row < computer.size(); row++)
         {
            Computer currentComputer = computer.at(row);

            QTableWidgetItem* newItem = new QTableWidgetItem();
            newItem->setText(QString::number(currentComputer.getId()));
            ui->table_showAllScientists->setItem(row,0,newItem);

            QTableWidgetItem* newItem1 = new QTableWidgetItem();
            newItem1->setText(QString::fromStdString(currentComputer.getName()));
            ui->table_showAllScientists->setItem(row,1,newItem1);

            QTableWidgetItem* newItem2 = new QTableWidgetItem();
            newItem2->setText(QString::number(currentComputer.getType()));
            ui->table_showAllScientists->setItem(row,2,newItem2);

            QTableWidgetItem* newItem3 = new QTableWidgetItem();
            newItem3->setText(QString::number(currentComputer.getYearBuilt()));
            ui->table_showAllScientists->setItem(row,3,newItem3);

            QTableWidgetItem* newItem4 = new QTableWidgetItem();
            newItem4->setText(QString::number(currentComputer.wasBuilt()));
            if(newItem4 == 0)
            {ui->table_showAllScientists->setItem(row,4,new QTableWidgetItem('Yes'));}
            else{ui->table_showAllScientists->setItem(row,4,new QTableWidgetItem("NO"));}

            //courtsey of https://forum.qt.io/topic/27584/fill-a-qtablewidget/10
          }
        currentComputer = computer; // Hvað gerir þetta ?
}


void MainWindow::on_Input_Filter_Scientists_textChanged(const QString &arg1)
{
    ScientistService scientistService;

    string inputFilter = ui->Input_Filter_Scientists->text().toStdString();

    vector<Scientist>scientists = scientistService.searchForScientists(inputFilter);
    displayScientists(scientists);
}

void MainWindow::on_table_showAllScientists_clicked(const QModelIndex &index)
{
    ui->button_delete_scientist->setEnabled(true);
}

void MainWindow::on_button_delete_scientist_clicked()
{
    ScientistService scientistService;

    int indexOfSelected = ui->table_showAllScientists->currentIndex().row();
    Scientist currentlySelectedScientist = currentScientists.at(indexOfSelected);

    bool success = scientistService.removeScientist(currentlySelectedScientist);

    if (success)
    {
       ui->Input_Filter_Scientists->setText("");
       displayAllScientists();
    }
    else
    {
        //error message
    }
}


void MainWindow::on_button_add_scientist_clicked()
{
    AddScientistDialog AddScientistDialog;
    int addScientistsReturnValue = AddScientistDialog.exec();
    ScientistService scientistService;

    if (addScientistsReturnValue == 0)
    {
        ui->Input_Filter_Scientists->setText("");
        displayAllScientists();

        ui->statusBar->showMessage("Successfully added scientist", 2500);
    }
    else
    {
        // there was an error
    }
}



void MainWindow::on_Dropdown_Menu_currentIndexChanged(const QString &arg1)
{
    QString index = ui->Dropdown_Menu->currentText();
    if(index=="Scientists")
    {
        displayAllScientists();
    }
    if(index=="Computers")
    {
        displayAllComputers();
    }
    if(index=="Relations")
    {
        //display Relations.
    }
    else
    {
        //display warning.
    }
}
