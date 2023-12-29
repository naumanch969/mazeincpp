#pragma once
#include "fundamentals.h"
#include "helper.h"
#include "display.h"
#include "maze.h"
#include "menu.h"
#include "modes.h"

void game()
{
	while (true)    // to restart the game if user press esc while playing
	{

		// const char *filePath = "C:/Users/Track Computers/Desktop/track.wav";
		// playAudio(filePath);
		try
		{
			changeSystemColor();
			mainMenu();

			system("cls");

			string modeOptions[3] = { "Classic", "Storyline", "Timetrial" };

			// 	 //const char *filepath = "c:/users/track computers/desktop/track.wav";
			// 	 //playaudio(filepath);

			// 	//centerText("Welcome to the game : MAZE QUEST the enigmatic lybrinth,");
			// 	string welcomeline = "WELCOME TO THE GAME ::: THE MAZE QUEST :: THE ENIGMATIC LYBRINTH";
			// 	animateText(welcomeline);
			// 	 cout << endl;
			// 	 Sleep(1100);
			// 	 system("cls");
			// 	 centerText(" ----- |    | |----    ||    /|   /|   ____ -----     --  |   | -----   /  ----- ");
			// 	 cout << endl;
			// 	 centerText("   |   |____| |____    | |  / |  /__|     / |____    /  | |   | |___   /_    |   ");
			// 	 cout << endl;
			// 	 ;
			// 	 centerText("   |   |    | |____    |  |/  | /    |   /  |____    |__/ |___/ |____   /    |   ");
			// 	 cout << endl;
			// 	 centerText("   |   |    |          |      |/      | /___            |              /     |   ");
			// 	 cout << endl;
			// 	 cout << "press any key to continue. ";
			// 	 cin.ignore();
			// 	 enter = _getch();
			// 	 loadingbar();
			// 	 system("cls");
			// 	 //asking the user to enter the name by initializing the global variable.
			// 	 string askName = "PLEASE ENTER YOUR GOOD NAME TO CONTINUE THE GAME. ";
			// 	 cout << endl;`
			// 	 // username is a global variable that is defined up in the section.
			// 	 cin.ignore();
			// 	 animateText(askName);
			// 	 getline(cin, username);
			// 	 system("cls");

			// 	 // it depends upon the user that what username he chooses.
			// 	 // convertint the string to the uppercase and then displaying it in on the console window.
			// 	 string abc = "WELCOME TO THE GAME MR.";
			// 	 for (char& c : username) {
			// 		 c = toupper(c);
			// 	 }
			// 	 animateText(abc);
			// 	 animateText(username);
			// 	 // using the cin.ignore to empty the console buffer.
			// 	 cin.ignore();
			// 	 Sleep(500);

			// 	 system("cls");
			// 	 // cin >> response;
			// 	string modeOptions[3] = { "Classic", "Storyline", "Timetrial" };

			response = chooseMode();
			cout << response;
			switch (response)
			{
			case 0:
				classic();
				break;
			case 1:
				storyline();
				break;
			case 2:
				timetrail();
				break;
			}
		}
		catch (const std::runtime_error& e)
		{
			if (e.what() == std::string("BreakException"))
			{
				std::cout << "Breaking out of everything!" << std::endl;
			}
			else
			{
				throw; // Re-throw other exceptions
			}
		}

	} // main while


		ofstream out("Source2.txt", ios::app);
		if (out.is_open())
		{
			out << score << endl;

			out.flush();
			out.close();
		}

		else
			cout << "unable to load file ";
}