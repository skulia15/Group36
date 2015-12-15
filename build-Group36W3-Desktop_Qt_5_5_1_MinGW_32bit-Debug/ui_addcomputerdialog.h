/********************************************************************************
** Form generated from reading UI file 'addcomputerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddComputerDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_add_computer;
    QVBoxLayout *verticalLayout;
    QLabel *label_input_label_computer;
    QLabel *label_error_computer_name;
    QLineEdit *Input_computer_name;
    QLabel *label_year_built;
    QLabel *label_error_YB;
    QLineEdit *input_year_built;
    QLabel *label_Computer_type;
    QLabel *label_error_computer_type;
    QComboBox *comboBox_computer_type;
    QLabel *label;
    QLabel *label_2;
    QPushButton *button_add_computer_box;

    void setupUi(QDialog *AddComputerDialog)
    {
        if (AddComputerDialog->objectName().isEmpty())
            AddComputerDialog->setObjectName(QStringLiteral("AddComputerDialog"));
        AddComputerDialog->resize(465, 348);
        verticalLayout_2 = new QVBoxLayout(AddComputerDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_add_computer = new QLabel(AddComputerDialog);
        label_add_computer->setObjectName(QStringLiteral("label_add_computer"));

        verticalLayout_2->addWidget(label_add_computer, 0, Qt::AlignHCenter);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_input_label_computer = new QLabel(AddComputerDialog);
        label_input_label_computer->setObjectName(QStringLiteral("label_input_label_computer"));

        verticalLayout->addWidget(label_input_label_computer);

        label_error_computer_name = new QLabel(AddComputerDialog);
        label_error_computer_name->setObjectName(QStringLiteral("label_error_computer_name"));
        label_error_computer_name->setEnabled(true);

        verticalLayout->addWidget(label_error_computer_name);

        Input_computer_name = new QLineEdit(AddComputerDialog);
        Input_computer_name->setObjectName(QStringLiteral("Input_computer_name"));

        verticalLayout->addWidget(Input_computer_name);

        label_year_built = new QLabel(AddComputerDialog);
        label_year_built->setObjectName(QStringLiteral("label_year_built"));

        verticalLayout->addWidget(label_year_built);

        label_error_YB = new QLabel(AddComputerDialog);
        label_error_YB->setObjectName(QStringLiteral("label_error_YB"));

        verticalLayout->addWidget(label_error_YB);

        input_year_built = new QLineEdit(AddComputerDialog);
        input_year_built->setObjectName(QStringLiteral("input_year_built"));

        verticalLayout->addWidget(input_year_built);

        label_Computer_type = new QLabel(AddComputerDialog);
        label_Computer_type->setObjectName(QStringLiteral("label_Computer_type"));

        verticalLayout->addWidget(label_Computer_type);

        label_error_computer_type = new QLabel(AddComputerDialog);
        label_error_computer_type->setObjectName(QStringLiteral("label_error_computer_type"));

        verticalLayout->addWidget(label_error_computer_type);

        comboBox_computer_type = new QComboBox(AddComputerDialog);
        comboBox_computer_type->setObjectName(QStringLiteral("comboBox_computer_type"));
        comboBox_computer_type->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(comboBox_computer_type);


        verticalLayout_2->addLayout(verticalLayout);

        label = new QLabel(AddComputerDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(AddComputerDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        button_add_computer_box = new QPushButton(AddComputerDialog);
        button_add_computer_box->setObjectName(QStringLiteral("button_add_computer_box"));
        button_add_computer_box->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(button_add_computer_box);


        retranslateUi(AddComputerDialog);

        QMetaObject::connectSlotsByName(AddComputerDialog);
    } // setupUi

    void retranslateUi(QDialog *AddComputerDialog)
    {
        AddComputerDialog->setWindowTitle(QApplication::translate("AddComputerDialog", "Dialog", 0));
#ifndef QT_NO_TOOLTIP
        label_add_computer->setToolTip(QApplication::translate("AddComputerDialog", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_add_computer->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">Add a new Computer</span></p></body></html>", 0));
        label_input_label_computer->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">Computer Name</span></p></body></html>", 0));
        label_error_computer_name->setText(QString());
        label_year_built->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">Year Built </span><span style=\" font-size:9pt;\">(if relevant)</span></p></body></html>", 0));
        label_error_YB->setText(QString());
        label_Computer_type->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">Computer Type</span></p></body></html>", 0));
        label_error_computer_type->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        button_add_computer_box->setText(QApplication::translate("AddComputerDialog", "Add Computer", 0));
    } // retranslateUi

};

namespace Ui {
    class AddComputerDialog: public Ui_AddComputerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPUTERDIALOG_H
