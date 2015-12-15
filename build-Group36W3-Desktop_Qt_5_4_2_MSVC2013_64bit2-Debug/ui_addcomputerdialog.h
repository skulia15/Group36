/********************************************************************************
** Form generated from reading UI file 'addcomputerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMPUTERDIALOG_H
#define UI_ADDCOMPUTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddComputerDialog
{
public:
    QPushButton *button_add_computer_box;
    QLineEdit *Input_computer_name;
    QLineEdit *input_year_built;
    QLabel *label_add_computer;
    QLabel *label_computer_type;
    QLabel *label_error_computer_type;
    QLabel *label_year_built;
    QLabel *label_input_label_computer;
    QComboBox *comboBox_computer_type;
    QLabel *label_error_computer_name;

    void setupUi(QDialog *AddComputerDialog)
    {
        if (AddComputerDialog->objectName().isEmpty())
            AddComputerDialog->setObjectName(QStringLiteral("AddComputerDialog"));
        AddComputerDialog->resize(400, 300);
        button_add_computer_box = new QPushButton(AddComputerDialog);
        button_add_computer_box->setObjectName(QStringLiteral("button_add_computer_box"));
        button_add_computer_box->setGeometry(QRect(130, 260, 151, 23));
        Input_computer_name = new QLineEdit(AddComputerDialog);
        Input_computer_name->setObjectName(QStringLiteral("Input_computer_name"));
        Input_computer_name->setGeometry(QRect(9, 99, 241, 20));
        input_year_built = new QLineEdit(AddComputerDialog);
        input_year_built->setObjectName(QStringLiteral("input_year_built"));
        input_year_built->setGeometry(QRect(9, 156, 241, 20));
        label_add_computer = new QLabel(AddComputerDialog);
        label_add_computer->setObjectName(QStringLiteral("label_add_computer"));
        label_add_computer->setGeometry(QRect(120, 20, 171, 19));
        label_computer_type = new QLabel(AddComputerDialog);
        label_computer_type->setObjectName(QStringLiteral("label_computer_type"));
        label_computer_type->setGeometry(QRect(9, 125, 131, 18));
        label_error_computer_type = new QLabel(AddComputerDialog);
        label_error_computer_type->setObjectName(QStringLiteral("label_error_computer_type"));
        label_error_computer_type->setGeometry(QRect(130, 180, 191, 20));
        label_year_built = new QLabel(AddComputerDialog);
        label_year_built->setObjectName(QStringLiteral("label_year_built"));
        label_year_built->setGeometry(QRect(9, 182, 103, 18));
        label_input_label_computer = new QLabel(AddComputerDialog);
        label_input_label_computer->setObjectName(QStringLiteral("label_input_label_computer"));
        label_input_label_computer->setGeometry(QRect(9, 69, 108, 18));
        comboBox_computer_type = new QComboBox(AddComputerDialog);
        comboBox_computer_type->setObjectName(QStringLiteral("comboBox_computer_type"));
        comboBox_computer_type->setGeometry(QRect(10, 200, 241, 22));
        label_error_computer_name = new QLabel(AddComputerDialog);
        label_error_computer_name->setObjectName(QStringLiteral("label_error_computer_name"));
        label_error_computer_name->setEnabled(true);
        label_error_computer_name->setGeometry(QRect(130, 70, 211, 16));

        retranslateUi(AddComputerDialog);

        QMetaObject::connectSlotsByName(AddComputerDialog);
    } // setupUi

    void retranslateUi(QDialog *AddComputerDialog)
    {
        AddComputerDialog->setWindowTitle(QApplication::translate("AddComputerDialog", "Dialog", 0));
        button_add_computer_box->setText(QApplication::translate("AddComputerDialog", "Add Computer", 0));
#ifndef QT_NO_TOOLTIP
        label_add_computer->setToolTip(QApplication::translate("AddComputerDialog", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_add_computer->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">Add a new Computer</span></p></body></html>", 0));
        label_computer_type->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">Year Built </span><span style=\" font-size:9pt;\">(if relevant)</span></p></body></html>", 0));
        label_error_computer_type->setText(QString());
        label_year_built->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">Computer Type</span></p></body></html>", 0));
        label_input_label_computer->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">Computer Name</span></p></body></html>", 0));
        label_error_computer_name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddComputerDialog: public Ui_AddComputerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPUTERDIALOG_H
