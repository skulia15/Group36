#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"
#include "services/scientistservice.h"
#include "utilities/utils.h"
#include "mainwindow.h"

using namespace std;

bool checkStringValid(string myString);

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
    ui->comboBox_sex->addItem("");
    ui->comboBox_sex->addItem("Male");
    ui->comboBox_sex->addItem("Female");

    setWindowIcon(QIcon("myapp2.rc"));
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_button_add_Scientist_box_clicked()
{

    ScientistService scientistService;
    bool thereWasAnError = false;
    int sex;

    ui->label_error_name->setText("");
    ui->label_error_sex->setText("");
    ui->label_error_YoB->setText("");

    QString name = ui->Input_Scientist_Name->text();
    QString temp = ui->comboBox_sex->currentText();

    if (temp == "Male"){
        sex = 1;
    }
    else if (temp == "Female"){
        sex = 2;
    }
    else sex = 3;

    QString YoB = ui->input_year_of_birth->text();
    QString YoD = ui->input_year_of_death->text();


    if (name.isEmpty()){
        ui->label_error_name->setText("<span style=color:#FF2A1A>The scientist must have a name!</span>");

        thereWasAnError = true;
    }
    else if (!checkStringValid(name.toStdString())){
         ui->label_error_name->setText("<span style=color:#FF2A1A>The name can only contain alphabetic characters!</span>");

         thereWasAnError = true;
    }
    if (checkStringValid(YoB.toStdString())){
         ui->label_error_YoB->setText("<span style=color:#FF2A1A>This this field can only contain numbers!</span>");

         thereWasAnError = true;
    }

    if (checkStringValid(YoD.toStdString())){
        if (!YoD.isEmpty()){
            //ui->label_error_YoD->setText("<span style=color:#FF2A1A>This this field can only contain numbers!</span>");
        }

         thereWasAnError = true;
         if (YoD.isEmpty()){
             thereWasAnError = false;
         }
    }
    if (sex == 3){
        ui->label_error_sex->setText("<span style=color:#FF2A1A>The scientist must have a sex!</span>");

        thereWasAnError = true;
    }
    if (YoB.isEmpty()){
        ui->label_error_YoB->setText("<span style=color:#FF2A1A>The scientist must have been born!</span>");

        thereWasAnError = true;
    }

    if (thereWasAnError)
    {
        return;
    }

    bool success = scientistService.addScientist(Scientist(name.toStdString(), sex, YoB.toInt(), YoD.toInt()));


    if (success){
        ui->Input_Scientist_Name->setText("");
        ui->input_year_of_birth->setText("");
        ui->input_year_of_death->setText("");
        this->done(0);
    }
    else{
        this->done(-1);
    }
}

bool checkStringValid(string myString){
    bool error = false;
    for (unsigned int i = 0; i < myString.length(); i++){
        if (isalpha(myString[i]) || isspace(myString[i])){
            error = true;}
             else return false;
    }
    if (error == true){ return true;}
    else{ return false;}
}


