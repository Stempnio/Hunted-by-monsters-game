#include <iostream>
#include <windows.h>

using namespace std;
void type_good();
void draw(char field[][30]);
void menu(char field[][30]);
void basic_field(char field[][30]);
void settings();


int main()
{
    char field[20][30];
    menu(field);
    draw(field);

}

void menu(char field[][30])
{

int choice;
    for(int i=0; i<30; i++)
        cout << '$';
    cout << endl;
    cout << "       START GAME - [1]" << endl;
    cout << endl;
    cout << "       SETTINGS - [2]" << endl;
    cout << endl;
    cout << "       EXIT - [3]" << endl;
    cout << endl;
    for(int i=0; i<30; i++)
        cout << '$';
    cout << endl << endl << "TYPE OPTION (1-3): ";
    cin >> choice;
    switch(choice)
    {
        case 1: draw(field); break;
        //case 2: settings(); break;
        case 3:
                cout << "Goodbye!";
                exit(0);
        default:
                cout << "WRONG OPTION, PLEASE ENTER AGAIN" << endl;
                break;
        }
}
void basic_field(char field[][30])
{
    for(int i=0; i<20; i++)
        for(int j=0; j<30; j++)
            field[i][j]='.';
}
void draw(char field[][30])
{
    system("cls");

    for(int i=0; i<20; i++)
    {
        cout << endl;
        for(int j=0; j<30; j++)
            cout << field[i][j];
    }

    for(int i=0; i<20; i++)
        for(int j=0; j<30; j++)
            field[i][j]='.';
}

