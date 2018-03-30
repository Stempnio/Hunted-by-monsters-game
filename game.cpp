#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;
void type_good();
void draw(char field[][30]);
void menu(char field[][30]);
void basic_field(char field[][30]);
void player_movement(char field[][30], int& p_x, int& p_y);
void monster_movement(char field[][30], int m_x[100], int m_y[100], int& p_x, int& p_y,  int& monster_counter);
void end_check(char field[][30], int& p_x, int& p_y, int m_x[100], int m_y[100],  int& monster_counter);
void score();
void settings();
void draw_position(int& p_x, int& p_y, int m_x[100], int m_y[100]);

int main()
{
    srand(time(NULL));
    char field[20][30];
    int p_x;
    int p_y;
    int m_x[100];
    int m_y[100];
    for(int i=0; i<100; i++)
    {
    m_x[i] = rand()%30;
    m_y[i] = 0;
    }
    menu(field);
    int monster_counter=1;
    p_x=15;
    p_y=17;
    while(1)
    {
    //end_check(field, p_x, p_y, m_x, m_y, monster_counter);
    //draw_position(p_x, p_y, m_x, m_y);
    draw(field);
    player_movement(field, p_x, p_y);
    draw(field);
    monster_movement(field, m_x, m_y, p_x, p_y, monster_counter);
    draw(field);
    }

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
    bool exit_loop = false;
    do
    {
    choice = getch();
    switch(choice)
    {
        case 49:
            basic_field(field);
            exit_loop = true;
            break;

        //case 50: settings(); break;
        case 51:
                cout << "Goodbye!";
                exit(0);
                break;
        default:
                cout << "WRONG OPTION, PLEASE ENTER AGAIN" << endl;
                break;
        }
    }while(exit_loop==false);
}
void basic_field(char field[][30])
{
    system("cls");

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

}

void draw_position(int& p_x, int& p_y, int m_x[100], int m_y[100])
{
    cout << endl << "p x " << p_x << " p y " << p_y << "m x " << m_x[0] << " m y " << m_y[0] << endl;
    Sleep(1000);
}

void player_movement(char field[][30], int& p_x, int& p_y)
{
    int wsad;
    wsad = getch();

    switch(wsad)
    {
    case 119: // w
        if(p_y>0)
        {
        field[p_y][p_x] = '.';
        p_y--;
        field[p_y][p_x]= 'P';
        }
        break;
    case 115: // s
        if(p_y<17) // 19 ale zanika przez m
        {
        field[p_y][p_x] = '.';
        p_y++;
        field[p_y][p_x]= 'P';
        }
        break;
    case 97: // a
        if(p_x>0)
        {
        field[p_y][p_x] = '.';
        p_x--;
        field[p_y][p_x]= 'P';
        }
        break;
    case 100: // d
        if(p_x<29)
        {
        field[p_y][p_x] = '.';
        p_x++;
        field[p_y][p_x]= 'P';
        }
        break;
    default:
        break;
    }
}

void monster_movement(char field[][30], int m_x[100], int m_y[100], int& p_x, int& p_y, int& monster_counter)
{
    if(monster_counter<100)
    {
    for(int i=0; i<monster_counter; i++)
    {
        if(m_y[i]<19)
        {
            field[m_y[i]][m_x[i]] = '.';
            m_y[i]++;
            field[m_y[i]][m_x[i]] = 'M';
        }
        else
            field[m_y[i]][m_x[i]] = '.';

    }
    monster_counter++;
    }
    else
    {
        for(int i=0; i<monster_counter; i++)
        {

            if(m_y[i]<19)
            {
                field[m_y[i]][m_x[i]] = 'M';
                field[m_y[i]-1][m_x[i]] = '.';
                m_y[i]++;
            }
            else
                field[m_y[i]-1][m_x[i]] = '.';
        }
    }

}

void end_check(char field[][30], int& p_x, int& p_y, int m_x[100], int m_y[100], int& monster_counter)
{
    for(int i=0; i<monster_counter+1; i++)
    {
        if( (m_y[i] == p_y && m_x[i] == p_x-1) || (m_y[i] == p_y && m_x[i] == p_x+1) || (m_y[i] == p_y+1 && m_x[i] == p_x) || (m_y[i] == p_y-1 && m_x[i] == p_x) )
        {
            cout << "kuniec" << endl;
            exit(0);
        }
    }
}


