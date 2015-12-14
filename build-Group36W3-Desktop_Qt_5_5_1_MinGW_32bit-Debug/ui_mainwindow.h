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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QLineEdit *Input_Filter_Scientists;
    QTableWidget *table_showAllScientists;
    QLabel *label_add_scientist;
    QHBoxLayout *horizontalLayout;
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
    QPushButton *button_scientists_to_table;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(945, 403);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Input_Filter_Scientists = new QLineEdit(centralWidget);
        Input_Filter_Scientists->setObjectName(QStringLiteral("Input_Filter_Scientists"));

        verticalLayout->addWidget(Input_Filter_Scientists);

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
        table_showAllScientists->setSelectionBehavior(QAbstractItemView::SelectColumns);

        verticalLayout->addWidget(table_showAllScientists);

        label_add_scientist = new QLabel(centralWidget);
        label_add_scientist->setObjectName(QStringLiteral("label_add_scientist"));

        verticalLayout->addWidget(label_add_scientist);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_input_label = new QLabel(centralWidget);
        label_input_label->setObjectName(QStringLiteral("label_input_label"));

        horizontalLayout->addWidget(label_input_label);

        label_error_name = new QLabel(centralWidget);
        label_error_name->setObjectName(QStringLiteral("label_error_name"));
        label_error_name->setEnabled(true);

        horizontalLayout->addWidget(label_error_name);


        verticalLayout->addLayout(horizontalLayout);

        Input_Scientist_Name = new QLineEdit(centralWidget);
        Input_Scientist_Name->setObjectName(QStringLiteral("Input_Scientist_Name"));

        verticalLayout->addWidget(Input_Scientist_Name);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_input_sex = new QLabel(centralWidget);
        label_input_sex->setObjectName(QStringLiteral("label_input_sex"));

        horizontalLayout_2->addWidget(label_input_sex);

        label_error_sex = new QLabel(centralWidget);
        label_error_sex->setObjectName(QStringLiteral("label_error_sex"));

        horizontalLayout_2->addWidget(label_error_sex);


        verticalLayout->addLayout(horizontalLayout_2);

        input_sex = new QLineEdit(centralWidget);
        input_sex->setObjectName(QStringLiteral("input_sex"));

        verticalLayout->addWidget(input_sex);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_year_of_birth = new QLabel(centralWidget);
        label_year_of_birth->setObjectName(QStringLiteral("label_year_of_birth"));

        horizontalLayout_3->addWidget(label_year_of_birth);

        label_error_YoB = new QLabel(centralWidget);
        label_error_YoB->setObjectName(QStringLiteral("label_error_YoB"));

        horizontalLayout_3->addWidget(label_error_YoB);


        verticalLayout->addLayout(horizontalLayout_3);

        input_year_of_birth = new QLineEdit(centralWidget);
        input_year_of_birth->setObjectName(QStringLiteral("input_year_of_birth"));

        verticalLayout->addWidget(input_year_of_birth);

        label_year_of_death = new QLabel(centralWidget);
        label_year_of_death->setObjectName(QStringLiteral("label_year_of_death"));

        verticalLayout->addWidget(label_year_of_death);

        input_year_of_death = new QLineEdit(centralWidget);
        input_year_of_death->setObjectName(QStringLiteral("input_year_of_death"));

        verticalLayout->addWidget(input_year_of_death);

        button_scientists_to_table = new QPushButton(centralWidget);
        button_scientists_to_table->setObjectName(QStringLiteral("button_scientists_to_table"));

        verticalLayout->addWidget(button_scientists_to_table);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 945, 21));
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
        label_add_scientist->setText(QApplication::translate("MainWindow", "Add a new Scientist", 0));
        label_input_label->setText(QApplication::translate("MainWindow", "Input scientist name", 0));
        label_error_name->setText(QString());
        label_input_sex->setText(QApplication::translate("MainWindow", "Sex", 0));
        label_error_sex->setText(QString());
        label_year_of_birth->setText(QApplication::translate("MainWindow", "Year of birth", 0));
        label_error_YoB->setText(QString());
        label_year_of_death->setText(QApplication::translate("MainWindow", "Year of death", 0));
        button_scientists_to_table->setText(QApplication::translate("MainWindow", "Add to table", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
