#include "connectiontodatabase.h"


int main(){
    //ToDo
    //Setja inn tengingar á milli Scientists og computers
    //Hver persóna getur verið tengd mörgum tölvum, Hver tölva getur verið tengt mörgum persónum
    //Þessar tengingar þarf að vera hægt að skoða og viðhalda, - display fall fyrir þá sem komu að gerð tölvu og öfugt
    //samræma kóðann -persistance
    //passa að það sé ekki prentað 0 þegar einhver er ekki dáinn eða þegar tölva  var ekki byggð
    //taka út óþarfa debug kóða og texta
    //kommenta kóðann
    //Input check fyrir ALLT input
    //Search function - Leit eftir substrings //ætti ekki að vera mál í sql :)
    //laga það sem dregin var niður í seinastu skilum
    //taka út að ID sé prentað, það er bara fyrir reference
    //Sort fall - Skúli
    //readme skrá með leiðbeiningum
    //Delete fall ef tími gefst
    //aukavirkni - fengum btw 7/10 auka stig í seinustu skilum, vel gert!

    GUI menu;
    connectionToDataBase connect;

    connect.connect();
    menu.displayMainMenu();

    return 0;
}



