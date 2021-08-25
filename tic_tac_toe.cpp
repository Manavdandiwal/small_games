#include <iostream>
using namespace std;
#define N 3

//check if game has ended
bool is_won(char arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
            return true;

        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
            return true;
    }

    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        return true;

    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        return true;

    return false;
}

bool first_player_turn(int position, char arr[N][N])
{
    char place_holder = 'X';
    position--;
    int row = position / 3;
    int col = position % 3;

    if (arr[row][col] == position + 1 + '0')
    {
        arr[row][col] = place_holder;
        return true;
    }

    return false;
}

bool second_player_turn(int position, char arr[N][N])
{
    char place_holder = 'O';
    position--;
    int row = position / 3;
    int col = position % 3;

    if (arr[row][col] == position + 1 + '0')
    {
        arr[row][col] = place_holder;
        return true;
    }

    return false;
}

void print_table(char arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " | ";
        }
        cout << "\b\b" << endl;
    }
}

void play_game(char arr[N][N])
{
    system("cls");
    static int moves = 0;
invalid_move_player_one:
    print_table(arr);
    int pos;
    cout << "Player 1 : " << endl;
    cout << "Enter position you want to place your character : ";
    cin >> pos;
    if (!first_player_turn(pos, arr))
    {
        system("cls");
        cout << "Invalid move player one" << endl
             << "Please enter the valid position" << endl;

        goto invalid_move_player_one;
    }
    moves++;
    if (is_won(arr))
    {
        system("cls");
        print_table(arr);
        cout << "Player One Wins" << endl;
        return;
    }

    if (moves == 9)
    {
        system("cls");
        print_table(arr);
        cout << "Match Draw" << endl;
        return;
    }

    system("cls");
invalid_move_player_two:
    print_table(arr);
    cout << "Player 2 : " << endl;
    cout << "Enter position you want to place your character : ";
    cin >> pos;
    if (!second_player_turn(pos, arr))
    {
        system("cls");
        cout << "Invalid move player two" << endl
             << "Please enter the valid position" << endl;

        goto invalid_move_player_two;
    }
    moves++;
    if (is_won(arr))
    {
        system("cls");
        print_table(arr);
        cout << "Player two Wins" << endl;
        return;
    }

    play_game(arr);
}

int main()
{
    char grid[N][N];

rematch:
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = 3 * i + j + 1 + '0';
        }
    }

    play_game(grid);

    char ch;

    cout << "Rematch? (y/n) : ";
    cin >> ch;

    switch (ch)
    {
    case 'y':
    case 'Y':
        goto rematch;

    default:
        break;
    }
    return 0;
}