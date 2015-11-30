#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct scientists{
    string firstName;
    string lastName;
    string personSex;
    string yearOfBirth;
    string yearOfDeath;
};

void callDefaultMenu(vector<scientists>& subject);
void inputInfo(vector<scientists>& subject);
void output(vector<scientists>& subject, int persons);
void print();
void search();
void readFromFileToVector(vector<scientists>& subject);
void searchInVector(vector<scientists>& subject);
<<<<<<< HEAD

=======
<<<<<<< HEAD
void deleteVector(vector<scientists>& subject);
=======
>>>>>>> 52862c1a2023230e66a973292c24eeb84dfe8084
>>>>>>> refs/remotes/origin/master
>>>>>>> ae6604bccef2bb29c7440a69af4f1d4c1a621582

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

    readFromFileToVector(subject);

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
            searchInVector(subject);
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
                scientist1.yearOfDeath = " ";
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
            myfile << subject[i].firstName << endl;
            myfile << subject[i].lastName << endl;
            myfile << subject[i].personSex << endl;
            myfile << subject[i].yearOfBirth << endl;
            if(subject[i].yearOfDeath == " "){  //if still alive then marks as "Still Alive"
                myfile << "still alive." << endl;}
            else {
                myfile << subject[i].yearOfDeath << endl;}
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

void search(); //þarf að laga til, er ekki að prenta rétt út.
/*void search()
{
    ifstream myfile;
    string find, temp="";
    bool found = 0;
    myfile.open("save.txt");

    if(myfile.fail()){
        cout << "Unable to open file";
        exit(1);
    }

    cout << "Please enter two or more characters to search for (case sensitive): ";
    cin >> find;
    cout << endl;

    while(!myfile.eof()){
        getline(myfile, temp);
        for(unsigned int i = 0; i < find.size(); i++){
            if(temp[i] == find[i]){
                found = 1;
            }
            else{
                found = 0;
                break;
            }
        }
        if(found){

            for(unsigned int i = find.size()+1; i < temp.size(); i++)
            for(int i = 0; i < temp.size()-16; i++)

                cout << temp[i];
                cout << endl;
            break;
        }
    }
    if(myfile.eof() && (!found)){
        cout << "Found nothing." << endl;
    }

    myfile.close();
}*/

void searhInVector(vector<scientists>& subject){// Search function
    char a;
    bool loop = true;
    string searchFirstName;
    string searchLastName;
    int searchBirthYear;

    while(loop == true){
        cout << "-----------Menu-----------";
        cout << " \n Please select a search option:  "<<endl;
        cout << " \n 1. To search by Firstname" << endl;
        cout << " 2. To search by Lastname" << endl;
        cout << " 3. To search by Birthyear" << endl;
        cout << " 4. To quit" << endl;
        cout << "--------------------------"<<endl;
        cin >> a;

        switch(a){ //Runs through vector and prints out the locations where "i" equals name provided
        case '1':

            cout<<"Please enter a firstname to search for"<<endl;
            cin>> searchFirstName;
            for(unsigned int i=0; i<subject.size(); i++)
            {
                if(subject.at(i).firstName == searchFirstName){
                    cout<< subject.at(i).firstName<<" "
                       <<subject.at(i).lastName<<" "
                       << subject.at(i).personSex<<" "
                       << subject.at(i).yearOfBirth<<" "
                       << subject.at(i).yearOfDeath<<endl;
                }else{cout<<"Sorry the firstname "<< searchFirstName<<" did not match any firstname in database. \n";}
            }
             break;

        case '2': //Runs through vector and prints out the locations where "i" equals lastname provided
            cin>> searchLastName;
            for(unsigned int i=0; i<subject.size(); i++)
            {
                if(subject.at(i).lastName == searchLastName){
                    cout<< subject.at(i).lastName<<" "
                       <<subject.at(i).firstName<<" "
                       << subject.at(i).personSex<<" "
                       << subject.at(i).yearOfBirth<<" "
                       << subject.at(i).yearOfDeath<<endl;
                }else{cout<<"Sorry the lastname"<< searchLastName<<" did not match any name in database. \n";}

            }
            break;

        case '3': //Runs through vector and prints out the locations where "i" equals birthday provided.
            cin >> searchBirthYear;
            for(unsigned int i = 0; i < subject.size(); i++){
                if(subject.at(i).yearOfBirth == searchBirthYear){
                    cout << subject.at(i).lastName<<" "
                       << subject.at(i).firstName<<" "
                       << subject.at(i).personSex<<" "
                       << subject.at(i).yearOfBirth<<" "
                       << subject.at(i).yearOfDeath<<endl;
                } else{ cout<<"Sorry according to our records nobody was born in "<< searchBirthYear <<endl;}
            }
           break;

         case '4':
            cout << "Going back to Main menu." << endl;
            loop = false;
            break;

void readFromFileToVector(vector<scientists>& subject){
    ifstream myfile;
    scientists scientist1;
    string line;

    myfile.open("save.txt");

        while (getline (myfile,line)){
            istringstream iss(line);
            string first, last, sex, YoB, YoD;

            if (!(iss >> first >> last >> sex >> YoB >> YoD)) { break; }

            scientist1.firstName = first;
            scientist1.lastName = last;
            scientist1.personSex = sex;
            scientist1.yearOfBirth = YoB;
            scientist1.yearOfDeath = YoD;
            cout << scientist1.firstName << scientist1.lastName << scientist1.personSex << scientist1.yearOfBirth << scientist1.yearOfDeath;
            subject.push_back(scientist1);
        }

   // cout <<  subject[0].firstName << endl;
  //  cout <<  subject[0].lastName << endl;
  //  cout << subject[0].personSex << endl;
    myfile.close();
    cout << scientist1.firstName << scientist1.lastName << scientist1.personSex << scientist1.yearOfBirth << scientist1.yearOfDeath;
  }

  //else cout << "Unable to open file";
//}
         default:
            cout << "Error in command, try again." << endl << endl;
            break;
        }
     }
}
