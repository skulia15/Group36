#include "connectiontodatabase.h"


int main(){
    //ToDo
    //Setja inn tengingar á milli Scientists og computers
    //Hver persóna getur verið tengd mörgum tölvum, Hver tölva getur verið tengt mörgum persónum
    //Þessar tengingar þarf að vera hægt að skoða og viðhalda, - display fall fyrir þá sem komu að gerð tölvu og öfugt
    //kommenta kóðann
    //readme skrá með leiðbeiningum

    GUI menu;
    connectionToDataBase connect;

    connect.connect();
    menu.displayMainMenu();

    return 0;
}



