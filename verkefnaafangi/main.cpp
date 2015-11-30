#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

struct scientists{
    string firstName;
    string lastName;
    string personSex;
    int yearOfBirth;
    int yearOfDeath;
};

void callDefaultMenu(vector<scientists>& subject);
void inputInfo(vector<scientists>& subject);
void output(vector<scientists>& subject, int persons);
void print();
void search();

int main()
{
    //ToDo list
    //Check if vector pushes back values correctly.
    //Figure out how to print contents of vector.
    //Create a function to save the info into a file.
    //Print options f.ex alphabetical order
    //Create a function to remove a computer scientist.
    //Error handling.
    //Cool extra features.

    vector<scientists> subject;  //vector of persons

    callDefaultMenu(subject);

    return 0;
}

void callDefaultMenu(vector<scientists>& subject){
    char a;
    bool loop = true;

    while(loop == true){
        cout << "-----------Menu-----------";
        cout << " \n Please select a option:  "<<endl;
        cout << " \n 1. To add a computer scientist" << endl;
        cout << " 2. To print all persons" << endl;
        cout << " 3. To search" << endl;
        cout << " 4. To quit" << endl;
        cout << "--------------------------"<<endl;
        cin >> a;

        switch(a){
        case '1':
             inputInfo(subject);
             break;
        case '2':
            print();
            break;
        case '3':
            search();
           break;
         case '4':
            cout << "Quitting." << endl;
            loop = false;
            break;
         default:
            cout << "Error in command, try again." << endl << endl;
            break;
        }
     }
}

void inputInfo(vector<scientists>& subject){
    scientists scientist1;
    char answer = 0;
    int persons;
    bool error = false;
    string sex;
    char sexTemp;

    cout << "How many persons would you like to add? ";
    cin >> persons;

    for (int i = 1;i <= persons; i++){
        if (i == 0){
            cout << "\nEnter the info for the first person: " << endl;}
        else {
            cout << "Enter the info for the next person: " << endl;}

        cout << "Person's first name: ";
        cin >> scientist1.firstName;
        cout << "Last name: ";
        cin >> scientist1.lastName;
        cout << endl;

        do{
            cout << "Sex: (m/f) " ;
            cin >> sexTemp;
            if (sexTemp == 'm'){ sex = "Male"; error = true;}
            else if (sexTemp == 'f'){ sex = "Female"; error = true;}
            else cout << "Input was invalid try again." << endl;
        } while (error == false);
        scientist1.personSex = sex;
        cout << endl;

        cout << "Year of Birth: ";
        cin >> scientist1.yearOfBirth;
        cout << endl;

        error = false;
        do{
            cout << "Is the person still alive? (y/n) ";
            cin >> answer;
            if (answer == 'n'||answer == 'N'){
                cout << "\nYear of Death: ";
                cin >> scientist1.yearOfDeath;
                error = true;}
            else if (answer == 'y'||answer == 'Y'){
                scientist1.yearOfDeath = 0;
                error = true;}
            else cout << "Input was invalid try again." << endl;
        } while (error == false);
        cout << endl;

        subject.push_back(scientist1);  //The struct is pushed on to the vector
    }
    output(subject, persons);
}

void output(vector<scientists>& subject, int persons){
    ofstream myfile;
    myfile.open("save.txt", ios::out | ios::app); //For adding without overwriting
    if (myfile.is_open()){
        for (int i = 0; i < persons; i++){  //Needs to be modified, not adding persons correctly. 1 off error.
            myfile << "Name: " << subject[i].firstName;
            myfile << " " << subject[i].lastName << endl;
            myfile << "Sex: "<< subject[i].personSex << endl;
            myfile << "Year of birth: " << subject[i].yearOfBirth << endl;
            if(subject[i].yearOfDeath == 0){  //if still alive then marks as "Still Alive"
                myfile << subject[i].firstName << " " << subject[i].lastName << " is still alive." << endl;}
            else {
                myfile << "Year of death: " << subject[i].yearOfDeath << endl;}
            myfile << endl;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void print(){
    ifstream myfile;
    string line;
    myfile.open("save.txt");
    if (myfile.is_open()){
    cout << "------Displaying Persons------" << endl;
    while (getline (myfile,line)){
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";
}

void search() //þarf að laga til, er ekki að prenta rétt út.
{
    ifstream myfile;
    string find, temp="";
    bool found = 0;
    myfile.open("save.txt");

    if(myfile.fail()){
        cout << "Unable to open file";
        exit(1);
    }

    cout << "Please enter search conditions: ";
    cin >> find;

    while(!myfile.eof()){
        getline(myfile, temp);
        for(int i = 0; i < find.size(); i++){
            if(temp[i] == find[i]){
                found = 1;
            }
            else{
                found = 0;
                break;
            }
        }
        if(found){
            for(int i = find.size()+1; i < temp.size(); i++)
                cout << temp[i];
            break;
        }
    }
    if(myfile.eof() && (!found)){
        cout << "Found nothing.";
    }

    myfile.close();
}

