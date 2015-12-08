#include <QCoreApplication>
#include "gui.h"
#include "manualInsertScientist.h"
#include "insertcomputer.h"
#include "connectiontodatabase.h"
#include "display.h"
#include "search.h"
using namespace std;

int main(){
    //ToDo
    //samræma kóðann -persistance
    //taka út óþarfa debug kóða og texta
    //kommenta kóðann
    //Input check fyrir ALLT input
    //Search function - Leit eftir substrings //ætti ekki að vera mál í sql :)
    //laga það sem dregin var niður í seinastu skilum
    //taka út að ID sé prentað, það er bara fyrir reference
    //Sort fall - Skúli
    //readme skrá með leiðbeiningum
    //Setja inn tengingar á milli Scientists og computers
    //Delete fall ef tími gefst
    //aukavirkni - fengum btw 7/10 auka stig í seinustu skilum, vel gert!

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
