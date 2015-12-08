#include "connectiontodatabase.h"

display::display(){
}

void display::showResult(string command){
    QSqlDatabase db;
    QSqlQuery query(db);

    string querySort = command;
    if(query.exec(QString(querySort.c_str()))){
       cout << "========== The scientist table sorted successfully! =========="<< endl;}
    else {cout<< "========== Scientist table was NOT sorted :( ==========" << endl;}

    int idName = query.record().indexOf("id");
    while (query.next())
    {
       int id = query.value("id").toUInt();
       QString firstName = query.value("firstName").toString();
       QString lastName = query.value("lastName").toString();
       QString sex = query.value("sex").toString();
       int YoB = query.value("YoB").toUInt();
       int YoD = query.value("YoD").toUInt();

       cout << "Scientist ID: ";
       qDebug() << id;
       cout << "Name: ";
       qDebug() << qPrintable(firstName)  << qPrintable(lastName) ;
       cout << "Sex: ";
       qDebug() << qPrintable(sex);
       cout << "Year of Birth: ";
       qDebug() << YoB;
       cout << "Year of Death: ";
       if (YoD == 0){
           cout << "Still Alive" << endl;
       }
       else{
           qDebug() << YoD;
       }
       cout << endl;
    }
}



void display::cpuShowResult(string command){// þarf kanski að finna betri texta
    QSqlDatabase db;
    QSqlQuery query(db);

    string querySort = command;

    if(query.exec(QString(querySort.c_str()))){
       cout << "========== The Computer table sorted successfully! =========="<< endl;}
    else {cout<< "========== Computer table was NOT sorted :( ==========" << endl;}

    int idName = query.record().indexOf("id");
    while (query.next())
    {

       QString cpuName = query.value("cpuName").toString();
       QString cpuType = query.value("cpuType").toString();
       QString built = query.value("built").toString();
       int yb = query.value("yearBuilt").toUInt();

       cout << "Name: ";
       qDebug() << qPrintable(cpuName);
       cout << "Type: ";
       qDebug() << qPrintable(cpuType);
       cout << "Was it buit?: ";
       qDebug() << qPrintable(built);
       cout << "Year Built: ";
       qDebug() << yb;
       cout << endl;
     }
}


