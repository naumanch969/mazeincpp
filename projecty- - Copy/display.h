#pragma once

#include "fundamentals.h"
#include "helper.h"
// #include "modes.h"
#include "maze.h"

void displayHealth()
{
	string healthString = "Health: " + to_string(superman.health);
	string scoreString = "Score: " + to_string(score);
	string escapeString = "Press Esc to skip the game.";
	Position healthStringPosition(((dialogueBoxWidth + dialogueBoxStart.x) + dialogueBoxStart.x) / 2 - healthString.length() / 2, 2);
	Position scoreStringPosition(((dialogueBoxWidth + dialogueBoxStart.x) + dialogueBoxStart.x) / 2 - healthString.length() / 2, 3);
	Position escapeStringPosition(((dialogueBoxWidth + dialogueBoxStart.x) + dialogueBoxStart.x) / 2 - escapeString.length() / 2, 0);

	int startX = dialogueBoxStart.x;
	int startY = 1;

	gotoxy(startX, startY - 1);
	for (int i = 0; i < dialogueBoxWidth; i++)
	{
		cout << " ";
	}
	gotoxy(escapeStringPosition.x, escapeStringPosition.y);
	cout << escapeString;

	// Draw the top border
	gotoxy(startX, startY);
	char topAciiCharacter = 203;
	for (int i = 0; i < dialogueBoxWidth; i++)
	{
		cout << topAciiCharacter;
	}

	// Draw the sides
	char leftAciiCharacter = 204;
	char rightAciiCharacter = 185;
	for (int j = 0; j < 2; j++)
	{
		gotoxy(startX, startY + j + 1);
		for (int i = 0; i < dialogueBoxWidth; i++)
		{
			if (i == 0)
			{
				cout << leftAciiCharacter;
			}
			else if (i == dialogueBoxWidth - 1)
			{
				cout << rightAciiCharacter;
			}
			else
			{
				cout << " ";
			}
		}
	}

	// Draw the bottom border
	char bottomAciiCharacter = 202;
	gotoxy(startX, startY + 3);
	for (int i = 0; i < dialogueBoxWidth; i++)
	{
		cout << bottomAciiCharacter;
	}

	if (healthString.length() >= 9 && healthString.length() < 11)
	{
		// Calculate the number of spaces to add
		int spacesToAdd = 11 - healthString.length();
		// Append spaces to the string
		for (int i = 0; i < spacesToAdd; ++i)
		{
			healthString += ' ';
		}
	}

	if (scoreString.length() >= 9 && scoreString.length() < 11)
	{
		// Calculate the number of spaces to add
		int spacesToAdd = 11 - scoreString.length();
		// Append spaces to the string
		for (int i = 0; i < spacesToAdd; ++i)
		{
			scoreString += ' ';
		}
	}

	gotoxy(healthStringPosition.x, healthStringPosition.y);
	cout << healthString;

	gotoxy(scoreStringPosition.x, scoreStringPosition.y);
	cout << scoreString;
}
void menuOptions(string arr[], int size, int activeOption)
{
	system("cls");
	// Clear the console (for Windows, use system("clear") for Unix-based systems)
	cout << "\x1b[33m\n\nSelect your choice. \x1b[0m" << endl;
	cout << "+=============================+" << endl;
	for (int i = 0; i < size; i++)
	{
		if (i == activeOption)
		{
			cout << BOLD << UNDERLINE << "      " << arr[i] << RESET << endl;
		}
		else
		{
			cout << "      " << arr[i] << endl;
		}
	}
	cout << "+=============================+" << endl;
}

bool enemyCoordiCorrectness(int x, int y)
{
	return (getCharacterAtPosition(x, y) != (char)219 && getCharacterAtPosition(x, y) != '+');
}
bool chestCoordiCorrectness(int x, int y)
{
	return (getCharacterAtPosition(x, y) != (char)219 && getASCIIAtPosition(x, y) != -80); // -80 is for enemies.
}

void displayScreenBorders() // not working correctly right now
{
	int screenWidth = getConsoleWidth(); // Assuming 'screen' is declared somewhere in your code
	int screenHeight = getConsoleWidth();
	// Display top border
	for (int i = 0; i < screenWidth; ++i)
	{
		cout << "#";
	}
	// Display side borders and empty space in between
	for (int i = 0; i < screenHeight - 2; ++i)
	{
		gotoxy(0, i);
		cout << "#";
		gotoxy(screenWidth - 2, i);
		cout << "#" << endl;
	}
	// Display bottom border
	for (int i = 0; i < screenWidth; ++i)
	{
		cout << "#";
	}
}
int displayOptions(string arr[], int size)
{
	int activeOption = 0;
	char arbitrary;
	menuOptions(arr, size, activeOption);
	while (true)
	{
		if (_kbhit())
		{
			arbitrary = _getch();
			if (arbitrary == 72 && activeOption > 0)
			{
				activeOption--;
			}
			else if (arbitrary == 80 && activeOption < size - 1)
			{
				activeOption++;
			}
			else if (arbitrary == 13)
			{ // Enter key to confirm selection
				return activeOption;
				break;
			}
			menuOptions(arr, size, activeOption); // Update the displayed options
		}
	}
}

void askQuestions()
{
	cleanDialogueBox();
	enableBGText(BACKGROUND_SILVER);
	srand(time(0));
	int x = dialogueBoxStart.x + 1; // one for border
	int y = dialogueBoxStart.y + 2; // one for border, one for heading, then show the text
	int questionsLength = sizeof(questions) / sizeof(Question);
	int index = rand() % questionsLength;
	string answer;
	Question question = questions[index];
	gotoxy(x, y); // moving in dialgoue box
	string q = "Enemy " + to_string(encounteredEnemies + 1) + ": Answer this question : " + question.question;
	int linesTaken = 1;
	customPrint(x, y, dialogueBoxWidth - 2, q, linesTaken);
	gotoxy(x, y + linesTaken + 1);
	cout << "Your answer: ";
	gotoxy(x, y + linesTaken + 2);
	cin >> answer;
	// Check the player's answer and affect health accordingly
	cleanDialogueBox();
	gotoxy(x, y + linesTaken + 3);
	if (toLowerCase(answer) == toLowerCase(question.answer))
	{
		string str = "Enemy: Correct! You escaped without damage.";
		customPrint(x, y, dialogueBoxWidth - 2, str, linesTaken);
	}
	else
	{
		string str = "Enemy: Wrong answer! You lost 20 points of health.";
		customPrint(x, y, dialogueBoxWidth - 2, str, linesTaken);
		superman.health -= 20;
		if (superman.health <= 0)
		{
			system("cls");
			cout << "You have lost all of your health." << endl;
			cout << "Your health :" << ((superman.health < 0) ? 0 : superman.health) << endl;
			cout << "Your score :" << score << endl;

			cout << endl;

			score = 0;
			superman.health = 100;
			mazeRows = 8;
			mazeCols = 14;
			cout << "Press any key continue.";
			_getch();
			throw runtime_error("BreakException");
			// exit(0);
		}
		// This will be happening only when we have the classic mode of the game.
		// if (response == 0)
		// {
		// 	gotoxy(0, 0);
		// 	cout << "+=================================+" << endl;
		// 	cout << "|       Health Bar = " << superman.health << "          |" << endl;
		// 	cout << "|       current score = " << score << "          |" << endl;
		// 	cout << "+=================================+" << endl;
		// }
	}
}
void askRiddles()
{
	cleanDialogueBox();
	enableBGText(BACKGROUND_SILVER);
	srand(time(0));

	int x = dialogueBoxStart.x + 1; // one for border
	int y = dialogueBoxStart.y + 2; // one for border, one for heading, then show the text
	int riddlesLength = sizeof(riddles) / sizeof(Riddle);

	int index = rand() % riddlesLength;
	Riddle riddle = riddles[index];

	gotoxy(x, y); // moving in dialgoue box
	string q = "Enemy " + to_string(encounteredEnemies + 1) + ": Answer this riddle : " + riddle.riddle;
	int linesTaken = 1; // these are number of extra lines to be taken
	customPrint(x, y, dialogueBoxWidth - 2, q, linesTaken);

	for (int i = 0; i < 4; i++)
	{
		customPrint(x, y + linesTaken + 1 + i, dialogueBoxWidth - 2, riddle.options[i], linesTaken);
	}
	gotoxy(x, y + linesTaken + 5); // after 4 options
	cout << "Your answer: ";

	char answer;
	gotoxy(x, y + linesTaken + 6); // after 4 options and 1 'Your answer'
	cin >> answer;

	// Check the player's answer and affect health accordingly
	cleanDialogueBox();
	gotoxy(x, y + linesTaken + 7);
	if (tolower(answer) == tolower(riddle.answer))
	{
		string str = "Enemy: Correct! You escaped without damage.";
		customPrint(x, y, dialogueBoxWidth - 2, str, linesTaken);
	}
	else
	{
		string str = "Enemy: Wrong answer! You lost 20 points of health.";
		customPrint(x, y, dialogueBoxWidth - 2, str, linesTaken);
		superman.health -= 20;
		if (superman.health <= 0)
		{
			system("cls");
			cout << "You have lost all of your health." << endl;
			cout << "Your health :" << superman.health << endl;
			cout << "Your score :" << score << endl;

			cout << endl;

			score = 0;
			superman.health = 100;
			mazeRows = 8;
			mazeCols = 14;
			cout << "Press any key continue.";
			_getch();
			throw runtime_error("BreakException");
			// exit(0);
		}
		// This will be happening only when we have the classic mode of the game.
		// if (response == 0)
		// {
		// 	gotoxy(0, 0);
		// 	cout << "+=================================+" << endl;
		// 	cout << "|       Health Bar = " << superman.health << "          |" << endl;
		// 	cout << "|       current score = " << score << "          |" << endl;
		// 	cout << "+=================================+" << endl;
		// }
	}
}
void chestReward()
{
	enableBGText(BACKGROUND_SILVER);
	cleanDialogueBox();
	int x = dialogueBoxStart.x + 1;
	int y = dialogueBoxStart.y + 2; // one for border, one for heading, then show the text
	int random = rand() % 4;
	gotoxy(x, y);
	switch (random)
	{
	case 0: // 	IMMUNE
		cout << "YOU HAVE FOUND THE IMMUNE POWER UP .";
		superman.immune = true;
		break;
	case 1: // 	SCORE
		cout << "YOUR SCORE INCREASES BY 12.";
		score += 12;
		break;
	case 2: //	HEALTH
		cout << "YOUR SCORE HEALTH IS RESTORED BY 5.";
		superman.health += 5;
		break;
	case 3:
		cout << "YOUR CHEST IS EMPTY PLEASE";
		break;
	default:
		break;
	}
}

void encounterEnemy(int playerX, int enemyX, int playerY, int enemyY)
{
	// Check if the player encounters the enemy
	if (playerX == enemyX && playerY == enemyY && getASCIIAtPosition(enemyX, enemyY) == -24) // -80 was the previous.
	{
		if (superman.immune == true)
		{
			superman.immune = false;
			return;
		}
		int random = (levelno > 2) ? rand() % 2 : 3; // if level > 2, there are chances of both questions and riddles else only questions
		switch (random)
		{
		case 0:
			askQuestions();
			break;
		case 1:
			askRiddles();
			break;
		default:
			askQuestions();
			break;
		}
		displayHealth();
	}
}
void encounterChest(int playerX, int chestX, int playerY, int chestY)
{
	if (playerX == chestX && playerY == chestY && getCharacterAtPosition(chestX, chestY) == '+')
	{
		chestReward();
		displayHealth();
	}
}

void displayChests()
{
	for (int i = 0; i < numberOfChests; i++)
	{
		chestsArray[i].character = '+';
	}
	srand(static_cast<unsigned int>(time(0)));

	while (true)
	{ // doing the necessary modifidcations so that the chests do not get out of the maze
		for (int i = 0; i < numberOfChests; i++)
		{
			chestsArray[i].x = (5 + (rand() % mazeCols));
			chestsArray[i].y = (5 + (rand() % mazeCols));
		}
		bool isEncounter = false;
		// checking enemy correctness
		for (int i = 0; i < numberOfChests; i++)
			if (chestCoordiCorrectness(chestsArray[i].x, chestsArray[i].y))
			{
				isEncounter = true;
				break;
			}

		if (isEncounter)
			break;
	}

	for (int i = 0; i < numberOfChests; i++)
	{
		gotoxy(chestsArray[i].x, chestsArray[i].y);
		cout << chestsArray[i].character;
	}
}
void displayEnemies()
{
	for (int i = 0; i < numberOfEnemies; i++)
		enemiesArray[i].enemy = 232;

	srand(static_cast<unsigned int>(time(0)));

	int enemyX;
	int enemyY;
	int i = 0;
	while (i < numberOfEnemies)
	{
		enemyX = mazeStart.x + 2 + (rand() % mazeCols - 1); // 2 is to prevent from the start of the wall and 1 is from the end
		enemyY = mazeStart.y + 2 + (rand() % mazeRows - 1);
		if (enemyCoordiCorrectness(enemyX, enemyY))
			continue;

		enemiesArray[i].x = enemyX;
		enemiesArray[i].y = enemyY;
		i++;
	}

	for (int i = 0; i < numberOfEnemies; i++)
	{
		gotoxy(enemiesArray[i].x, enemiesArray[i].y);
		cout << enemiesArray[i].enemy;
	}
}
void displayDialogueBox()
{

	gotoxy(dialogueBoxStart.x, dialogueBoxStart.y);

	// Draw the top border
	char topAciiCharacter = 203;
	for (int i = 0; i < dialogueBoxWidth; i++)
	{
		cout << topAciiCharacter;
	}

	// Draw the sides
	char leftAciiCharacter = 204;
	char rightAciiCharacter = 185;
	for (int i = 1; i < dialogueBoxHeight - 1; i++)
	{
		gotoxy(dialogueBoxStart.x, dialogueBoxStart.y + i);
		cout << leftAciiCharacter;
		gotoxy(dialogueBoxStart.x + dialogueBoxWidth - 1, dialogueBoxStart.y + i);
		cout << rightAciiCharacter;
	}

	// Draw the bottom border
	char bottomAciiCharacter = 202;
	gotoxy(dialogueBoxStart.x, dialogueBoxStart.y + dialogueBoxHeight - 1);
	for (int i = 0; i < dialogueBoxWidth; i++)
	{
		cout << bottomAciiCharacter;
	}

	string dialogue = "-----Dialogue Box-----";
	int x = (dialogueBoxStart.x + (dialogueBoxStart.x + dialogueBoxWidth)) / 2 - dialogue.length() / 2;
	gotoxy(x, dialogueBoxStart.y + 1);
	cout << dialogue;
}
void displayMaze(const vector<vector<char>> &maze)
{
	int i = 0;
	for (const auto &row : maze)
	{
		gotoxy(mazeStart.x, mazeStart.y + i);
		for (char cell : row)
		{
			cout << cell << "";
		}
		cout << " " << endl;
		i++;
	}
	displayEnemies();
	displayChests();
}
void displayGame(const vector<vector<char>> &maze)
{
	displayMaze(maze);
	displayDialogueBox();
	displayHealth();

	// displayScreenBorders();  // not working correctly right now
}