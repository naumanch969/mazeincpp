#pragma once

#include "fundamentals.h"
#include "helper.h"
// #include "display.h"
#include "maze.h"

void timer()
{
    int timeLimit = 30; // Time limit in seconds

    // Timer logic
    std::time_t start_time = std::time(nullptr); // Get current time
    std::time_t current_time;
    std::time_t end_time = start_time + timelimit;

    while (true)
    {

        // Check the time
        current_time = time(nullptr);
        if (current_time >= end_time)
        {
            // clearing the screen and showing Time's up!
            system("cls");
            cout << "\nTime's up! Game Over.\n";
            cout << "your score is as follows . " << score;
            break;
        }
        gotoxy(1, 1);
        // Display time remaining to the player
        cout << "Time remaining: " << end_time - current_time << " seconds";

        // this_thread::sleep_for(chrono::seconds(1));
    }
}
void movePlayerwithtimer(int x, int y, char c)
{
    changeSystemColor();
    enableBGText(BACKGROUND_SILVER);
    int timeLimit = 30; // Time limit in seconds

    // Timer logic
    std::time_t start_time = std::time(nullptr); // Get current time
    std::time_t current_time;
    std::time_t end_time = start_time + timelimit;

    while (true)
    {
        current_time = time(nullptr);
        if (current_time >= end_time)
        {
            // clearing the screen and showing Time's up!
            system("cls");
            Sleep(1000);
            cout << "\nTime's up! Game Over.\n";
            cout << "your score is " << score;

           
			cout << endl;
		
			score  = 0;
			superman.health = 100;
			mazeRows = 8;
			mazeCols = 14;
			cout << "Press any key continue.";
			_getch();
			throw runtime_error("BreakException");
            // exit(0);
        }
        gotoxy(2, 4);
        // Display time remaining to the player
        cout << "Time remaining: " << end_time - current_time << " seconds";

        // this_thread::sleep_for(chrono::seconds(1));

        gotoxy(x, y);
        std::cout << c;

        if (_kbhit())
        {
            char key = _getch();
            gotoxy(x, y);
            std::cout << ' '; // Clear previous position

            int prevX = x;
            int prevY = y;

            // Move the player based on arrow key input

            switch (key)
            {
            case 72: // Up Arrow key code
                prevY = y;
                y--;
                break;
            case 80: // Down Arrow key code
                prevY = y;
                y++;
                break;
            case 75: // Left Arrow key code
                prevX = x;
                x--;
                break;
            case 77: // Right Arrow key code
                prevX = x;
                x++;
                break;
            case 27: // ESCAPE key
                system("cls");
                throw std::runtime_error("BreakException");
                // goto StartOfGame;
                break;
            default:
                break;
            }
            // Check for collisions with walls or obstacles
            if ((
                    (getASCIIAtPosition(x, y) == -37) || // giving -37 for solid block as ascii value
                    (getCharacterAtPosition(x, y) == '|') ||
                    (getCharacterAtPosition(x, y) == '*')))
            {
                x = prevX;
                y = prevY;
            }

            // CHECKING FOR THW
            for (int i = 0; i < numberOfEnemies; i++)
            {
                encounterEnemy(x, enemiesArray[i].x, y, enemiesArray[i].y);
            }

            // for checking if there is chest at this position.
            for (int i = 0; i < numberOfChests; i++)
            {
                encounterChest(x, chestsArray[i].x, y, chestsArray[i].y);
            }

            // condition to check whether the player has reached out of the maze or not.
            if (getCharacterAtPosition(x, y) == 'E')
            {
                system("cls");
                cout << "Congratulations! You have won the game." << endl;
                cout << "Now proceed to the next level." << endl;
                Sleep(400);

                break;
            } // now display  a portal at the final destination.
        }
    }
    timelimit += 15;
}

void combat(Player *b, Monster *a)
{
    // printing line only for the purpose of formatting

    cout << endl;
    centerText(a->name);
    cout << endl;
    Sleep(5000);
    changeSystemColor();
    string combatOptions[4] = {"Attack", "Defend", "Special Move", "SKIP ENEMY"};
    // change turn of each
    bool turnchanger = true;
    srand(time(NULL));
    while (true)
    {
        system("cls");
        cout << "\033[31m+==========================+\033[0m" << endl;
        cout << "| Monster's Health  = " << a->health << "   |" << endl;
        cout << "| Player's  Health  = " << b->health << "   |" << endl;
        cout << "\033[31m+==========================+\033[0m" << endl;
        // clearing the screen everytime to show the newstats.
        Sleep(2000);

        if (b->health <= 0)
        {
            string lostmessage = "YOU LOST!!!!!!!!!|N YOU WERE UNABLE TO DEAL WITH THE GUARDIAN OF THIS PATH";
            animateText(lostmessage);
            cout << endl;
 
			score  = 0;
			superman.health = 100;
			mazeRows = 8;
			mazeCols = 14;
			cout << "Press any key continue.";
			_getch();
			throw runtime_error("BreakException");
            // exit(0);

            break;
        }
        else if (a->health <= 0)
        {
            string message = "You won the battle. You have killed the Monster. \n  Now you pass to the next level. \nBeware of the future dangers ";
            animateText(message);
            cout << endl;
            break;
        }

        // creating the variables for the task of performing the choices.
        int respons;
        int attack;
        int monsterresponse;
        int monsterattack = 0;
        // asking the user what they want to do and getting their answer.
        // creating a variable bool to change the tufn of the attacks by the Monster and the player.
        if (turnchanger)
        {
            // displayOptions(combatOptions, 3);
            int d = displayOptions(combatOptions, 4);

            switch (d)
            {
            case 0:
            {
                attack = rand() % 10;
                cout << "Monster lost " << attack << " amount of health." << endl;
                a->health -= attack;
                break;
            }
            case 1:
            {
                int heal;
                cout << "you have choosen to defend the attack of the enemy." << endl;
                heal = 1 + rand() % 3;
                if (heal == 1)
                {
                    cout << "you have restored 9 points of health. " << endl;
                    b->health += 9;
                }
                else
                {
                    cout << "defense failed. You have to face the damage." << endl;
                    b->health -= monsterattack;
                }
                break;
            }
            case 2:
            {
                attack = 5 + (rand() % 20);
                string specialAttack = "USING THE SPECIAL ATTACK  OF THE PLAYER"
                                       "\nRight execution will deal massive damage to the enemy.";

                (specialAttack);
                cout << "the damage to the enemy is as follows. " << attack << endl;
                a->health -= attack;
                break;
            }
            case 3:
            {
                string choose = "YOU SOMEHOW MANAGED TO ESCAPE THE ENEMY\n"
                                "BUT DUE TO HARSHILY RUNNING TO ESCAPE YOU LOST 15 POINTS OF HEALTH";
                animateText(choose);
                b->health -= 15;
                // using the return go back to caller function and continue the next portion of hte storyline.
                return;
            }
            default:
                break;
            }
            // giving the boolean variable the signal to change the turn.
            turnchanger = false;
            Sleep(2000);
            system("cls");
        }
        else if (!turnchanger)
        {
            string monterturn = "NOW THIS IS MONSTER'S TURN . \n LET's SEE WHAT THE MONSTER DOES";
            cout << endl;
            animateText(monterturn);
            monsterresponse = 1 + rand() % 3;
            if (monsterresponse == 1)
            {
                monsterattack = 1 + rand() % 10;
                cout << "the Monster attacked and you lost " << monsterattack << "  health." << endl;
                b->health -= monsterattack;
            }
            else if (monsterresponse == 2)
            {
                // increasing the Monster's health  by 5 to make the battle difficult.
                cout << "The Monster healed your attack. and restored 5 points of health" << endl;
                a->health += 5;
            }
            else
            {
                cout << "The Monster used its special ability, which deals massive damage!" << endl;
                monsterattack = 15;
                cout << "now you have lost " << monsterattack << " of health." << endl;
                b->health -= monsterattack;
            }
            // giveng the turn back to the player.
            turnchanger = true;
            Sleep(6000);
            system("cls");
        }
    }
}
void movePlayer(int x, int y, char c)
{
    // changeSystemColor();
    enableBGText(BACKGROUND_SILVER);

    // Character representing the player
    while (true)
    {
        gotoxy(x, y);
        std::cout << c;
        // using the _kbhit to detect which key is being hit by hte uer.
        if (_kbhit())
        {
            char key = _getch();
            gotoxy(x, y);
            std::cout << ' ';
            // Clear previous position

            int prevX = x;

            // Move the player based on arrow key input
            int prevY = y;
            switch (key)
            {
            case 72: // Up Arrow key code
                prevY = y;
                y--;
                break;
            case 80: // Down Arrow key code
                prevY = y;
                y++;
                break;
            case 75: // Left Arrow key code
                prevX = x;
                x--;
                break;
            case 77: // Right Arrow key code
                prevX = x;
                x++;
                break;
            case 27: // ESCAPE key
                system("cls");
                throw std::runtime_error("BreakException");
                // goto StartOfGame;
                break;
            default:
                break;
            }

            if (
                (getASCIIAtPosition(x, y) == -37) || // getting -37 for solid block as ascii value
                (getCharacterAtPosition(x, y) == 'S'))
            {
                x = prevX;
                y = prevY;
            }

            // for checking if there is enemy at this position.
            for (int i = 0; i < numberOfEnemies; i++)
            {
                encounterEnemy(x, enemiesArray[i].x, y, enemiesArray[i].y);
            }
            // for checking if there is chest at this position.
            for (int i = 0; i < numberOfChests; i++)
            {
                encounterChest(x, chestsArray[i].x, y, chestsArray[i].y);
            }
            // introducing the createria for facing a Monster.
            // this feature will only be able if the player is playing the storyline mode

            // if (levelno >= 5 && levelno < 11)
            if (levelno >= 11 && levelno < 11)
            {
                if (getCharacterAtPosition(x, y) == 'E' && response == 1)
                {
                    system("cls");
                    centerText("+=====================================================================+");
                    cout << endl;
                    centerText(" get ready to face the Monster that protects the endway of this path.");
                    cout << endl;
                    Monster currentmonster = monsters[e];
                    combat(&superman, &currentmonster);
                    Sleep(2000);
                    system("cls");
                    e++;

                    break;
                }
            }

            // condition to check whether the player has reached out of the maze or not.
            if (getCharacterAtPosition(x, y) == 'E')
            {
                system("cls");
                cout << "Congratulations! You have won the game." << endl;
                cout << "Now proceed to the next level." << endl;
                Sleep(400);

                break;
            } // now display  a portal at the final destination.
        }
    }
}

void storyline()
{
    system("cls");
    changeSystemColor();
    loadingbar();

    system("cls");
    // giving the user the introduction of the storyline game.
    string story = "WELCOME TO STORYLINE OF THE GAME \n NOW CHOOSE A SPECIAL CHARACTER TO PLAY WITH.\n";
    animateText(story);
    cin >> superman.player;
    Sleep(50);
    system("cls");

    string introduction = "\nThis story is about a lost survivor who has lost himself in the forest. \n in order to reach out of the forest he has to pass through different mazes. \nIf he succesfully cleares all the mazes, then he finds himself out of the maze. \nThe game starts in a HUT. Player's is looking for the path out can you help him. ";
    for (char &c : introduction)
    {
        c = toupper(c);
    }

    animateText(introduction);
    cout << endl;
    system("cls");

    // cout << "\nThis story is about a lost survivor who has lost himself in the forest. " << endl;
    // cout << "in order to reach out of the forest he has to pass through different mazes." << endl;
    // cout << "If he succesfully cleares all the mazes, then he finds himself out of the maze. " << endl;
    // cout << "The game starts in a HUT. Player's is looking for the path out can you help him. " << endl;
    // system("cls");
    while (true)
    {
        // using a switch case statement to handle the game based on the level no.

        if (levelno == 1)
        {
            changeSystemColor();
            numberOfEnemies = 3;
            string level1Story = "Level 1: The Monstrous Hut\n"
                                 "In the heart of the forest lies an old hut, shrouded in mystery. Here,\n "
                                 "you must navigate through hidden passages and solve ancient puzzles to find the exit.\n";
            vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
            animateText(level1Story);
            gotoxy(0, 4);
            displayGame(maze);
            movePlayer(superman.x, superman.y, superman.player);
            mazeRows += 1;
            mazeCols += 2;
            levelno++;
            system("cls");
            loadingbar();
        }
        else if (levelno == 2)
        {
            score += 10;
            changeSystemColor();
            numberOfEnemies = 5;
            system("cls");
            string level2Story = "Level 2: Entering the Jungle\n"
                                 "Emerging from the hut, you find yourself at the edge of a dense jungle. \n"
                                 "Your senses tingle as you step into the green maze,\n with unknown dangers lurking in the shadows.\n";
            animateText(level2Story);
            gotoxy(0, 4);
            vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
            displayGame(maze);
            movePlayer(superman.x, superman.y, superman.player);
            mazeRows += 2;
            mazeCols += 3;
            levelno++;
        }
        else if (levelno == 3)
        {
            score += 10;
            changeSystemColor();
            numberOfEnemies = 7;
            system("cls");
            string level3Story = "Level 3: Jungle Survival\n"
                                 "Deeper into the jungle, survival becomes a challenge. \n"
                                 "Here, the maze tests your ability to find resources and\n protect yourself against the wild inhabitants of the forest.\n";
            animateText(level3Story);
            gotoxy(0, 4);
            vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
            displayGame(maze);
            movePlayer(superman.x, superman.y, superman.player);
            mazeRows += 2;
            mazeCols += 3;
            levelno++;
        }
        else if (levelno == 4)
        {
            score += 10;
            changeSystemColor();
            numberOfEnemies = 9;
            system("cls");
            string level4Story = "Level 4: Reaching the River\n"
                                 "Beyond the jungle lies a vast river. The maze now involves crossing treacherous waters \n"
                                 "and navigating along its unpredictable banks, full of slippery stones and hidden paths.\n";
            animateText(level4Story);
            gotoxy(0, 4);
            vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
            displayGame(maze);
            movePlayer(superman.x, superman.y, superman.player);
            mazeRows += 2;
            mazeCols += 3;
            levelno++;
        }
        else if (levelno == 5)
        {
            score += 10;
            changeSystemColor();
            numberOfEnemies = 11;
            system("cls");
            string level5Story = "Level 5: Entering the Dungeon\n"
                                 "As you travel, you discover an entrance to an underground dungeon. \n"
                                 "In this level, the maze becomes a labyrinth of dark, \nnarrow tunnels filled with ancient traps and cryptic symbols.\n";
            animateText(level5Story);
            gotoxy(0, 4);
            vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
            displayGame(maze);
            movePlayer(superman.x, superman.y, superman.player);
            mazeRows += 2;
            mazeCols += 2;
            levelno++;
        }
        else if (levelno == 6)
        {
            score += 10;
            changeSystemColor();
            numberOfEnemies = 13;
            system("cls");
            string level6Story = "Level 6: The Dungeon Part 2\n"
                                 "Deeper in the dungeon, the challenges intensify. \n"
                                 "The maze here is more complex, with dead ends and hidden doors,\n as you delve into the heart of the underground world.\n";
            animateText(level6Story);
            gotoxy(0, 4);
            vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
            displayGame(maze);
            movePlayer(superman.x, superman.y, superman.player);
            mazeRows += 2;
            mazeCols += 2;
            levelno++;
        }
        else if (levelno == 7)
        {
            score += 10;
            changeSystemColor();
            numberOfEnemies = 15;
            system("cls");
            string level7Story = "Level 7: Death Valley\n"
                                 "Escaping the dungeon, you find yourself in Death Valley, a desolate landscape. \n"
                                 "Here, the maze is a series of dry canyons and treacherous cliffs,\n with extreme conditions testing your endurance.\n";
            animateText(level7Story);
            gotoxy(0, 4);
            vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
            displayGame(maze);
            movePlayer(superman.x, superman.y, superman.player);
            mazeRows += 2;
            mazeCols += 2;
            levelno++;
        }
        else if (levelno == 8)
        {
            score += 10;
            changeSystemColor();
            numberOfEnemies = 17;
            system("cls");
            string level8Story = "Level 8: Death Bridge\n"
                                 "Your path leads you to a precarious bridge. In this level, \n"
                                 "you must carefully navigate across while solving puzzles\n that control the bridge's stability and path.\n";
            animateText(level8Story);
            gotoxy(0, 4);
            vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
            displayGame(maze);
            movePlayer(superman.x, superman.y, superman.player);
            mazeRows += 3;
            mazeCols += 2;
            levelno++;
        }
        else if (levelno == 9)
        {
            score += 10;
            changeSystemColor();
            numberOfEnemies = 19;
            system("cls");
            string level9Story = "Level 9: Dead End\n"
                                 "Nearing the end of your journey, you enter a maze that seems to have no exit. \n"
                                 "This level requires clever problem-solving and \nintuition to find the hidden passage leading out.\n";
            animateText(level9Story);
            gotoxy(0, 4);
            vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
            displayGame(maze);
            movePlayer(superman.x, superman.y, superman.player);
            mazeRows += 4;
            mazeCols += 2;
            levelno++;
        }
        else if (levelno == 10)
        {
            score += 10;
            changeSystemColor();
            numberOfEnemies = 21;
            system("cls");
            string level10Story = "Level 10: Path to the Earth\n"
                                  "In the final challenge, you must use all your acquired skills\n and knowledge to navigate the most intricate maze. \n"
                                  "Success here means finding the path that leads back to the familiar world.\n";
            animateText(level10Story);
            gotoxy(0, 4);
            vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
            displayGame(maze);
            movePlayer(superman.x, superman.y, superman.player);
            // if the user completes the game then, displaying the user the message showing the victory message.
            system("cls");

            cout << "CONGRATULTIONS, You have Completed the game MR." << username << endl;
            cout << "You have now reached back to the Earth. " << endl;
        }
        if (levelno == 11)
        {
            score += 10;
            break;
        }
    }
}
void timetrail()

{
    changeSystemColor();

    system("cls");
    loadingbar();
    system("cls");
    // giving the user the introduction when he enters the maze game.
    string timetrailintro = "WELCOME TO THE TIMETRAIL MODE OF THE GAME. \n"
                            "IN THIS MODE YOU WILL BE GIVEN SPECIFIC TIME TO SOLVE THE MAZE.\n"
                            "IF YOU SOLVED THE MAZE IN THE GIVEN TIME THEN YOU WILL PROCEED TO THE NEXT MAZE.\n"
                            "THIS WILL CONTINUE UNTIL YOUR HEALTH BECOMES ZERO OR YOU RAN OUT OF TIME\n"
                            "WE HOPE THAT YOU WILL ENJOY THIS MODE OF THE GAME.\n";
    animateText(timetrailintro);
    // making the predefined function
    superman.player = 'P';
    while (true)
    {
        system("cls");

        gotoxy(2, 9);
        vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
        displayMaze(maze);
        displayDialogueBox();
        movePlayerwithtimer(superman.x, superman.y, superman.player);

        // incresing the score by 20 when the user clears a maze.
        score += 20;
        // updatintg the size of the maze every time the user survives the game.
        mazeRows += 2;
        mazeCols += 3;

        // After the maze is displayed, start player movement
    }
}
void classic()
{
    changeSystemColor();

    system("cls");
    loadingbar();
    system("cls");
    centerText("WELCOME TO THE CLASSIC MODE OF THIS GAME.");
    cout << endl;
    centerText("+=========================================================================+");
    cout << endl;
    centerText("||");
    cout << endl;
    centerText("In this mode, you have to survive as long as you can.");
    cout << endl;
    centerText("The Rules For this mode are Below : ");
    cout << endl;
    centerText("-> No revival");
    cout << endl;
    centerText("-> Score by solving only.");
    cout << endl;
    centerText("||");
    cout << endl;
    centerText("+=========================================================================+");
    cout << endl;
    Sleep(3000);
    system("cls");
    // asking the user to enter the character with which he wants to play the game.
    cout << "+=================================+" << endl;
    cout << "|                                 |" << endl;
    cout << "|      enter your character :     |" << endl;
    cout << "|                                 |" << endl;
    cout << "+=================================+" << endl;
    superman.player = _getch();
    system("cls");
    // maiking the use of the system cls to create an illusion that character is entered within the box.
    cout << "+=================================+" << endl;
    cout << "|                                 |" << endl;
    cout << "|    enter your character : " << superman.player << "     |" << endl;
    cout << "|                                 |" << endl;
    cout << "+=================================+" << endl;

    Sleep(1000);
    while (superman.health != 0)
    {
        // clearing the screen every time the playerr wins the game.
        system("cls");
        Sleep(900);
        gotoxy(0, 0);
        /*cout << "+=================================+" << endl;
        cout << "|       Health Bar = " << superman.health << "         |" << endl;
        cout << "|       current score = " << score << "         |" << endl;
        cout << "+=================================+" << endl;*/

        // moving the cursor on the top to display the score on the right top most corner of the console.

        vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
        gotoxy(1, 4);
        displayHealth();
        changeSystemColor();
        displayMaze(maze);
        displayDialogueBox();
        movePlayer(superman.x, superman.y, superman.player);
        // incresing the score by 20 when the user clears a maze.
        score += 20;
        // updatintg the size of the maze every time the user survives the game.
        mazeRows += 1;
        mazeCols += 2;
    }
}
void finalBoss()
{

    string news;
    centerText("+========================================+");
    string warning = " HE HE HOO HOOO HAAA HAAA HAAA  \n   YOU HAVE DONE A GREAT JOB SOO FAR   \n BUT NOW IT IS TIME TO DIE .\n AND THE BATTLE BEGINS";
    for (char &c : warning)
    {
        news += c;
        Sleep(800);
        centerText(news);
    }

    system("cls");
}
