#pragma once

#include "fundamentals.h"

void gotoxy(int x, int y)
{
    // Set console cursor position
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void changeSystemColor(string bg = theme.background, string fg = theme.foreground)
{
    string command = "color " + bg + fg;
    const char* commandCStr = command.c_str();
    system(commandCStr);
}
void animateText(string sentence)
{
    for (int j = 0; j < sentence.length(); j++)
    {
        // skip the text if enter is pressed during the animation, put changes here
        Sleep(20);
        if ((GetAsyncKeyState(VK_RETURN) & 0x8000) && j > 2)
        {
            for (int k = j; k < sentence.length(); k++)
            {
                cout << sentence[k];
            }
            Sleep(300);
            break;
        }
        cout << sentence[j];
    }
}
void cleanDialogueBox()
{
    for (int i = 0; i < dialogueBoxHeight - 2; i++)
    {
        gotoxy(dialogueBoxStart.x + 1, dialogueBoxStart.y + 1 + i);
        for (int i = 0; i < dialogueBoxWidth - 2; i++)
        {
            cout << " ";
        }
    }
}
void customPrint(int x, int y, int width, const std::string& text, int& linesTaken)
{
    // Initial position
    int currentX = x;
    int currentY = y;

    // Iterate through each character in the text
    for (char ch : text)
    {
        // Check if the current position exceeds the specified width
        if (currentX - x >= width)
        {
            // Move to the next line
            currentX = x;
            currentY++;
            linesTaken++;
        }

        // Set the cursor position and print the character
        gotoxy(currentX, currentY);
        std::cout << ch;

        // Move to the next column
        currentX++;
    }
}
void enableBGText(WORD backgroundColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, backgroundColor);
}
void disableBGText()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

    changeSystemColor(theme.background, theme.foreground);
}
int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.X;
}
int getConsoleHeight()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.Y;
}
char getCharacterAtPosition(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Invalid handle." << std::endl;
        return '\0';
    }

    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    DWORD charsRead;
    char charBuffer;

    if (!ReadConsoleOutputCharacterA(hConsole, &charBuffer, 1, coord, &charsRead))
    {
        std::cerr << "ReadConsoleOutputCharacterA failed." << std::endl;
        return '\0';
    }

    return charBuffer;
}
int getASCIIAtPosition(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Invalid handle." << std::endl;
        return 0; // Return 0 to indicate an error
    }

    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    DWORD charsRead;
    char charBuffer;

    if (!ReadConsoleOutputCharacterA(hConsole, &charBuffer, 1, coord, &charsRead))
    {
        std::cerr << "ReadConsoleOutputCharacterA failed." << std::endl;
        return 0; // Return 0 to indicate an error
    }

    // Convert the character to ASCII value (cast to int)
    int asciiValue = static_cast<int>(charBuffer);
    return asciiValue;
}
void loadingbar()
{
    system("cls");
    printf("\e[?251");

    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    int bar1 = 177, bar2 = 219;

    cout << "\n\n\n\t\t\t\t\t\t\t\t\t  Loading...";
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t";

    for (int i = 1; i <= 25; i++)
        cout << (char)bar1;

    cout << "\r\t\t\t\t\t\t\t\t\t";

    for (int i = 0; i <= 25; i++)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == '\t')
            {
                // Skip loading if Tab key is pressed
                cout << "\n\t\t\t\t\t\t\t\t\tLoading skipped by user.\n";
                return;
            }
        }

        cout << (char)bar2;
        Sleep(50);
    }
}
void centerText(const string& text)
{
    int width = getConsoleWidth();
    if (width > 0)
    {
        int padding = (width - static_cast<int>(text.length())) / 2;
        for (int i = 0; i < padding; i++)
        {
            cout << " ";
        }
        cout << text; // Display centered text.
    }
    else
    {
        cerr << "Unable to determine console width." << endl; // Print an error message if console width cannot be determined.
    }
}
string toLowerCase(string answer)
{
    for (char& c : answer)
    {
        c = tolower(c);
    }
    return answer;
}

// void playAudio(const char *filePath)
// {
// 	PlaySound(TEXT("C:/Users/Track Computers/Desktop/track.wav"), NULL, SND_FILENAME | SND_ASYNC);
// }

void cursorPosition(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void loadingScreen()
{
    cout << setw(115) << "______ _   _ _____    ____ _____ ____ _   _ _____    _____ _____ _____ _____ _____ _____" << endl;
    cout << setw(115) << "  |    |   | |       |   | |   | |    |   | |        |     |     |   | |   | |   | |    " << endl;
    cout << setw(115) << "  |    |   | |       |   | |   | | -| |   | |        |     |     |     |   | |   | |    " << endl;
    cout << setw(115) << "  |    |___| |____   |___| |   | |__| |   | |____    |____ |___| |     |___| |___| |____" << endl;
    cout << setw(115) << "  |    |   | |       |\\    |   |    | |   | |        |         | |     |   | |     |    " << endl;
    cout << setw(115) << "  |    |   | |       | \\   |   |    | |   | |        |         | |   | |   | |     |    " << endl;
    cout << setw(115) << "  |    |   | |____   |  \\  |___|    | |___| |____    |____ ____| |___| |   | |     |____" << endl;
    cout << endl
        << endl;
    cout << setw(60) << "Loading... ";
    for (int i = 0; i < 22; i++)
    {
        cout << char(177);
    }
    for (int i = 0; i < 22; i++)
    {
        cursorPosition(60 + i, 11);
        Sleep(25);
        cout << char(178);
    }
}
