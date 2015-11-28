#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ostream>

using namespace std;

struct scientists{
    string firstName;
    string lastName;
    char personSex;
    int yearOfBirth;
    int yearOfDeath;
};

void callDefaultMenu(vector<scientists>& subject);
void inputInfo(vector<scientists>& subject);
void output(vector<scientists>& subject);

int main()
{ 
    //ToDo list
    //Check if vector pushes back values correctly
    //Figure out how to print contents of vector
    //Create a function to save the info into a file.
    //Create function to read from file. - without everwriting
    //Print options f.ex alphabetical order
    //Implement a search function
    //Error handling
    //Cool extra features

    vector<scientists> subject;

    subject.push_back(scientists()); //default constructor
    output(subject);

    callDefaultMenu(subject);

    for(unsigned int i=0; i < subject.size(); ++i)
      //cout << subject[i] << ' ';    þarf að yfirskifa << operator til þess að fá til að skrifa út?
    return 0;
}

void callDefaultMenu(vector<scientists>& subject){
    char a;
    bool loop = true;

    while(loop == true)
    {
        cout << "-----------Menu-----------"<<endl;
        cout << endl;
        cout << " Please select a option  "<<endl;
        cout << " 1. to add a person" << endl;
        cout << " 2. to print all persons" << endl;
        cout << " 3. to search" << endl;
        cout << " 4. to quit" << endl;
        cout << endl;
        cout << "--------------------------"<<endl;
        cin >> a;

        switch(a){
        case '1':
             inputInfo(subject);
             break;
        case '2':
            //print();
            break;
        case '3':
           //search();
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

    cout << "How many persons would you like to add? ";
    cin >> persons;

    for (int i = 0;i < persons; i++){
        if (i == 0){
            cout << "Enter the info for the first person: " << endl;
        }
        else {
            cout << "Enter the info for the next person: " << endl;
        }

        cout << "Person's first name: ";
        cin >> scientist1.firstName;
        cout << " Last name: ";
        cin >> scientist1.lastName;
        cout << endl;

        cout << "Sex: (m/f) " ;
        cin >> scientist1.personSex;
        cout << endl;

        cout << "Year of Birth: ";
        cin >> scientist1.yearOfBirth;
        cout << endl;

        cout << "Is the person still alive? (y/n) ";
        cin >> answer;

        if (answer == 'n'||answer == 'N'){
            cout << "\nYear of Death: ";
            cin >> scientist1.yearOfDeath;
        }
        cout << endl;

        subject.push_back(scientist1);
        output(subject);
    }
}

void output(vector<scientists>& subject){ //drag að ofstream/ifstream falli
    ifstream document;
    ofstream writeToFile;
    document.open("list.txt");
    writeToFile.open("list.txt");
    writeToFile.close();
    document.close();


}

