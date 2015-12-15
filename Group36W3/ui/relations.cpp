#include "relations.h"
#include "ui_relations.h"
#include "utilities/utils.h"
#include "services/linkservice.h"
#include "services/scientistservice.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>

using namespace std;

relations::relations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::relations)
{
    ui->setupUi(this);
    displayAllScientistsRelations();
    displayAllComputersRelations();
    ComputerService computerService;
    LinkService links;
    ScientistService scientistService;
}

relations::~relations()
{
    delete ui;
}




void relations::displayAllScientistsRelations()//Sverrir, Sets all scientists to vector and calls display.
{
    ScientistService scientistService;
    vector<Scientist>scientists = scientistService.getAllScientists("name",true);

    displayScientistsRelations(scientists);
}


void relations::displayScientistsRelations(std::vector<Scientist> scientists)//Sverrir, shows scientists.at(i).
{

    ui->table_relations_scientists->setRowCount(scientists.size());
    ui->table_relations_scientists->setColumnCount(2);
    ui->table_relations_scientists->setColumnWidth(0, 30);
    QStringList header;
    header << "ID" << "Name";
    ui->table_relations_scientists->setHorizontalHeaderLabels(header);


     for(unsigned int row = 0; row < scientists.size(); row++)
     {
        Scientist currentScientists = scientists.at(row);

        QTableWidgetItem* newItem = new QTableWidgetItem();
        newItem->setText(QString::number(currentScientists.getId()));
        ui->table_relations_scientists->setItem(row,0,newItem);

        QTableWidgetItem* newItem1 = new QTableWidgetItem();
        newItem1->setText(QString::fromStdString(currentScientists.getName()));
        ui->table_relations_scientists->setItem(row,1,newItem1);

        //courtsey of https://forum.qt.io/topic/27584/fill-a-qtablewidget/10
      }
    currentScientists = scientists; //For indexing purposes
}

void relations::displayAllComputersRelations() //Sverrir, Sets all scientists to vector and calls display.
{
    ComputerService cpuService;

    vector<Computer>computer = cpuService.getAllComputers("name",true);

    displayComputersRelations(computer);

}


void relations::displayComputersRelations(std::vector<Computer> computers)
{
    ui->table_relations_Computers->setRowCount(computers.size());
    ui->table_relations_Computers->setColumnCount(2);
    ui->table_relations_Computers->setColumnWidth(0, 30);
    QStringList header;
    header << "ID" << "Name";
    ui->table_relations_Computers->setHorizontalHeaderLabels(header);
    // ui->table_relations_Computers->hideColumn(0);

     for(unsigned int row = 0; row < computers.size(); row++)
     {
        Computer currentComputer = computers.at(row);

        QTableWidgetItem* newItem = new QTableWidgetItem();
        newItem->setText(QString::number(currentComputer.getId()));
        ui->table_relations_Computers->setItem(row,0,newItem);

        QTableWidgetItem* newItem1 = new QTableWidgetItem();
        newItem1->setText(QString::fromStdString(currentComputer.getName()));
        ui->table_relations_Computers->setItem(row,1,newItem1);

        //courtsey of https://forum.qt.io/topic/27584/fill-a-qtablewidget/10
      }
    currentComputers = computers;
}

void relations::on_pushButton_clicked()
{

    LinkService link;
    QString sciId = ui->table_relations_scientists->currentItem()->text();
    QString cpuId = ui->table_relations_Computers->currentItem()->text();
    if(!sciId.isEmpty())
    {
        link.addLink(sciId.toStdString(),cpuId.toStdString());
    }
    else
    {
       //Error
    }

}
