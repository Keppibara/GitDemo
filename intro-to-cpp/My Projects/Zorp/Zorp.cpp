#include <iostream>
#include <Windows.h>
#include <random>	
#include <time.h>

const char* CSI = "\x1b[";
const char* TITLE = "\x1b[5;20h";
const char* INDENT = "\x1b[5c";
const char* YELLOW = "\x1b[93m";
const char* MAGENTA = "\x1b[95m";
const char* RESET_COLOR = "\x1b[0m";
const char* SAVE_CURSOR_POS = "\x1b[s";
const char* RESTORE_CURSOR_POS = "\x1b[u";

void main()
{
	const int EMPTY = 0;
	const int ENEMY = 1;
	const int TREASURE = 2;
	const int FOOD = 3;
	const int ENTRANCE = 4;
	const int EXIT = 5;
	const int MAX_RANDOM_TYPE = FOOD+1;

	const int MAZE_WIDTH = 10;
	const int MAZE_HEIGHT = 6;

	//Set output mode to handle virtual terminal sequences
	DWORD dwMode = 0;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);

	int height = 0;
	char firstLetterOfName = 0;
	int avatarHP = 0;

	// create a 2d array
	int rooms[MAZE_HEIGHT][MAZE_WIDTH];
		srand(time(nullptr));

		// fill the arrays with random room types
		for (int y = 0; y < MAZE_HEIGHT; y++)
		{
			for (int x = 0; x < MAZE_WIDTH; x++) {
				rooms[y][x] = rand() % MAX_RANDOM_TYPE;
			}
		}
		// set the entrance and exit of the maze
		rooms[0][0] = ENTRANCE;
		rooms[MAZE_HEIGHT - 1][MAZE_WIDTH - 1] = EXIT;

	std::cout << TITLE << MAGENTA << "Welcome to ZORP!" << RESET_COLOR << std::endl;
	std::cout << INDENT << "ZORP is a game of adventure, danger, and low cunning." << std::endl;
	std::cout << INDENT << "It is definitely not related to any other text-based adventure game." << std::endl << std::endl;

	std::cout << INDENT << "First, some questions..." << std::endl;
	
	// save cursor position
	std::cout << SAVE_CURSOR_POS;
	
	// output the map
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		std::cout << INDENT;
		for (int x = 0; x < MAZE_WIDTH; x++) {
			std::cout << "[ " << rooms[y][x] << " ] ";
		}
    	std::cout << std::endl;
	}
	// move the cursor back to the top of the map
	std::cout << RESTORE_CURSOR_POS;

	std::cout << INDENT << "How tall are you, in centimeters? " << INDENT << YELLOW;

	std::cin >> height;
	std::cout << RESET_COLOR << std::endl;

	if (std::cin.fail()) 
	{
		std::cout << INDENT << "You have failed the first challenge and are eaten by a grue." << std::endl;

	}
	else
	{
		std::cout << INDENT << "You entered " << height << std::endl;
	}

	// Clear input buffer
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	// Move the cursor to the start of the 1st question
	std::cout << RESTORE_CURSOR_POS;
	// delete the next 4 lines of text
	std::cout << CSI << "4M";

	std::cout << INDENT << "What is the first letter of your name? " << INDENT << YELLOW;

	std::cin >> firstLetterOfName;
	std::cout << RESET_COLOR << std::endl;

	if (std::cin.fail() || !isalpha(firstLetterOfName))
	{
		std::cout << INDENT << "You have failed the second challenge and are eaten by a grue." << std::endl;
	}
	else
	{
		std::cout << INDENT << "You entered " << firstLetterOfName << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	// move the cursor to the start of the !st question
	std::cout << RESTORE_CURSOR_POS;
	std::cout << CSI << "A"; // cursor up 1
	std::cout << CSI << "4M"; // delete the next 4 lines of text

	if (firstLetterOfName != 0)
	{
		avatarHP = (float)height / (firstLetterOfName * 0.02f);
	}
	else
	{
		avatarHP = 0;
	}
	
	std::cout << INDENT << "Using a complex deterministic algorithm, it has been calculated that you have " << avatarHP << " hit point(s)." << std::endl;

	std::cout << std::endl << INDENT << "Press 'Enter' to exit the program." << std::endl;
	std::cin.get();
    return;
}