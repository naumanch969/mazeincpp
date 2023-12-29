#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define RESET "\033[0m"

#define BACKGROUND_BLUE 0x0010		// Blue background
#define BACKGROUND_GREEN 0x0020		// Green background
#define BACKGROUND_RED 0x0040		// Red background
#define BACKGROUND_INTENSITY 0x0080 // Intensity (bright) background

#define BACKGROUND_WHITE (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED) // White background
#define BACKGROUND_SILVER (BACKGROUND_WHITE | BACKGROUND_INTENSITY)

// GLOBAL VARIABLES
int e = 0;
// e to check the Monster that is selected in the level of the game.
int response;
int mazeCols = 14;
int mazeRows = 8;
char enter;
int score = 0;
// int Health = 100;
int timelimit = 30;
int levelno = 1;
int seconds = 30;
int encounteredEnemies = 0;
int numberOfEnemies = 5;
int numberOfChests = 1;
int dialogueBoxWidth = 40;
int dialogueBoxHeight = 2 * mazeRows;
string username; // making a global variable to ask for the name of the user.

bool backToMainMenu = false;

char TAB = '\t';
char ESCAPE = 27;

struct Position
{
	int x;
	int y;

	Position(const int &a, const int &b) : x(a), y(b) {}
};
struct Wall
{
	pair<int, int> cell1;
	pair<int, int> cell2;
};
struct Enemyy
{
	int x;
	int y;
	char enemy;
};
struct Monster
{
	int health;
	string name;
	string status;

	Monster(const int &a, const string &b) : health(a), name(b) {}
};
struct Player
{
	int x;
	int y;
	char player;
	int health;
	bool immune = false; // if he has, he can bypass enemy

	Player(const int &a, const int &b, const char &c, const int &d, const bool &e) : x(a), y(b), player(c), health(d), immune(e) {}
};
struct Chest
{
	char character;
	int x;
	int y;
	string reward; // immune, score, health refill, null.
};
struct Question
{
	string question;
	string answer;

	Question(const string &q, const string &a) : question(q), answer(a) {}
};
struct Riddle
{
	string riddle;
	vector<string> options;
	char answer;

	Riddle(const string &r, const vector<string> &a, const char &ans) : riddle(r), options(a), answer(ans) {}
};
struct Theme
{
	string background;
	string foreground;

	Theme(const string &b, const string &f) : background(b), foreground(f) {}
};

Position dialogueBoxStart(90, 5);
Position mazeStart(5, 5);
Player superman(mazeStart.x + 1, mazeStart.y + 1, 'a', 100, false);
Theme theme("8", "0");

Riddle riddles[10] = {
	Riddle("What has keys but can't open locks?", {"A. piano", "B. keyboard", "C. typewriter", "D. computer"}, 'A'),
	Riddle("What has a head and a tail but no body?", {"A. coin", "B. snake", "C. book", "D. ship"}, 'A'),
	Riddle("What has one eye but can't see?", {"A. needle", "B. tornado", "C. potato", "D. fish"}, 'A'),
	Riddle("What is always in front of you but can't be seen?", {"A. The future", "B. The past", "C. The present", "D. Air"}, 'D'),
	Riddle("I am taken from a mine and shut up in a wooden case, from which I am never released, and yet I am used by almost every person. What am I?", {"A. A pencil", "B. Gold", "C. Coal", "D. A diamond"}, 'A'),
	Riddle("What comes once in a minute, twice in a moment, but never in a thousand years?", {"A. The letter 'M'", "B. A clock", "C. Laughter", "D. The number 1"}, 'A'),
	Riddle("The more you take, the more you leave behind. What am I?", {"A. Footsteps", "B. Memories", "C. Presents", "D. Footprints"}, 'D'),
	Riddle("What is full of holes but still holds water?", {"A. A sponge", "B. A net", "C. A sieve", "D. A bottle"}, 'A'),
	Riddle("What has a neck but no head?", {"A. A bottle", "B. A shirt", "C. A snake", "D. A balloon"}, 'B'),
	Riddle("I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?", {"A. An echo", "B. A thought", "C. A dream", "D. A cloud"}, 'D')};
Question questions[20] = {
	Question("What's the capital of Pakistan", "Islamabad"),
	Question("What's the capital of France", "Paris"),
	Question("What's the capital of France", "Paris"),
	Question("What's the capital of Turkey", "Ankara"),
	Question("What's the capital of China", "Beijing"),
	Question("What's the capital of Japan", "Tokyo"),
	Question("What's the capital of USA", "Washington"),
	Question("What's the capital of England", "London"),
	Question("What's the capital of England", "London"),
	Question("What's the capital of Norway", "Oslo"),
	Question("What's the capital of Spain", "Madrid"),
	Question("What's the capital of Italy", "Room"),
	Question("What's the capital of India", "Delhi"),
	Question("What's the capital of Bangladesh", "Dhaka"),
	Question("What's the capital of Denmark", "Copenhegan"),
	Question("What's the capital of Canada", "Toronto"),
	Question("What's the capital of Srilanka", "Columbo"),
	Question("What's the capital of Saudi Arabia", "Riaz"),
	Question("What's the capital of Saudi Arabia", "Riaz"),
	Question("What's the capital of Portugal", "Lisbon")};
Monster monsters[6] = {
	Monster(40, "Kazuma"),
	Monster(50, "toughieee"),
	Monster(60, "noyan"),
	Monster(65, "dirtuuuu"),
	Monster(75, "jarasim"),
	Monster(100, "DEADLY DIRT")};

Enemyy *enemiesArray = new Enemyy[numberOfEnemies];
Chest *chestsArray = new Chest[numberOfChests];