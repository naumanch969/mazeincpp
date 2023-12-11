#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>
using namespace std;

char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string player = "User";

void Draw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void togglePlayer()
{
    player = player == "User" ? "Mashine" : "User";
}
char getRandomCharacter()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 9);
    return static_cast<char>(distribution(gen) + '0');
}

void userInput()
{

    while (1) // mashine input could already be selected, so regenerate input in that case
    {
        char input;
        cout << "Select Number: ";
        cin >> input;
        bool isFound = false;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix[i][j] == input) // if  array character matches with mashine input
                {
                    matrix[i][j] = 'X';
                    isFound = true;
                    break;
                }
            }
            if (isFound)
                break;
        }

        if (isFound)
            break;
        else
            cout << input << " is already selected." << endl;
    }
    togglePlayer();
}
void mashineInput()
{
    while (1) // mashine input could already be selected, so regenerate input in that case
    {
        char input = getRandomCharacter(); // generating random character as mashine input
        bool isFound = false;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix[i][j] == input) // if  array character matches with mashine input
                {
                    matrix[i][j] = 'O';
                    isFound = true;
                    cout << "Mashine Input: " << input << endl;
                    break;
                }
            }
            if (isFound)
                break;
        }

        if (isFound)
            break;
    }
    togglePlayer();
}
char Check()
{

    // User
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'U';
    else if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'U';
    else if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'U';

    else if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'U';
    else if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'U';
    else if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'U';

    else if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'U';
    else if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
        return 'U';

    // Mashine
    else if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'M';
    else if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'M';
    else if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'M';

    else if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'M';
    else if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'M';
    else if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'M';

    else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'M';
    else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
        return 'M';

    else
    {
        bool isBoxFull = false;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix[i][j] == 'X' || matrix[i][j] == 'O') // if  array character matches with mashine input
                {
                    isBoxFull = true;
                }
                else
                {
                    isBoxFull = false;
                    break;
                }
            }
        }
        if (isBoxFull)
            return 'D';
        else
            return 'C';
    }
}

int main()
{
    cout << "Tic Tac Toe" << endl;

    Draw();
    while (1)
    {
        system("cls");
        if (player == "User")
        {
            userInput();
        }
        else
        {
            mashineInput();
        }
        Draw();
        char winner = Check(); // U for user, M for mashine, D for draw
        if (winner == 'U')
        {
            cout << "You Win!";
            break;
        }
        else if (winner == 'M')
        {
            cout << "Mashine Win!";
            break;
        }
        else if (winner == 'D')
        {
            cout << "Match Draw.";
            break;
        }
        else
            continue;
    }

    return 0;
}
