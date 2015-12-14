/********************************************************************************
** Form generated from reading UI file 'addscientistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSCIENTISTDIALOG_H
#define UI_ADDSCIENTISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddScientistDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_add_scientist;
    QLabel *label_input_label;
    QLabel *label_error_name;
    QLineEdit *Input_Scientist_Name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_input_sex;
    QLabel *label_error_sex;
    QLineEdit *input_sex;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_year_of_birth;
    QLabel *label_error_YoB;
    QLineEdit *input_year_of_birth;
    QLabel *label_year_of_death;
    QLineEdit *input_year_of_death;
    QPushButton *button_add_Scientist_box;

    void setupUi(QDialog *AddScientistDialog)
    {
        if (AddScientistDialog->objectName().isEmpty())
            AddScientistDialog->setObjectName(QStringLiteral("AddScientistDialog"));
        AddScientistDialog->resize(440, 348);
        verticalLayout_2 = new QVBoxLayout(AddScientistDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_add_scientist = new QLabel(AddScientistDialog);
        label_add_scientist->setObjectName(QStringLiteral("label_add_scientist"));

        horizontalLayout->addWidget(label_add_scientist);

        label_input_label = new QLabel(AddScientistDialog);
        label_input_label->setObjectName(QStringLiteral("label_input_label"));

        horizontalLayout->addWidget(label_input_label);

        label_error_name = new QLabel(AddScientistDialog);
        label_error_name->setObjectName(QStringLiteral("label_error_name"));
        label_error_name->setEnabled(true);

        horizontalLayout->addWidget(label_error_name);


        verticalLayout_2->addLayout(horizontalLayout);

        Input_Scientist_Name = new QLineEdit(AddScientistDialog);
        Input_Scientist_Name->setObjectName(QStringLiteral("Input_Scientist_Name"));

        verticalLayout_2->addWidget(Input_Scientist_Name);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_input_sex = new QLabel(AddScientistDialog);
        label_input_sex->setObjectName(QStringLiteral("label_input_sex"));

        horizontalLayout_2->addWidget(label_input_sex);

        label_error_sex = new QLabel(AddScientistDialog);
        label_error_sex->setObjectName(QStringLiteral("label_error_sex"));

        horizontalLayout_2->addWidget(label_error_sex);


        verticalLayout_2->addLayout(horizontalLayout_2);

        input_sex = new QLineEdit(AddScientistDialog);
        input_sex->setObjectName(QStringLiteral("input_sex"));

        verticalLayout_2->addWidget(input_sex);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_year_of_birth = new QLabel(AddScientistDialog);
        label_year_of_birth->setObjectName(QStringLiteral("label_year_of_birth"));

        horizontalLayout_3->addWidget(label_year_of_birth);

        label_error_YoB = new QLabel(AddScientistDialog);
        label_error_YoB->setObjectName(QStringLiteral("label_error_YoB"));

        horizontalLayout_3->addWidget(label_error_YoB);


        verticalLayout_2->addLayout(horizontalLayout_3);

        input_year_of_birth = new QLineEdit(AddScientistDialog);
        input_year_of_birth->setObjectName(QStringLiteral("input_year_of_birth"));

        verticalLayout_2->addWidget(input_year_of_birth);

        label_year_of_death = new QLabel(AddScientistDialog);
        label_year_of_death->setObjectName(QStringLiteral("label_year_of_death"));

        verticalLayout_2->addWidget(label_year_of_death);

        input_year_of_death = new QLineEdit(AddScientistDialog);
        input_year_of_death->setObjectName(QStringLiteral("input_year_of_death"));

        verticalLayout_2->addWidget(input_year_of_death);

        button_add_Scientist_box = new QPushButton(AddScientistDialog);
        button_add_Scientist_box->setObjectName(QStringLiteral("button_add_Scientist_box"));

        verticalLayout_2->addWidget(button_add_Scientist_box);


        retranslateUi(AddScientistDialog);

        QMetaObject::connectSlotsByName(AddScientistDialog);
    } // setupUi

    void retranslateUi(QDialog *AddScientistDialog)
    {
        AddScientistDialog->setWindowTitle(QApplication::translate("AddScientistDialog", "Dialog", 0));
        label_add_scientist->setText(QApplication::translate("AddScientistDialog", "Add a new Scientist", 0));
        label_input_label->setText(QApplication::translate("AddScientistDialog", "Input scientist name", 0));
        label_error_name->setText(QString());
        label_input_sex->setText(QApplication::translate("AddScientistDialog", "Sex", 0));
        label_error_sex->setText(QString());
        label_year_of_birth->setText(QApplication::translate("AddScientistDialog", "Year of birth", 0));
        label_error_YoB->setText(QString());
        label_year_of_death->setText(QApplication::translate("AddScientistDialog", "Year of death", 0));
        button_add_Scientist_box->setText(QApplication::translate("AddScientistDialog", "Add Scientist", 0));
    } // retranslateUi

};

namespace Ui {
    class AddScientistDialog: public Ui_AddScientistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSCIENTISTDIALOG_H
