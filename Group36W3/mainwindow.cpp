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
#include <services/linkservice.h>
#include "addcomputerdialog.h"
#include "relations.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Scientists And Computer Finder 3000");
    setWindowIcon(QIcon("logo.png"));
    QPalette palette;
    ui->statusBar->setPalette(palette);


    ComputerService computerService;
    LinkService links;
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
    header << "ID" << "Name" << "Sex" << "YoB" << "YoD";
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
        newItem2->setText(QString::number(static_cast<int>(currentScientists.getSex())));
        ui->table_showAllScientists->setItem(row,2,newItem2);

        QTableWidgetItem* newItem3 = new QTableWidgetItem();
        newItem3->setText(QString::number(currentScientists.getYearBorn()));
        ui->table_showAllScientists->setItem(row,3,newItem3);

        QTableWidgetItem* newItem4 = new QTableWidgetItem();
        newItem4->setText(QString::number(currentScientists.getYearDied()));
        ui->table_showAllScientists->setItem(row,4,newItem4);


        //courtsey of https://forum.qt.io/topic/27584/fill-a-qtablewidget/10
      }
    currentScientists = scientists; //For indexing purposes
}

void MainWindow::displayAllComputers() //Sverrir, Sets all scientists to vector and calls display.
{
    ComputerService cpuService;

    vector<Computer>computer = cpuService.getAllComputers("name",true);
qDebug()<<computer.size();
    displayComputers(computer);

}


void MainWindow::displayComputers(std::vector<Computer> computers)
{
    ui->table_showAllScientists->setRowCount(computers.size());
    ui->table_showAllScientists->setColumnCount(5);
    QStringList header;
    header << "ID" << "Name" << "Year Built" << "Type" << "Was it built";
    ui->table_showAllScientists->setHorizontalHeaderLabels(header);
     ui->table_showAllScientists->hideColumn(0);

     for(unsigned int row = 0; row < computers.size(); row++)
     {
        Computer currentComputer = computers.at(row);

        QTableWidgetItem* newItem = new QTableWidgetItem();
        newItem->setText(QString::number(currentComputer.getId()));
        ui->table_showAllScientists->setItem(row,0,newItem);

        QTableWidgetItem* newItem1 = new QTableWidgetItem();
        newItem1->setText(QString::fromStdString(currentComputer.getName()));
        ui->table_showAllScientists->setItem(row,1,newItem1);

        QTableWidgetItem* newItem3 = new QTableWidgetItem();
        newItem3->setText(QString::number(currentComputer.getYearBuilt()));
        ui->table_showAllScientists->setItem(row,2,newItem3);

        QTableWidgetItem* newItem4 = new QTableWidgetItem();

        newItem4->setText(QString::number(currentComputer.getType()));
        if(newItem4->text().toInt() == 0){ ui-> table_showAllScientists-> setItem (row,4,new QTableWidgetItem("Electronic"));}
        if(newItem4->text().toInt() == 1){ ui-> table_showAllScientists-> setItem (row,4,new QTableWidgetItem("Mechatronic"));}
        if(newItem4->text().toInt() == 2){ ui-> table_showAllScientists-> setItem (row,4,new QTableWidgetItem("Transistor"));}
        if(newItem4->text().toInt() == 3){ ui-> table_showAllScientists-> setItem (row,4,new QTableWidgetItem("Other"));}


        else {ui->table_showAllScientists->setItem(row,3,new QTableWidgetItem("error"));}
        qDebug() << newItem4->text().toInt();

        QTableWidgetItem* newItem5 = new QTableWidgetItem();
        newItem5->setText(QString::number(currentComputer.wasBuilt()));
        //Sama Enum vese og í Scientists
        if(newItem5 == 0) { ui-> table_showAllScientists-> setItem (row,4,new QTableWidgetItem("No"));}
            else { ui->table_showAllScientists -> setItem(row,4,new QTableWidgetItem("Yes"));}

        //courtsey of https://forum.qt.io/topic/27584/fill-a-qtablewidget/10
      }
    currentComputers = computers;
}

void MainWindow::on_Input_Filter_Scientists_textChanged(const QString &arg1)
{
    QString index = ui->Dropdown_Menu->currentText();

    if(index == "Scientists")
    {
        ScientistService scientistService;

        string inputFilter = ui->Input_Filter_Scientists->text().toStdString();

        vector<Scientist>scientists = scientistService.searchForScientists(inputFilter);
        displayScientists(scientists);
    }
    if(index=="Computers")
    {
        ComputerService computerService;

        string inputFilter = ui->Input_Filter_Scientists->text().toStdString();

        vector<Computer>computers = computerService.searchForComputers(inputFilter);
        displayComputers(computers);
    }
}

void MainWindow::on_table_showAllScientists_clicked(const QModelIndex &index)
{
    ui->button_delete_scientist->setEnabled(true);
}

void MainWindow::on_button_delete_scientist_clicked()
{
    QString index = ui->Dropdown_Menu->currentText();
    if(index == "Scientists")
    {
        ScientistService scientistService;

        int indexOfSelected = ui->table_showAllScientists->currentIndex().row();
        Scientist currentlySelectedScientist = currentScientists.at(indexOfSelected);

        bool success = scientistService.removeScientist(currentlySelectedScientist);

        if (success)
        {
           ui->Input_Filter_Scientists->setText("");
           displayAllScientists();
           ui->statusBar->showMessage("Successfully removed scientist", 3000);
        }
        else
        {
           ui->statusBar->showMessage("Scientist was NOT deleted", 3000);
        }
    }
    if(index=="Computers")
    {
        ComputerService computerService;

        int indexOfSelected = ui->table_showAllScientists->currentIndex().row();
        Computer currentlySelectedComputer = currentComputers.at(indexOfSelected);

        bool success = computerService.removeComputer(currentlySelectedComputer);

        if (success)
        {
           ui->Input_Filter_Scientists->setText("");
           displayAllComputers();
           ui->statusBar->showMessage("Successfully removed Computer", 3000);
        }
        else
        {
           ui->statusBar->showMessage("Computer was NOT deleted", 3000);
        }
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

        ui->statusBar->showMessage("Successfully added scientist", 3000);
    }
    else
    {
        ui->statusBar->showMessage("Error! Scientist was not added, make sure tables have been created.", 3000);
    }
}

void MainWindow::on_Dropdown_Menu_currentIndexChanged(const QString &arg1)
{
    QString index = ui->Dropdown_Menu->currentText();
    if(index == "Scientists")
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
        ui->statusBar->showMessage("Please select a repository", 3000);
    }
}

void MainWindow::on_actionAdd_Scientists_triggered()
{
    on_button_add_scientist_clicked();
}

void MainWindow::on_actionAdd_Computer_triggered()
{
    on_button_add_computer_clicked();
}

void MainWindow::on_action_Exit_triggered()
{
    close();
}


void MainWindow::on_button_add_computer_clicked()
{
    AddComputerDialog addComputerDialog;
    addComputerDialog.setModal(true);
    int addComputerReturnValue = addComputerDialog.exec();

    if (addComputerReturnValue == 0)
    {
        ui->Input_Filter_Scientists->setText("");
        displayAllComputers();

        ui->statusBar->showMessage("Successfully added computer", 3000);
    }
    else
    {
        ui->statusBar->showMessage("Error! Computer was not added, make sure tables have been created.", 3000);
    }

}



void MainWindow::on_button_add_relasions_clicked()//Sverrir, used to open Relations window.
{
    relations addRelations;
    addRelations.setModal(true);
    addRelations.exec();
}
