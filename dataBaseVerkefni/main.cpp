#include "connectiontodatabase.h"


int main(){
    //ToDo
    //Setja inn tengingar á milli Scientists og computers
    //Hver persóna getur verið tengd mörgum tölvum, Hver tölva getur verið tengt mörgum persónum
    //Þessar tengingar þarf að vera hægt að skoða og viðhalda, - display fall fyrir þá sem komu að gerð tölvu og öfugt
    //kommenta kóðann
    //Search function - Leit eftir substrings //ætti ekki að vera mál í sql :)
    //readme skrá með leiðbeiningum
    //aukavirkni - fengum btw 7/10 auka stig í seinustu skilum, vel gert!

    GUI menu;
    connectionToDataBase connect;

    connect.connect();
    menu.displayMainMenu();

    return 0;
}



