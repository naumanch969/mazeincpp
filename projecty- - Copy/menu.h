#pragma once
#include "fundamentals.h"
#include "helper.h"

using namespace std;

string startMenu()
{
    system("cls");
    cout << setw(100) << "  _______ _____ _____ _     _      _______ _____ _       _ _    _   " << endl;
    cout << setw(97) << "|  |  | |   |   |   |\\    |      |  |  | |     |\\     | |    |" << endl;
    cout << setw(97) << "|  |  | |   |   |   | \\   |      |  |  | |     | \\    | |    |" << endl;
    cout << setw(97) << "|  |  | |___|   |   |  \\  |      |  |  | |____ |   \\  | |    |" << endl;
    cout << setw(97) << "|  |  | |   |   |   |   \\ |      |  |  | |     |    \\ | |    |" << endl;
    cout << setw(97) << "|  |  | |   |   |   |    \\|      |  |  | |     |     \\| |    |" << endl;
    cout << setw(100) << "  |  |  | |   | __|__ |     |      |  |  | |____ |      | |____|   " << endl;
    cout << endl;
    cout << setw(70) << "1. Start " << endl
         << endl;
    cout << setw(71) << "2. Options" << endl
         << endl;
    cout << setw(68) << "3. Quit" << endl
         << endl;
    string mainInput;
    do
    {
        cout << "\t\t\t\t\t\t\t\t";
        getline(cin, mainInput);
        if (mainInput == "1")
        {
            system("cls");
            return "start";
            break;
        }
        else if (mainInput == "2")
        {
            system("cls");
            return "options";
            break;
        }
        else if (mainInput == "3")
        {
            cout << setw(77) << "Thanks For Playing!!!" << endl;
            exit(0);
        }
        else
        {
            cout << setw(73) << "Invalid Input" << endl;
        }
    } while (true);
}
string optionsMenu()
{
    cout << setw(90) << "_____ _____ _______ _____ _____ _      _ _______" << endl;
    cout << setw(90) << "|   | |   |    |      |   |   | |\\     | |     " << endl;
    cout << setw(90) << "|   | |   |    |      |   |   | | \\    | |     " << endl;
    cout << setw(90) << "|   | |___]    |      |   |   | |  \\   | |_____" << endl;
    cout << setw(90) << "|   | |        |      |   |   | |   \\  |      |" << endl;
    cout << setw(90) << "|   | |        |      |   |   | |    \\ |      |" << endl;
    cout << setw(90) << "[___] |        |    __|__ [___] |     \\| _____]" << endl;
    cout << endl
         << endl;
    cout << setw(70) << "1. Controls" << endl
         << endl;
    cout << setw(70) << "2. Theme   " << endl
         << endl;
    cout << setw(70) << "3. Credits " << endl
         << endl;
    cout << setw(75) << "Press X to go back" << endl
         << endl;
    string optionsInput;
    do
    {
        cout << "\t\t\t\t\t\t\t\t";
        getline(cin, optionsInput);
        if (optionsInput == "1")
        {
            system("cls");
            return "controls";
        }
        else if (optionsInput == "2")
        {
            system("cls");
            return "theme";
        }
        else if (optionsInput == "3")
        {
            system("cls");
            return "credits";
        }
        else if (optionsInput == "X" || optionsInput == "x")
        {
            system("cls");
            return "back";
        }
        else
        {
            cout << setw(73) << "Invalid Input" << endl;
        }
    } while (true);
}
int chooseMode()
{
    cout << setw(90) << "_       _   _______   _____     ______   ______" << endl;
    cout << setw(90) << "|\\     /|   |     |   |    \\    |        |     " << endl;
    cout << setw(90) << "| \\   / |   |     |   |     |   |        |     " << endl;
    cout << setw(90) << "|  \\ /  |   |     |   |     |   |_____   |_____" << endl;
    cout << setw(90) << "|       |   |     |   |     |   |             |" << endl;
    cout << setw(90) << "|       |   |     |   |     |   |             |" << endl;
    cout << setw(90) << "|       |   |_____|   |____/    |_____   _____|" << endl;
    cout << endl
         << endl;
    cout << setw(70) << "1. Classic  " << endl
         << endl;
    cout << setw(70) << "2. Storyline" << endl
         << endl;
    cout << setw(70) << "3. Timetrail" << endl
         << endl;
    cout << setw(75) << "Press X to go back" << endl
         << endl;
    string optionsInput;
    do
    {
        cout << "\t\t\t\t\t\t\t\t";
        getline(cin, optionsInput);
        if (optionsInput == "1")
        {
            system("cls");
            return 0;
        }
        else if (optionsInput == "2")
        {
            system("cls");
            return 1;
        }
        else if (optionsInput == "3")
        {
            system("cls");
            return 2;
        }
        else if (optionsInput == "X" || optionsInput == "x")
        {
            system("cls");
            return 3;
        }
        else
        {
            cout << setw(73) << "Invalid Input" << endl;
        }
    } while (true);
}

string controlsMenu()
{
    cout << setw(100) << "_______ ______ _      _ _______ ______ ______ _       ______ " << endl;
    cout << setw(100) << "|       |    | |\\     |    |    |    | |    | |       |      " << endl;
    cout << setw(100) << "|       |    | | \\    |    |    |    | |    | |       |      " << endl;
    cout << setw(100) << "|       |    | |  \\   |    |    |____| |    | |       |_____ " << endl;
    cout << setw(100) << "|       |    | |   \\  |    |    |\\     |    | |            | " << endl;
    cout << setw(100) << "|       |    | |    \\ |    |    | \\    |    | |            | " << endl;
    cout << setw(100) << "|______ |____| |     \\|    |    |  \\   |____| |______ _____| " << endl;
    cout << endl
         << endl;
    cout << setw(65) << "Action\t\t\tKey" << endl
         << endl;
    cout << setw(68) << "Move Up   \t\tUp Key" << endl;
    cout << setw(71) << "Move Down \t\tDown Key" << endl;
    cout << setw(71) << "Move Left \t\tLeft Key" << endl;
    cout << setw(73) << "Move Right\t\tRight Key" << endl;
    cout << endl
         << setw(72) << "Press X to go back" << endl
         << endl;
    string input;
    do
    {
        cout << "\t\t\t\t\t\t\t\t";
        getline(cin, input);
        if (input == "x" || input == "X")
        {
            system("cls");
            return "back";
        }
        else
        {
            cout << setw(73) << "Invalid Input" << endl;
        }
    } while (true);
}
bool foregroundMenu()
{
    cout << setw(70) << "Please Select the Color" << endl;
    cout << setw(65) << "0\tBlack       " << endl;
    cout << setw(65) << "1\tBlue        " << endl;
    cout << setw(65) << "2\tGreen       " << endl;
    cout << setw(65) << "3\tAqua        " << endl;
    cout << setw(65) << "4\tRed	        " << endl;
    cout << setw(65) << "5\tPurple      " << endl;
    cout << setw(65) << "6\tYellow      " << endl;
    cout << setw(65) << "7\tWhite       " << endl;
    cout << setw(65) << "8\tGray        " << endl;
    cout << setw(65) << "9\tLight Blue  " << endl;
    cout << setw(65) << "A\tLight Green " << endl;
    cout << setw(65) << "B \tLight Aqua " << endl;
    cout << setw(65) << "C\tLight Red   " << endl;
    cout << setw(65) << "D\tLight Purple" << endl;
    cout << setw(65) << "E\tLight Yellow" << endl;
    cout << setw(65) << "F\tBright White" << endl;
    cout << endl
         << setw(69) << "Press X to go back" << endl
         << endl;
    string colorInput;

    do
    {
        cout << "\t\t\t\t\t\t\t";
        getline(cin, colorInput);
        if (colorInput == "1")
        {
            system("cls");
            theme.foreground = "1";
            changeSystemColor(theme.background, "1");
            return true;
        }
        else if (colorInput == "2")
        {
            system("cls");
            theme.foreground = "2";
            changeSystemColor(theme.background, "2");
            return true;
        }
        else if (colorInput == "3")
        {
            system("cls");
            theme.foreground = "3";
            changeSystemColor(theme.background, "3");
            return true;
        }
        else if (colorInput == "4")
        {
            system("cls");
            theme.foreground = "4";
            changeSystemColor(theme.background, "4");
            return true;
        }
        else if (colorInput == "5")
        {
            system("cls");
            theme.foreground = "5";
            changeSystemColor(theme.background, "5");
            return true;
        }
        else if (colorInput == "6")
        {
            system("cls");
            theme.foreground = "6";
            changeSystemColor(theme.background, "6");
            return true;
        }
        else if (colorInput == "7")
        {
            system("cls");
            theme.foreground = "7";
            changeSystemColor(theme.background, "7");
            return true;
        }
        else if (colorInput == "8")
        {
            system("cls");
            theme.foreground = "8";
            changeSystemColor(theme.background, "8");
            return true;
        }
        else if (colorInput == "9")
        {
            system("cls");
            theme.foreground = "9";
            changeSystemColor(theme.background, "9");
            return true;
        }
        else if (colorInput == "A")
        {
            system("cls");
            theme.foreground = "A";
            changeSystemColor(theme.background, "A");
            return true;
        }
        else if (colorInput == "B")
        {
            system("cls");
            theme.foreground = "B";
            changeSystemColor(theme.background, "B");
            return true;
        }
        else if (colorInput == "C")
        {
            system("cls");
            theme.foreground = "C";
            changeSystemColor(theme.background, "C");
            return true;
        }
        else if (colorInput == "D")
        {
            system("cls");
            theme.foreground = "D";
            changeSystemColor(theme.background, "D");
            return true;
        }
        else if (colorInput == "E")
        {
            system("cls");
            theme.foreground = "E";
            changeSystemColor(theme.background, "E");
            return true;
        }
        else if (colorInput == "F")
        {
            system("cls");
            theme.foreground = "F";
            changeSystemColor(theme.background, "F");
            return true;
        }
        else if (colorInput == "X" || colorInput == "x")
        {
            system("cls");
            return true;
        }
        else
        {
            cout << setw(73) << "Invalid Input" << endl;
        }
    } while (true);
}
bool backgroundMenu()
{
    cout << setw(70) << "Please Select the Color" << endl;
    cout << setw(65) << "0\tBlack       " << endl;
    cout << setw(65) << "1\tBlue        " << endl;
    cout << setw(65) << "2\tGreen       " << endl;
    cout << setw(65) << "3\tAqua        " << endl;
    cout << setw(65) << "4\tRed	        " << endl;
    cout << setw(65) << "5\tPurple      " << endl;
    cout << setw(65) << "6\tYellow      " << endl;
    cout << setw(65) << "7\tWhite       " << endl;
    cout << setw(65) << "8\tGray        " << endl;
    cout << setw(65) << "9\tLight Blue  " << endl;
    cout << setw(65) << "A\tLight Green " << endl;
    cout << setw(65) << "B \tLight Aqua " << endl;
    cout << setw(65) << "C\tLight Red   " << endl;
    cout << setw(65) << "D\tLight Purple" << endl;
    cout << setw(65) << "E\tLight Yellow" << endl;
    cout << setw(65) << "F\tBright White" << endl;
    cout << endl
         << setw(69) << "Press X to go back" << endl
         << endl;
    string colorInput;

    do
    {
        cout << "\t\t\t\t\t\t\t";
        getline(cin, colorInput);
        if (colorInput == "1")
        {
            system("cls");
            theme.background = "1";
            changeSystemColor("1", theme.foreground);
            return true;
        }
        else if (colorInput == "2")
        {
            system("cls");
            theme.background = "2";
            changeSystemColor("2", theme.foreground);
            return true;
        }
        else if (colorInput == "3")
        {
            system("cls");
            theme.background = "3";
            changeSystemColor("3", theme.foreground);
            return true;
        }
        else if (colorInput == "4")
        {
            system("cls");
            theme.background = "4";
            changeSystemColor("4", theme.foreground);
            return true;
        }
        else if (colorInput == "5")
        {
            system("cls");
            theme.background = "5";
            changeSystemColor("5", theme.foreground);
            return true;
        }
        else if (colorInput == "6")
        {
            system("cls");
            theme.background = "6";
            changeSystemColor("6", theme.foreground);
            return true;
        }
        else if (colorInput == "7")
        {
            system("cls");
            theme.background = "7";
            changeSystemColor("7", theme.foreground);
            return true;
        }
        else if (colorInput == "8")
        {
            system("cls");
            theme.background = "8";
            changeSystemColor("8", theme.foreground);
            return true;
        }
        else if (colorInput == "9")
        {
            system("cls");
            theme.background = "9";
            changeSystemColor("9", theme.foreground);
            return true;
        }
        else if (colorInput == "A")
        {
            system("cls");
            theme.background = "A";
            changeSystemColor("A", theme.foreground);
            return true;
        }
        else if (colorInput == "B")
        {
            system("cls");
            theme.background = "B";
            changeSystemColor("B", theme.foreground);
            return true;
        }
        else if (colorInput == "C")
        {
            system("cls");
            theme.background = "C";
            changeSystemColor("C", theme.foreground);
            return true;
        }
        else if (colorInput == "D")
        {
            system("cls");
            theme.background = "D";
            changeSystemColor("D", theme.foreground);
            return true;
        }
        else if (colorInput == "E")
        {
            system("cls");
            theme.background = "E";
            changeSystemColor("E", theme.foreground);
            return true;
        }
        else if (colorInput == "F")
        {
            system("cls");
            theme.background = "F";
            changeSystemColor("F", theme.foreground);
            return true;
        }
        else if (colorInput == "X" || colorInput == "x")
        {
            system("cls");
            return true;
        }
        else
        {
            cout << setw(73) << "Invalid Input" << endl;
            continue;
        }
    } while (true);
}

string themeMenu()
{
label1:
    cout << setw(80) << "_______ _   _ _____ _             _ _____ " << endl;
    cout << setw(80) << "   |    |   | |     |\\          /| |    " << endl;
    cout << setw(80) << "   |    |   | |     | \\        / | |    " << endl;
    cout << setw(80) << "   |    |___| |____ |  \\      /  | |____" << endl;
    cout << setw(80) << "   |    |   | |     |   \\    /   | |    " << endl;
    cout << setw(80) << "   |    |   | |     |    \\  /    | |    " << endl;
    cout << setw(80) << "   |    |   | |____ |     \\/     | |____" << endl;
    cout << endl
         << endl;
    cout << setw(70) << "1. Background Color" << endl;
    cout << endl;
    cout << setw(70) << "2. Text Color      " << endl
         << endl;
    cout << setw(69) << "Press X to go back" << endl
         << endl;
    string themeInput;
    do
    {
        cout << "\t\t\t\t\t\t\t";
        getline(cin, themeInput);
        if (themeInput == "1")
        {
            system("cls");
            if (backgroundMenu() == true)
            {
                system("cls");
                goto label1;
            }
        }
        else if (themeInput == "2")
        {
            system("cls");
            if (foregroundMenu() == true)
            {
                system("cls");
                goto label1;
            }
        }
        else if (themeInput == "X" || themeInput == "x")
        {
            system("cls");
            return "back";
        }
        else
        {
            cout << setw(73) << "Invalid Input" << endl;
        }
    } while (true);
}
string creditsMenu()
{
    cout << setw(80) << "1. Producer          MNC & AAS        " << endl;
    cout << setw(80) << "2. Programmers       MNC & AAS        " << endl;
    cout << setw(80) << "                     MNC & AAS        " << endl;
    cout << setw(80) << "3. Writter           MNC & AAS        " << endl;
    cout << setw(80) << "4. Music             MNC & AAS        " << endl;
    cout << setw(80) << "5. Composer          MNC & AAS        " << endl;
    cout << setw(80) << "6. Design Artist     MNC & AAS        " << endl;
    cout << endl
         << setw(65) << "Press X to go back" << endl
         << endl;
    string input;
    do
    {
        cout << "\t\t\t\t\t\t\t";
        getline(cin, input);
        if (input == "x" || input == "X")
        {
            system("cls");
            return "back";
        }
        else
        {
            cout << setw(73) << "Invalid Input" << endl;
        }
    } while (true);
}

void mainMenu()
{
    system("cls");
    loadingScreen();
    string chosenOption;
    do
    {
        if (startMenu() == "start")
        {
            // startGame();
            break;
        }
        else
        {
            do
            {
                chosenOption = optionsMenu();
                if (chosenOption == "controls")
                {
                    if (controlsMenu() == "back")
                        continue;
                }
                else if (chosenOption == "theme")
                {
                    if (themeMenu() == "back")
                        continue;
                }
                else if (chosenOption == "credits")
                {
                    if (creditsMenu() == "back")
                        continue;
                }
                else if (chosenOption == "back")
                {
                    chosenOption = "";
                    break;
                }
            } while (true);
            if (chosenOption == "")
                continue;
            else
                break;
        }
    } while (true);
}