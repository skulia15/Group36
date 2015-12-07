#include "gui.h"
#include "manualInsertScientist.h"
#include "connectiontodatabase.h"
#include <QCoreApplication>
#include "display.h"
using namespace std;

struct Klasi{
    int id;
    string firstName;
    string lastName;
    string sex;
    int YoB;
    int YoD;
};

//void readFromDatabaseToVector(vector<Klasi>& viktor);
void print();

//void inputInfo(vector<Klasi>& viktor);//input into Vector
//void manualInsertToDataBase();
//void readFromDatabaseToVector(vector<Klasi>& viktor);


int main()
{
    GUI menu;
    connectionToDataBase();
    menu.displayMainMenu();

return 0;
}
