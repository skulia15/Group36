#include <person.h>

using namespace std;

int main()
{
    person person1;

    cout << "Enter your persons info." << endl;
    person1.inputName();
    person1.inputSex();
    person1.inputYoB();
    person1.inputYoD();

    cout << "Saelir" << endl;

    return 0;
}

