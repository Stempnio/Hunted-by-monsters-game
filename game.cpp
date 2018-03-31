#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;
void type_good();
void draw(char field[][30], int& score, int& start);
void menu(char field[][30], int& score);
void basic_field(char field[][30]);
void player_movement(char field[][30], int& p_x, int& p_y, int& score);
void monster_movement(char field[][30], int m_x[100], int m_y[100], int& p_x, int& p_y,  int& monster_counter);
void end_check(char field[][30], int& p_x, int& p_y, int m_x[100], int m_y[100],  int& monster_counter, bool& again);
void tutorial(char field[][30], bool& exit_loop, int& score);
void draw_position(int& p_x, int& p_y, int m_x[100], int m_y[100]); // do sprawdzania bledow
void continuation(bool& again);
void score(int& score);

int main()
{
    srand(time(NULL));
    char field[20][30];
    int p_x;
    int p_y;
    int m_x[100];
    int m_y[100];
    int monster_counter;
    bool again;
    int score;
    int start;
    while(1)
    {
        for(int i=0; i<100; i++)
        {
            m_x[i] = rand()%30;
            m_y[i] = 0;
        }
        menu(field, score);
        monster_counter=1;
        p_x=15;
        p_y=17;
        again = true;
        score = 0;
        start = 0;
        while(again == true)
        {
            //draw_position(p_x, p_y, m_x, m_y);
            draw(field, score, start);
            monster_movement(field, m_x, m_y, p_x, p_y, monster_counter);
            player_movement(field, p_x, p_y, score);
            Sleep(10);
            draw(field, score, start);
            end_check(field, p_x, p_y, m_x, m_y, monster_counter, again);
        }
    }

}

void menu(char field[][30], int& score)
{
    system("cls");
    int choice;
    for(int i=0; i<30; i++)
        cout << '$';

    cout << endl << endl;
    cout << "       START GAME - [1]" << endl;
    cout << endl;
    cout << "       TUTORIAL - [2]" << endl;
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
        case 50:
            tutorial(field, exit_loop, score);
            break;
        case 51:
                cout << "GOODBYE!";
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
            field[i][j]=' ';
}
void draw(char field[][30], int& score1, int& start)
{
    if(start == 0)
        field[17][15] = 'P';
    start++;
    system("cls");
    cout << "   ";
    for(int i=0; i<30; i++)
        cout << '$';

    cout << endl;

    for(int i=0; i<20; i++)
    {
        cout << endl;
        cout << "$   ";
        for(int j=0; j<30; j++)
                cout << field[i][j];

        cout << "  $";
    }

    cout << endl << endl;
    cout << "   ";

    for(int i=0; i<30; i++)
        cout << '$';

    cout << endl << endl;
    score(score1);
}

void draw_position(int& p_x, int& p_y, int m_x[100], int m_y[100]) // do sprawdzania bledow
{
    cout << endl << "p x " << p_x << " p y " << p_y << "m x " << m_x[0] << " m y " << m_y[0] << endl;
    Sleep(1000);
}

void player_movement(char field[][30], int& p_x, int& p_y, int& score)
{
    if(_kbhit())
    {
    switch(getch())
    {
    case 119: // w
        if(p_y>0)
        {
            field[p_y][p_x] = ' ';
            p_y--;
            field[p_y][p_x]= 'P';
        }
        score++;
        break;
    case 115: // s
        if(p_y<17) // 19 ale zanika przez m
        {
            field[p_y][p_x] = ' ';
            p_y++;
            field[p_y][p_x]= 'P';
        }
        score++;
        break;
    case 97: // a
        if(p_x>0)
        {
            field[p_y][p_x] = ' ';
            p_x--;
            field[p_y][p_x]= 'P';
        }
        score++;
        break;
    case 100: // d
        if(p_x<29)
        {
            field[p_y][p_x] = ' ';
            p_x++;
            field[p_y][p_x]= 'P';
        }
        score++;
        break;
    default: // popracuj
        break;
    }
    }
}

void monster_movement(char field[][30], int m_x[100], int m_y[100], int& p_x, int& p_y, int& monster_counter) // do zoptymalizowania
{
    for(int i=0; i<monster_counter; i++)
    {
        if(m_y[i]<19)
        {
            field[m_y[i]][m_x[i]] = ' ';
            m_y[i]++;
            field[m_y[i]][m_x[i]] = '+';
        }
        else
            field[m_y[i]][m_x[i]] = ' ';
    }

    if(monster_counter<100)
        monster_counter++;
}

void end_check(char field[][30], int& p_x, int& p_y, int m_x[100], int m_y[100], int& monster_counter, bool& again)
{
    for(int i=0; i<monster_counter+1; i++)
    {
        if( (m_y[i] == p_y && m_x[i] == p_x-1) || (m_y[i] == p_y && m_x[i] == p_x+1) || (m_y[i] == p_y+1 && m_x[i] == p_x) || (m_y[i] == p_y-1 && m_x[i] == p_x))
        {
            cout << endl << endl << "YOU'VE GOT CAUGHT BY MONSTER" << endl;
            Sleep(1000);
            continuation(again);
        }
    }
}

void continuation(bool& again)
{
    int choice;
    cout << endl << "GO BACK TO MENU [1]" << endl << "EXIT GAME [2]" << endl;
    while(again == true)
    {
    choice = getch();

        switch(choice)
        {
        case 49:
            again = false;
            break;
        case 50:
            cout << "GOODBYE!";
            exit(0);
            break;
        default:
            cout << "WRONG OPTION, PLEASE ENTER AGAIN" << endl;
            break;
        }
    }
}

void tutorial(char field[][30], bool& exit_loop, int& score)
{
    system("cls");
    for(int i=0; i<30; i++)
        cout << '$';

    cout << endl << endl;
    cout << "   IN THIS GAME YOU HAVE TO RUNAWAY FROM MONSTERS (+)" << endl;
    cout << "   TO MOVE PRESS W,S,A,D" << endl;
    cout << "   YOU CAN AVOID MONSTERS BY GOING ONTO THEM IN PROPER WAY" << endl;
    cout << "   GO BACK TO MENU [1]" << endl << endl;

    for(int i=0; i<30; i++)
        cout << '$';

    cout << endl << "TYPE OPTION: ";

    int go_back;
    bool exit_loop1 = true;
    do
    {
        go_back = getch();
        switch(go_back)
        {
            case 49:
                exit_loop1 = false;
                exit_loop = true;
                break;
            default:
                cout << "WRONG OPTION, PLEASE ENTER AGAIN" << endl;
                break;
        }
    }while(exit_loop1==true);

    menu(field, score);
}

void score(int& score)
{
    cout << endl << "SCORE: " << score;
}
