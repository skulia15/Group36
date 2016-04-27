/********************************************************************************
** Form generated from reading UI file 'relations.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RELATIONS_H
#define UI_RELATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_relations
{
public:
    QPushButton *pushButton;
    QLabel *label_add_relation_prompt;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_error_cpu;
    QTableWidget *table_relations_scientists;
    QTableWidget *table_relations_Computers;
    QLabel *label_error_Sci;

    void setupUi(QDialog *relations)
    {
        if (relations->objectName().isEmpty())
            relations->setObjectName(QStringLiteral("relations"));
        relations->resize(590, 364);
        pushButton = new QPushButton(relations);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(160, 330, 274, 23));
        label_add_relation_prompt = new QLabel(relations);
        label_add_relation_prompt->setObjectName(QStringLiteral("label_add_relation_prompt"));
        label_add_relation_prompt->setGeometry(QRect(230, 0, 141, 31));
        label = new QLabel(relations);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 571, 21));
        layoutWidget = new QWidget(relations);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 80, 520, 242));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_error_cpu = new QLabel(layoutWidget);
        label_error_cpu->setObjectName(QStringLiteral("label_error_cpu"));

        gridLayout->addWidget(label_error_cpu, 0, 2, 1, 2, Qt::AlignHCenter);

        table_relations_scientists = new QTableWidget(layoutWidget);
        table_relations_scientists->setObjectName(QStringLiteral("table_relations_scientists"));
        table_relations_scientists->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_relations_scientists->setAlternatingRowColors(true);
        table_relations_scientists->setSelectionMode(QAbstractItemView::SingleSelection);
        table_relations_scientists->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_relations_scientists->setSortingEnabled(true);
        table_relations_scientists->horizontalHeader()->setStretchLastSection(true);
        table_relations_scientists->verticalHeader()->setVisible(false);

        gridLayout->addWidget(table_relations_scientists, 1, 0, 1, 2);

        table_relations_Computers = new QTableWidget(layoutWidget);
        table_relations_Computers->setObjectName(QStringLiteral("table_relations_Computers"));
        table_relations_Computers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_relations_Computers->setAlternatingRowColors(true);
        table_relations_Computers->setSelectionMode(QAbstractItemView::SingleSelection);
        table_relations_Computers->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_relations_Computers->setSortingEnabled(true);
        table_relations_Computers->horizontalHeader()->setStretchLastSection(true);
        table_relations_Computers->verticalHeader()->setVisible(false);

        gridLayout->addWidget(table_relations_Computers, 1, 2, 1, 2);

        label_error_Sci = new QLabel(layoutWidget);
        label_error_Sci->setObjectName(QStringLiteral("label_error_Sci"));

        gridLayout->addWidget(label_error_Sci, 0, 0, 1, 2, Qt::AlignHCenter);


        retranslateUi(relations);

        QMetaObject::connectSlotsByName(relations);
    } // setupUi

    void retranslateUi(QDialog *relations)
    {
        relations->setWindowTitle(QApplication::translate("relations", "Dialog", 0));
        pushButton->setText(QApplication::translate("relations", "Add Relation", 0));
        label_add_relation_prompt->setText(QApplication::translate("relations", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">Add a Relation</span></p></body></html>", 0));
        label->setText(QApplication::translate("relations", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Select a scientist from the list on the left and then a computer from the other to create a relation</span></p></body></html>", 0));
        label_error_cpu->setText(QApplication::translate("relations", "Select a computer to relate to", 0));
        label_error_Sci->setText(QApplication::translate("relations", "Select a scientist to relate", 0));
    } // retranslateUi

};

namespace Ui {
    class relations: public Ui_relations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELATIONS_H
