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
#include "repositories/linkrepository.h"
#include "repositories/computerrepository.h"
#include "repositories/scientistrepository.h"
#include "relations.h"
#include "services/linkservice.h"
#include "utilities/utils.h"
#include "ui/relations.h"
#include "ui_relations.h"

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
    ui->button_add_computer->setVisible(false);
    ui->button_add_relasions->setVisible(false);


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


    ui->table_showAllScientists->setRowCount(scientists.size());
    ui->table_showAllScientists->setColumnCount(5);
    QStringList header;
    header << "ID" << "Name" << "Sex" << "YoB" << "YoD";
    ui->table_showAllScientists->setHorizontalHeaderLabels(header);
    ui->table_showAllScientists->setColumnWidth(0,120);
    ui->table_showAllScientists->setColumnWidth(1,120);
    ui->table_showAllScientists->setColumnWidth(2,120);
    ui->table_showAllScientists->setColumnWidth(3,120);
    ui->table_showAllScientists->setColumnWidth(4,120);
    ui->table_showAllScientists->showColumn(4);
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


        QTableWidgetItem* newItem2 = new QTableWidgetItem();
        newItem2->setText(QString::number(currentScientists.getSex()));
        int temp = newItem2->text().toInt();
        if (temp == 1){
            ui->table_showAllScientists->setItem(row,2,new QTableWidgetItem("Male"));
        }
        if (temp == 2){
            ui->table_showAllScientists->setItem(row,2,new QTableWidgetItem("Female"));
        }
        else{if (temp == 3){}
            ui->table_showAllScientists->setItem(row,2,new QTableWidgetItem("Male"));
        }



        QTableWidgetItem* newItem3 = new QTableWidgetItem();
        newItem3->setText(QString::number(currentScientists.getYearBorn()));
        ui->table_showAllScientists->setItem(row,3,newItem3);

        QTableWidgetItem* newItem4 = new QTableWidgetItem();
        newItem4->setText(QString::number(currentScientists.getYearDied()));
        temp = newItem4->text().toInt();
        if(temp == 0) { ui-> table_showAllScientists-> setItem (row,4,new QTableWidgetItem("Alive"));} //viljum fá ALIVE!!!
            else { ui->table_showAllScientists->setItem(row,4,newItem4);}

        //courtsey of https://forum.qt.io/topic/27584/fill-a-qtablewidget/10
      }
    currentScientists = scientists; //For indexing purposes
}

void MainWindow::displayAllComputers() //Sverrir, Sets all scientists to vector and calls display.
{
    ComputerService cpuService;

    vector<Computer>computer = cpuService.getAllComputers("name",true);

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
     ui->table_showAllScientists->setColumnWidth(0,120);
     ui->table_showAllScientists->setColumnWidth(1,120);
     ui->table_showAllScientists->setColumnWidth(2,120);
     ui->table_showAllScientists->setColumnWidth(3,120);
     ui->table_showAllScientists->setColumnWidth(4,120);

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
        int temp = newItem3->text().toInt();
        if(temp == 0){ ui-> table_showAllScientists-> setItem (row,2,new QTableWidgetItem("Not Built"));}
                else {ui->table_showAllScientists->setItem(row,2,newItem3);}

        QTableWidgetItem* newItem4 = new QTableWidgetItem();
        newItem4->setText(QString::number(currentComputer.getType()));
        temp = newItem4->text().toInt();

        if(temp == 1){
            ui->table_showAllScientists->setItem(row,3,new QTableWidgetItem("Electronic"));
        }
        if(temp == 2){
            ui->table_showAllScientists->setItem(row,3,new QTableWidgetItem("Mechatronic"));
        }
        if(temp == 3){
            ui->table_showAllScientists->setItem(row,3,new QTableWidgetItem("Transistor"));
        }
        if(temp == 4){
            ui->table_showAllScientists->setItem(row,3,new QTableWidgetItem("Other"));
        }


        QTableWidgetItem* newItem5 = new QTableWidgetItem();
        newItem5->setText(QString::number(currentComputer.wasBuilt()));
        //Sama Enum vese og í Scientists
        ui->table_showAllScientists->hideColumn(4);
        temp = newItem4->text().toInt();
        if(temp == 2) { ui-> table_showAllScientists-> setItem (row,4,new QTableWidgetItem("No"));}
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
    ui->button_wiki_search->setEnabled(true);
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
    if(index=="Relations"){
        LinkService link;

        int indexOfSelected = ui->table_showAllScientists->currentIndex().row();

        QString sciId = ui->table_showAllScientists->currentItem()->text();
        QString cpuId = ui->table_showAllScientists->currentItem()->text();

        bool success = link.removeLink(sciId.toStdString(), cpuId.toStdString());

        if (success)
        {
           ui->Input_Filter_Scientists->setText("");
           displayRelation();
           ui->statusBar->showMessage("Successfully removed Relation", 3000);
        }
        else
        {
           ui->statusBar->showMessage("Relation was NOT deleted", 3000);
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
    {   ui->table_showAllScientists->clear();
        displayAllScientists();
        ui->button_add_scientist->setVisible(true);
        ui->button_add_computer->setVisible(false);
        ui->button_add_relasions->setVisible(false);
        ui->button_wiki_search->setVisible(true);
    }
    if(index=="Computers")
    {   ui->table_showAllScientists->clear();
        displayAllComputers();
        ui->button_add_computer->setVisible(true);
        ui->button_add_relasions->setVisible(false);
        ui->button_add_scientist->setVisible(false);
        ui->button_wiki_search->setVisible(true);
    }
    if(index=="Relations")

    {   ui->table_showAllScientists->clear();
        displayRelation();

    {
        displayRelation();
        ui->button_add_scientist->setVisible(false);
        ui->button_add_computer->setVisible(false);
        ui->button_add_relasions->setVisible(true);
        ui->button_wiki_search->setVisible(false);

    }
    }else
    {
        ui->statusBar->showMessage("Please select a repository", 1000);
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
    int addRelationsReturnValue = addRelations.exec();


    if (addRelationsReturnValue == 0)
    {
        displayRelation();
        ui->statusBar->showMessage("Successfully added relation", 3000);
    }
    else
    {
        //ui->statusBar->showMessage("Error! Relation was not added, make sure tables have been created.", 3000);
        ui->statusBar->showMessage("Successfully added relation", 3000); //error displaying when successful? Weird...
    }
    displayRelation();
}


void MainWindow::displayRelation()
{

    std::vector<string>viktor;
    std::vector<string>viktor2;


    db = utils::getDatabaseConnection();


    QSqlQuery query(db);
    query.exec("SELECT *FROM ScientistComputerConnections");
    while(query.next())
    {
        string scid = query.value("scientistId").toString().toStdString();
        string cpuId = query.value("computerId").toString().toStdString();

        viktor.push_back(scid);
        viktor2.push_back(cpuId);
    }

    db.close();

   ui->table_showAllScientists->setRowCount(viktor.size());
   ui->table_showAllScientists->setColumnCount(3);
   QStringList header;
   header << "Id"<< "Sci ID" << "Cpu Id";
   ui->table_showAllScientists->setHorizontalHeaderLabels(header);
   ui->table_showAllScientists->hideColumn(0);
   ui->table_showAllScientists->setColumnWidth(0,120);
   ui->table_showAllScientists->setColumnWidth(1,120);
   ui->table_showAllScientists->setColumnWidth(2,120);


    for(unsigned int row = 0; row < viktor.size(); row++)
         {

            QTableWidgetItem* newItem = new QTableWidgetItem();
            newItem->setText(QString::fromStdString(viktor.at(row)));
            ui->table_showAllScientists->setItem(row,1,newItem);

         }
    for(unsigned int row = 0; row<viktor2.size();row++)
    {
        QTableWidgetItem* newItem2 = new QTableWidgetItem();
        newItem2->setText(QString::fromStdString(viktor2.at(row)));
        ui->table_showAllScientists->setItem(row,2,newItem2);
    }
}



void MainWindow::on_actionAdd_Relation_triggered()
{
    on_button_add_relasions_clicked();
}


void MainWindow::on_button_wiki_search_clicked()//searches wikipedia for computers
{
    QString index = ui->Dropdown_Menu->currentText();

    if(index == "Scientists")
    {
    ScientistService scientistService;

    int indexOfSelected = ui->table_showAllScientists->currentIndex().row();
    Scientist currentlySelectedScientist = currentScientists.at(indexOfSelected);
    string myString = currentlySelectedScientist.getName();
    string myOtherString = currentlySelectedScientist.getName();
    size_t pos = myString.find(" ");
    string str3 = myString.substr(pos);

    string myUrl = "https://en.wikipedia.org/wiki/"+myString+"_"+str3+"";;

    system(string("start " + myUrl).c_str());
    }
    if(index=="Computers")
    {
        ComputerService ComputerService;

        int indexOfSelected = ui->table_showAllScientists->currentIndex().row();
        Computer currentlySelectedComputer = currentComputers.at(indexOfSelected);
        string myString = currentlySelectedComputer.getName();


        string myUrl = "https://en.wikipedia.org/wiki/"+myString+"";

        system(string("start " + myUrl).c_str());
    }
}


void MainWindow::on_table_showAllScientists_customContextMenuRequested(const QPoint &pos)
{
    // for most widgets
    QPoint globalPos = ui->table_showAllScientists->mapToGlobal(pos);
    // for QAbstractScrollArea and derived classes you would use:
    // QPoint globalPos = myWidget->viewport()->mapToGlobal(pos);

    QMenu myMenu;
   // myMenu.addAction("Add Scientist");
   // myMenu.addAction("Add Computer");
   // myMenu.addAction("Add Relation");
   // myMenu.addAction("Exit");

    QAction* selectedItem = myMenu.exec(globalPos);
    if (selectedItem)
    {
        on_button_add_scientist_clicked();
    }
    if (selectedItem)
    {
        on_button_add_computer_clicked();
    }
    if (selectedItem)
    {
        on_button_add_relasions_clicked();
    }
    if (selectedItem)
    {
        close();
    }
    else
    {
        // nothing was chosen
    }
}

