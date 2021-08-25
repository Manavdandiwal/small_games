#include <iostream>
#include <conio.h>
#include "gotoxy.h"
using namespace std;
#define N 9

bool valid_col(int num, int arr[N][N], int row)
{
    for (int i = 0; i < N; i++)
        if (arr[row][i] == num)
            return false;

    return true;
}

bool valid_row(int num, int arr[N][N], int col)
{
    for (int i = 0; i < N; i++)
        if (arr[i][col] == num)
            return false;

    return true;
}

bool valid_box(int num, int arr[N][N], int row, int col)
{
    int R = 3 * (row / 3);
    int C = 3 * (col / 3);

    for (int i = R; i < R + 3; i++)
    {
        for (int j = C; j < C + 3; j++)
        {
            if (arr[i][j] == num)
                return false;
        }
    }
}
bool is_valid_position(int num, int row, int col, int arr[N][N])
{
    return valid_col(num, arr, row) && valid_row(num, arr, col) && valid_box(num, arr, row, col);
}

bool solve_suduko(int arr[N][N], int row = 0, int col = 0)
{
    if (row == 8 && col == 9)
        return true;

    if (col == 9)
    {
        row++;
        col = 0;
    }

    if (arr[row][col] > 0)
        return solve_suduko(arr, row, col + 1);

    for (int i = 1; i <= 9; i++)
    {
        if (is_valid_position(i, row, col, arr))
        {
            arr[row][col] = i;

            if (solve_suduko(arr, row, col + 1))
                return true;

            arr[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    system("cls");
    int suduko[9][9];

    cout << "Enter the suduko table(spaces are to be represented by 0)" << endl
         << endl;
    ;

    print_table();

    int x = 1, y = 2;
    for (int i = 1; i <= 9; i++)
    {
        x = 1;
        for (int j = 1; j <= 9; j++)
        {
            gotoxy(x, y);
            cin >> suduko[i - 1][j - 1];
            x += 2;

            if (j == 3 || j == 6)
                x += 2;
        }

        y += 1;

        if (i == 3 || i == 6)
            y += 1;
    }
    cout << endl;
    print_table();

    y = 14;
    x = 1;
    if (solve_suduko(suduko))
    {
        for (int i = 0; i < N; i++)
        {
            x = 1;

            for (int j = 0; j < N; j++)
            {
                gotoxy(x, y);
                cout << suduko[i][j];
                x += 2;

                if (j == 2 || j == 5)
                    x += 2;
            }

            y++;

            if (i == 2 || i == 5)
                y++;
        }
    }

    else
        cout << "No solution" << endl;
}