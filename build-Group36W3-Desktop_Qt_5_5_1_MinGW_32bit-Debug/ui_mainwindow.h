/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *Dropdown_Menu;
    QLineEdit *Input_Filter_Scientists;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *table_showAllScientists;
    QPushButton *button_add_scientist;
    QPushButton *button_delete_scientist;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(531, 417);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Dropdown_Menu = new QComboBox(centralWidget);
        Dropdown_Menu->setObjectName(QStringLiteral("Dropdown_Menu"));

        verticalLayout->addWidget(Dropdown_Menu);

        Input_Filter_Scientists = new QLineEdit(centralWidget);
        Input_Filter_Scientists->setObjectName(QStringLiteral("Input_Filter_Scientists"));

        verticalLayout->addWidget(Input_Filter_Scientists);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        table_showAllScientists = new QTableWidget(centralWidget);
        if (table_showAllScientists->columnCount() < 5)
            table_showAllScientists->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_showAllScientists->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_showAllScientists->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_showAllScientists->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_showAllScientists->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_showAllScientists->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        table_showAllScientists->setObjectName(QStringLiteral("table_showAllScientists"));
        table_showAllScientists->setSelectionMode(QAbstractItemView::ExtendedSelection);
        table_showAllScientists->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_showAllScientists->setSortingEnabled(true);
        table_showAllScientists->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_4->addWidget(table_showAllScientists);


        verticalLayout->addLayout(horizontalLayout_4);

        button_add_scientist = new QPushButton(centralWidget);
        button_add_scientist->setObjectName(QStringLiteral("button_add_scientist"));

        verticalLayout->addWidget(button_add_scientist);

        button_delete_scientist = new QPushButton(centralWidget);
        button_delete_scientist->setObjectName(QStringLiteral("button_delete_scientist"));
        button_delete_scientist->setEnabled(false);

        verticalLayout->addWidget(button_delete_scientist);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 531, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        Dropdown_Menu->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Choose repository</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        Input_Filter_Scientists->setPlaceholderText(QApplication::translate("MainWindow", "Filter scientists..", 0));
        QTableWidgetItem *___qtablewidgetitem = table_showAllScientists->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Id", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_showAllScientists->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_showAllScientists->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Sex", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_showAllScientists->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Birth Year", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_showAllScientists->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Died in ", 0));
        button_add_scientist->setText(QApplication::translate("MainWindow", "Add", 0));
        button_delete_scientist->setText(QApplication::translate("MainWindow", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
