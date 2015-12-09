#include "connectiontodatabase.h"

using namespace std;

extras::extras(){
}

void extras::searchWiki(){
    string firstname;
    string lastname;
    cout<< "Please enter a first and last name: ";
    cin >> firstname;
    cin >> lastname;

    string myUrl ="https://en.wikipedia.org/wiki/"+firstname+"_"+lastname;

    system(string("start " + myUrl).c_str());
}

void extras::searchWikiCpu(){
    string name;
    cout<< "Please enter a computer to search for: ";
    cin >> name;

    string myUrl = "https://en.wikipedia.org/wiki/"+name+"";

    system(string("start " + myUrl).c_str());
}

void extras::deleteAll(){
    QSqlDatabase db;
    QSqlQuery query(db);
    query.prepare("DELETE FROM Scientists");
    query.prepare("DELETE FROM Computers");
    query.exec();
}

