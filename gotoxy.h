#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void print_table()
{
    std::cout << "       |       |       " << endl;
    std::cout << "       |       |       " << endl;
    std::cout << "       |       |       " << endl;
    std::cout << "-----------------------" << endl;
    std::cout << "       |       |       " << endl;
    std::cout << "       |       |       " << endl;
    std::cout << "       |       |       " << endl;
    std::cout << "-----------------------" << endl;
    std::cout << "       |       |       " << endl;
    std::cout << "       |       |       " << endl;
    std::cout << "       |       |       " << endl;
}