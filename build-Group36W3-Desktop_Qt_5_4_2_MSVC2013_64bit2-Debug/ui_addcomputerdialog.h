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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
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
    QHBoxLayout *horizontalLayout;
    QLabel *label_input_label_computer;
    QLabel *label_error_computer_name;
    QLineEdit *Input_computer_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_computer_type;
    QLabel *label_pointless_alignment;
    QLineEdit *input_year_built;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_year_built;
    QLabel *label_error_computer_type;
    QLineEdit *input_computer_type;
    QPushButton *button_add_computer_box;

    void setupUi(QDialog *AddComputerDialog)
    {
        if (AddComputerDialog->objectName().isEmpty())
            AddComputerDialog->setObjectName(QStringLiteral("AddComputerDialog"));
        AddComputerDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(AddComputerDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_add_computer = new QLabel(AddComputerDialog);
        label_add_computer->setObjectName(QStringLiteral("label_add_computer"));

        verticalLayout_2->addWidget(label_add_computer, 0, Qt::AlignHCenter);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_input_label_computer = new QLabel(AddComputerDialog);
        label_input_label_computer->setObjectName(QStringLiteral("label_input_label_computer"));

        horizontalLayout->addWidget(label_input_label_computer);

        label_error_computer_name = new QLabel(AddComputerDialog);
        label_error_computer_name->setObjectName(QStringLiteral("label_error_computer_name"));
        label_error_computer_name->setEnabled(true);

        horizontalLayout->addWidget(label_error_computer_name);


        verticalLayout->addLayout(horizontalLayout);

        Input_computer_name = new QLineEdit(AddComputerDialog);
        Input_computer_name->setObjectName(QStringLiteral("Input_computer_name"));

        verticalLayout->addWidget(Input_computer_name);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_computer_type = new QLabel(AddComputerDialog);
        label_computer_type->setObjectName(QStringLiteral("label_computer_type"));

        horizontalLayout_4->addWidget(label_computer_type, 0, Qt::AlignHCenter);

        label_pointless_alignment = new QLabel(AddComputerDialog);
        label_pointless_alignment->setObjectName(QStringLiteral("label_pointless_alignment"));

        horizontalLayout_4->addWidget(label_pointless_alignment);


        verticalLayout->addLayout(horizontalLayout_4);

        input_year_built = new QLineEdit(AddComputerDialog);
        input_year_built->setObjectName(QStringLiteral("input_year_built"));

        verticalLayout->addWidget(input_year_built);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_year_built = new QLabel(AddComputerDialog);
        label_year_built->setObjectName(QStringLiteral("label_year_built"));

        horizontalLayout_3->addWidget(label_year_built, 0, Qt::AlignHCenter);

        label_error_computer_type = new QLabel(AddComputerDialog);
        label_error_computer_type->setObjectName(QStringLiteral("label_error_computer_type"));

        horizontalLayout_3->addWidget(label_error_computer_type);


        verticalLayout->addLayout(horizontalLayout_3);

        input_computer_type = new QLineEdit(AddComputerDialog);
        input_computer_type->setObjectName(QStringLiteral("input_computer_type"));

        verticalLayout->addWidget(input_computer_type);

        button_add_computer_box = new QPushButton(AddComputerDialog);
        button_add_computer_box->setObjectName(QStringLiteral("button_add_computer_box"));

        verticalLayout->addWidget(button_add_computer_box);


        verticalLayout_2->addLayout(verticalLayout);


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
        label_input_label_computer->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">Computer Name</span></p></body></html>", 0));
        label_error_computer_name->setText(QString());
        label_computer_type->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">Year Built </span><span style=\" font-size:9pt;\">(if relevant)</span></p></body></html>", 0));
        label_pointless_alignment->setText(QString());
        label_year_built->setText(QApplication::translate("AddComputerDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">Computer Type</span></p></body></html>", 0));
        label_error_computer_type->setText(QString());
        button_add_computer_box->setText(QApplication::translate("AddComputerDialog", "Add Computer", 0));
    } // retranslateUi

};

namespace Ui {
    class AddComputerDialog: public Ui_AddComputerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPUTERDIALOG_H
