#include "connectiontodatabase.h"

bool isValid(string myString);

Scientists::Scientists(){
   firstName = "";
   lastName = "";
   sex = "";
   YoB = 0;
   YoD = 0;
};

void Scientists::manualInput(){
    bool error = false;
    bool error2 = true;
    char persons;
    char temp;

    QSqlDatabase db;
    QSqlQuery query(db);

    while(error == false){
        cout << "How many persons would you like to add? ";
        cin >> persons;
        if (isalpha(persons)){
            cout << "Error in input, try again." << endl;
        }
        else
            error = true;
    }

    for (int i = 1;i <= persons - '0'; i++){
        if (i == 1){
            cout << "Please use letters from the English alphabet exclusively. ";
            cout << "\nEnter the info for the first person: " << endl << endl;
           }
        else {
            cout << "Enter the info for the next person: " << endl;}
        error = false;

        while(error == false){
            cout << "First name: ";
            cin >> firstName;
            error = isValid(firstName);
        }
        error = false;
        while(error == false){
            cout << "Last name: ";
            cin >> lastName;
            error = isValid(lastName);
        }
        while (error2 == true){
            cout << "Sex: (m/f) ";
            cin >> temp;
            if (temp == 'm'||temp == 'M'){
                sex = "Male"; error2 = false;}
            else if (temp == 'f'||temp == 'F'){
                sex = "Female"; error2 = false;}
            else
            cout << "Input was invalid try again." << endl;}

        cout << "Year of Birth: ";
        cin >> YoB;

        error = false;
        do{
            cout << "Is the person still alive? (y/n) ";
            cin >> temp;
            if (temp == 'n'||temp == 'N'){
                cout << "Year of Death: ";
                cin >> YoD;
                while(YoB > YoD){
                    cout << "The person can not have died before its birth, please try again" << endl;
                    cout << "Year of Death: ";
                    cin >> YoD;}
                cout << endl;
                error = true;}
            else if (temp == 'y'||temp == 'Y'){
                YoD = 0;
                cout << endl;
                error = true;}
            else cout << "Input was invalid try again." << endl;
        } while (error == false);

        query.prepare("INSERT INTO Scientists (firstName, lastName, sex, YoB, YoD) "
        "VALUES (:firstName, :lastName, :sex, :YoB, :YoD)");
        query.bindValue(":id", QString::fromStdString(id));
        query.bindValue(":firstName", QString::fromStdString(firstName));
        query.bindValue(":lastName",  QString::fromStdString(lastName));
        query.bindValue(":sex",  QString::fromStdString(sex));
        query.bindValue(":YoB",  YoB);
        query.bindValue(":YoD",  YoD);
        if(query.exec()){
            cout << "========== Successfully entered into the database ==========" << endl;
        }else cout << "========== Error entering info to the database ==========" << endl;
    }
}

bool isValid(string myString){
    for(unsigned int i = 0; i < myString.length(); i++){
        if(!isalpha(myString[i])){
            cout << "Input was invalid. The name cannot contain numbers or symbols. Try again.\n";
            return false;
        }
    }
    return true;
}

void Scientists::deleteScientist(){
    QSqlDatabase db;
    QSqlQuery query(db);
    int tempID;

    cout << "Enter the scientist ID: ";
    cin >> tempID;

    QString toDelete = QString::number(tempID);

    query.prepare("DELETE FROM Scientists WHERE id = "+toDelete+";");
    query.exec();
     if(query.exec()){
         cout << "Scientist with ID number " << tempID <<" was deleted." << endl;
     }
     else
         cout << "No scientist has that ID." << endl;

}

