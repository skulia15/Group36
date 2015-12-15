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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_relations
{
public:
    QTableWidget *table_relations_scientists;
    QTableWidget *table_relations_Computers;
    QPushButton *pushButton;

    void setupUi(QDialog *relations)
    {
        if (relations->objectName().isEmpty())
            relations->setObjectName(QStringLiteral("relations"));
        relations->resize(590, 364);
        table_relations_scientists = new QTableWidget(relations);
        table_relations_scientists->setObjectName(QStringLiteral("table_relations_scientists"));
        table_relations_scientists->setGeometry(QRect(20, 30, 256, 192));
        table_relations_scientists->setAlternatingRowColors(true);
        table_relations_scientists->setSelectionMode(QAbstractItemView::MultiSelection);
        table_relations_scientists->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_relations_scientists->setSortingEnabled(true);
        table_relations_scientists->horizontalHeader()->setStretchLastSection(true);
        table_relations_Computers = new QTableWidget(relations);
        table_relations_Computers->setObjectName(QStringLiteral("table_relations_Computers"));
        table_relations_Computers->setGeometry(QRect(310, 30, 256, 192));
        table_relations_Computers->setAlternatingRowColors(true);
        table_relations_Computers->setSelectionMode(QAbstractItemView::MultiSelection);
        table_relations_Computers->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_relations_Computers->setSortingEnabled(true);
        table_relations_Computers->horizontalHeader()->setStretchLastSection(true);
        pushButton = new QPushButton(relations);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 270, 111, 23));

        retranslateUi(relations);

        QMetaObject::connectSlotsByName(relations);
    } // setupUi

    void retranslateUi(QDialog *relations)
    {
        relations->setWindowTitle(QApplication::translate("relations", "Dialog", 0));
        pushButton->setText(QApplication::translate("relations", "Add Relation", 0));
    } // retranslateUi

};

namespace Ui {
    class relations: public Ui_relations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELATIONS_H
