#include <QCoreApplication>
#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "display.h"
#include "search.h"
using namespace std;

int main()
{
    GUI menu;
    connectionToDataBase connect;
    connect.connect();
    menu.displayMainMenu();

return 0;
}


/*#include <QCoreApplication>
    #include <windows.h>
    #include <iostream>
    using namespace std;

    int main()
    {
        string firstname;
        string lastname;

        cout<< "Would you like more info about your favorite computer scientist?"<<endl;
        cout<< "Please enter his first name:";
        cin >> firstname;
        cout<<"Plese enter his last name:";
        cin >> lastname;
        string myUrl ="https://en.wikipedia.org/wiki/"+firstname+"_"+lastname;


        system(std::string("start " + myUrl).c_str());

        return 0;
    }*/
