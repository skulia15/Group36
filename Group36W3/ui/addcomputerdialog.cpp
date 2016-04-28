#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "utilities/utils.h"
#include "mainwindow.h"
using namespace std;

bool checkStringValid(string myString);
bool checkCompStringValid(string myString);

AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
    ui->comboBox_computer_type->addItem("");
    ui->comboBox_computer_type->addItem("Electronic");
    ui->comboBox_computer_type->addItem("Mechatronic");
    ui->comboBox_computer_type->addItem("Transistor");
    ui->comboBox_computer_type->addItem("Other");
}

AddComputerDialog::~AddComputerDialog()
{
    delete ui;
}

void AddComputerDialog::on_button_add_computer_box_clicked()
{
    ComputerService computerService;

    bool thereWasAnError = false;
    QString computerType;
    int temp;

    ui->label_error_computer_name->setText("");
    ui->label_error_computer_type->setText("");

    QString name = ui->Input_computer_name->text();
    QString yearBuilt = ui->input_year_built->text();

    if(ui->comboBox_computer_type->currentText() == "Electronic"){
        temp = 1;
        computerType = temp;
        qDebug()<<temp<<computerType;
    }
    if(ui->comboBox_computer_type->currentText() == "Mechatronic"){
        temp = 2;
        computerType = temp;

    }
    if(ui->comboBox_computer_type->currentText() == "Transistor"){
        temp = 3;
        computerType = temp;
    qDebug()<<temp<<computerType;
    }
    if(ui->comboBox_computer_type->currentText() == "Other"){
        temp = 4;
        computerType = temp;

    }

    if (name.isEmpty()){
        ui->label_error_computer_name->setText("<span style=color:#FF2A1A>The computer must have a name!</span>");

        thereWasAnError = true;
    }

    else if (!checkCompStringValid(name.toStdString())){
         ui->label_error_computer_name->setText("<span style=color:#FF2A1A>The name must only contain alphanumeric characters</span>");

         thereWasAnError = true;
    }
    if (checkStringValid(yearBuilt.toStdString())){
        if (!yearBuilt.isEmpty()){
            //ui->label_error_YB->setText("<span style=color:#FF2A1A>This this field can only contain numbers!</span>");
        }
         thereWasAnError = true;
         if (yearBuilt.isEmpty()){
             thereWasAnError = false;
         }
    }
    if (computerType.isEmpty()){
        ui->label_error_computer_type->setText("<span style=color:#FF2A1A>The computer must have a type!</span>");

        thereWasAnError = true;
    }

    if (thereWasAnError)
    {
        return;
    }

    bool success = computerService.addComputer(Computer(name.toStdString(), temp, yearBuilt.toInt()));

    if (success){
        ui->Input_computer_name->setText("");
        ui->input_year_built->setText("");
        this->done(0);
    }
    else{
        this->done(-1);

    }
}

bool checkCompStringValid(string myString){
    bool error = false;
    for (unsigned int i = 0; i < myString.length(); i++){
        if (isalnum(myString[i]) || isspace(myString[i])){
            error = true;}
             else return false;
    }
    if (error == true) return true;
    else return false;
  }
