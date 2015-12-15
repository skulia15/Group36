#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"
#include "services/scientistservice.h"
#include "utilities/utils.h"
#include "mainwindow.h"

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_button_add_Scientist_box_clicked()
{
    ScientistService scientistService;
    bool thereWasAnError = false;

    ui->label_error_name->setText("");
    ui->label_error_sex->setText("");
    ui->label_error_YoB->setText("");

    QString name = ui->Input_Scientist_Name->text();
    QString sex = ui->input_sex->text();
    QString YoB = ui->input_year_of_birth->text();
    QString YoD = ui->input_year_of_death->text();

    if (name.isEmpty()){
        ui->label_error_name->setText("The scientist must have a name!");

        thereWasAnError = true;
    }
    if (sex.isEmpty()){
        ui->label_error_sex->setText("The scientist must have a sex!");

        thereWasAnError = true;
    }
    if (YoB.isEmpty()){
        ui->label_error_YoB->setText("The scientist must have been born!");

        thereWasAnError = true;
    }


    if (thereWasAnError)
    {
        return;
    }

    bool success = scientistService.addScientist(Scientist(name.toStdString(), utils::stringToSex(sex.toStdString()), YoB.toInt(), YoD.toInt()));


    if (success){
        ui->Input_Scientist_Name->setText("");
        ui->input_sex->setText("");
        ui->input_year_of_birth->setText("");
        ui->input_year_of_death->setText("");
        this->done(0);
    }
    else{
        this->done(-1);
        // there was some error, tell the user
       qDebug() << QDate::currentDate();
    }
}

void AddScientistDialog::on_checkBox_cpuRelations_clicked()
{
    if(ui->checkBox_cpuRelations->isChecked())
        {
            ui->label_cpuRelationName->setEnabled(1);
        }
    else
        {
           ui->label_cpuRelationName->setEnabled(0);
        }
}
