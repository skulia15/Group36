#include <windows.h>
#include <iostream>
#include <extras.h>
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
