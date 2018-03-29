#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
void type_good();
void draw(char field[][30]);
void menu(char field[][30]);
void basic_field(char field[][30]);
void movement(char field[][30]);
void end_check();
void settings();


int main()
{
    char field[20][30];
    int player_position[20][30];
    int p_x;
    int p_y;

    menu(field);
    //draw(field);
    //while()

}

void menu(char field[][30])
{
    system("cls");
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
    choice = getch();
    switch(choice)
    {
        case 49: basic_field(field); break;
        //case 50: settings(); break;
        case 51:
                cout << "Goodbye!";
                exit(0);
                break;
        default:
                cout << "WRONG OPTION, PLEASE ENTER AGAIN" << endl;
                break;
        }
}
void basic_field(char field[][30])
{
    system("cls");

    for(int i=0; i<20; i++)
        for(int j=0; j<30; j++)
            field[i][j]='.';

    field[18][15] = 'P';

    for(int i=0; i<20; i++)
    {
        cout << endl;
        for(int j=0; j<30; j++)
            cout << field[i][j];
    }

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
}

void movement(char field[][30])
{
    int wsad;
    wsad = getch();

    switch(wsad)
    {
    case 119:
        field
        break;
    case
    }
}
