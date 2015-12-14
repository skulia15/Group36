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

class Ui_Dialog_computer
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_add_computer_prompt;
    QHBoxLayout *horizontalLayout;
    QLabel *label_computer_name;
    QLabel *label_error_comp_name;
    QLineEdit *input_computer_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_year_built;
    QLabel *label_error_comp_YB;
    QLineEdit *input_year_built;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_computer_type;
    QLabel *label_error_comp_type;
    QLineEdit *input_computer_type;
    QPushButton *button_end_add_computer;

    void setupUi(QDialog *Dialog_computer)
    {
        if (Dialog_computer->objectName().isEmpty())
            Dialog_computer->setObjectName(QStringLiteral("Dialog_computer"));
        Dialog_computer->resize(904, 310);
        verticalLayout = new QVBoxLayout(Dialog_computer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_add_computer_prompt = new QLabel(Dialog_computer);
        label_add_computer_prompt->setObjectName(QStringLiteral("label_add_computer_prompt"));

        verticalLayout->addWidget(label_add_computer_prompt, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_computer_name = new QLabel(Dialog_computer);
        label_computer_name->setObjectName(QStringLiteral("label_computer_name"));

        horizontalLayout->addWidget(label_computer_name);

        label_error_comp_name = new QLabel(Dialog_computer);
        label_error_comp_name->setObjectName(QStringLiteral("label_error_comp_name"));

        horizontalLayout->addWidget(label_error_comp_name);


        verticalLayout->addLayout(horizontalLayout);

        input_computer_name = new QLineEdit(Dialog_computer);
        input_computer_name->setObjectName(QStringLiteral("input_computer_name"));

        verticalLayout->addWidget(input_computer_name);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_year_built = new QLabel(Dialog_computer);
        label_year_built->setObjectName(QStringLiteral("label_year_built"));

        horizontalLayout_2->addWidget(label_year_built);

        label_error_comp_YB = new QLabel(Dialog_computer);
        label_error_comp_YB->setObjectName(QStringLiteral("label_error_comp_YB"));

        horizontalLayout_2->addWidget(label_error_comp_YB);


        verticalLayout->addLayout(horizontalLayout_2);

        input_year_built = new QLineEdit(Dialog_computer);
        input_year_built->setObjectName(QStringLiteral("input_year_built"));

        verticalLayout->addWidget(input_year_built);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_computer_type = new QLabel(Dialog_computer);
        label_computer_type->setObjectName(QStringLiteral("label_computer_type"));

        horizontalLayout_3->addWidget(label_computer_type);

        label_error_comp_type = new QLabel(Dialog_computer);
        label_error_comp_type->setObjectName(QStringLiteral("label_error_comp_type"));

        horizontalLayout_3->addWidget(label_error_comp_type);


        verticalLayout->addLayout(horizontalLayout_3);

        input_computer_type = new QLineEdit(Dialog_computer);
        input_computer_type->setObjectName(QStringLiteral("input_computer_type"));

        verticalLayout->addWidget(input_computer_type);

        button_end_add_computer = new QPushButton(Dialog_computer);
        button_end_add_computer->setObjectName(QStringLiteral("button_end_add_computer"));

        verticalLayout->addWidget(button_end_add_computer);


        retranslateUi(Dialog_computer);

        QMetaObject::connectSlotsByName(Dialog_computer);
    } // setupUi

    void retranslateUi(QDialog *Dialog_computer)
    {
        Dialog_computer->setWindowTitle(QApplication::translate("Dialog_computer", "Dialog", 0));
        label_add_computer_prompt->setText(QApplication::translate("Dialog_computer", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Add a new Computer</span></p></body></html>", 0));
        label_computer_name->setText(QApplication::translate("Dialog_computer", "<html><head/><body><p><span style=\" font-size:10pt;\">Computer name</span></p></body></html>", 0));
        label_error_comp_name->setText(QString());
        label_year_built->setText(QApplication::translate("Dialog_computer", "<html><head/><body><p><span style=\" font-size:10pt;\">Year built</span></p></body></html>", 0));
        label_error_comp_YB->setText(QString());
        label_computer_type->setText(QApplication::translate("Dialog_computer", "<html><head/><body><p><span style=\" font-size:10pt;\">Computer type</span></p></body></html>", 0));
        label_error_comp_type->setText(QString());
        button_end_add_computer->setText(QApplication::translate("Dialog_computer", "Add Computer", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_computer: public Ui_Dialog_computer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPUTERDIALOG_H
