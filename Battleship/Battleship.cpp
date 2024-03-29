#include <iostream>
#include <string>

int AddShipx(int _l);
int AddShipy(int _l);
void PrintBoard(int _w, int _l);

int main()
{
	const int length = 5;
	const int width = 5;
	int x = 0;
	int y = 0;
	int Board[width][length];
	bool AddShip = true;
	bool P2Turn = true;
	int numShips = 0;

	//Set all board values to 0
	for (int i = 0; i < length; i++)
	{
		Board[i][i] = 0;
		for (int j = 0; j < width; j++)
		{
			Board[j][i] = 0;
		}
	}

	// Constructs Board
	int n = 0;
	std::cout << "  ";
	// Prints the x axis number line
	for (int i = 1; i < length + 1; i++)
	{
		std::cout << "  " << i;
	}
	// Prints the rest of the board
	for (int i = 0; i < length; i++)
	{
		n++;
		std::cout << "\n" << n << " ";
		std::cout << "|" << Board[0][i] << "|";
		for (int j = 1; j < width; j++)
		{
			std::cout << "|" << Board[j][i] << "|";
		}
	}
	std::cout << std::endl;

	while (AddShip)
	{
		//Take in input from user
		Board[AddShipx(width)][AddShipy(length)] = 1;

		// Reprints new Board
		int n = 0;
		std::cout << "  ";
		// Prints the x axis number line
		for (int i = 1; i < length + 1; i++)
		{
			std::cout << "  " << i;
		}
		// Prints the rest of the board
		for (int i = 0; i < length; i++)
		{
			n++;
			std::cout << "\n" << n << " ";
			std::cout << "|" << Board[0][i] << "|";
			for (int j = 1; j < width; j++)
			{
				std::cout << "|" << Board[j][i] << "|";
			}
		}
		std::cout << std::endl;
		numShips++;

		// Get out of loop
		std::cout << "Would you like to add another ship?\n1. Yes\n2. No\n";
		int input = 0;
		std::cin >> input;
		while (input < 1 || input > 2)
		{
			std::cout << "Sorry this is not a valid input. Please try again...\n";
			std::cin >> input;
		}
		if (input == 2)
		{
			AddShip = false;
		}
		system("cls");
	}

	// 2nd Player -----------------------------------------------------------------
	system("cls");
	std::cout << "Player 2's Turn\n\n";
	int Board2[width][length];
	//Sets board to 0
	for (int i = 0; i < length; i++)
	{
		Board2[i][i] = 0;
		for (int j = 0; j < width; j++)
		{
			Board2[j][i] = 0;
		}
	}

	bool Guess = true;
	while (Guess) 
	{
		
		// Reprints new Board
		int m = 0;
		std::cout << "  ";
		// Prints the x axis number line
		for (int i = 1; i < length + 1; i++)
		{
			std::cout << "  " << i;
		}
		// Prints the rest of the board
		for (int i = 0; i < length; i++)
		{
			m++;
			std::cout << "\n" << m << " ";
			std::cout << "|" << Board2[0][i] << "|";
			for (int j = 1; j < width; j++)
			{
				std::cout << "|" << Board2[j][i] << "|";
			}
		}
		std::cout << std::endl;

		// Player guesses where a ship is
		std::cout << "Enter x cord for ship location\nx = ";
		int px = 0;
		while (px < 1 || px > width)
		{
			std::cin >> px;
			if (px < 1 || px > width)
			{
				std::cout << "This is not a valid answer. Please try again.\n";
				std::cout << "x = ";
			}
		}
		std::cout << "Enter y cord for ship location\ny = ";
		int py = 0;
		while (py < 1 || py > length)
		{
			std::cin >> py;
			if (py < 1 || py > length)
			{
				std::cout << "This is not a valid answer. Please try again.\n";
				std::cout << "y = ";
			}
		}

		// subtract one cuss array are 0 based
		py -= 1;
		px -= 1;

		system("cls");

		// Test if player hit
		if (Board[px][py] == 1)
		{
			std::cout << "HIT! You hit an enemy shit.\n";
			Board2[px][py] = 1;
			numShips--;
		}
		// Test if player near miss
		else if (Board[px + 1][py] == 1 || Board[px - 1][py] == 1 || Board[px + 1][py + 1] == 1 || Board[px + 1][py - 1] == 1 || Board[px][py + 1] == 1 || Board[px][py-1] == 1 || Board[px-1][py+1] == 1 || Board[px-1][py-1] == 1)
		{
			std::cout << "Near Miss. You are right next to a ship.\n";
			Board2[px][py] = 2;
		}
		// Test if player miss
		else if (Board[px][py] != 1)
		{
			std::cout << "Miss. You are no where near a ship.\n";
			Board2[px][py] = 2;
		}

		if (numShips == 0)
		{
			std::cout << "You found all the ships. Game Over\n";
			Guess = false;
		}
	}

	
	// End of program
	std::cout << std::endl;
	system("PAUSE");
	return 0;
}

int AddShipx(int _w)
{
	int x = 0;
	
	std::cout << "Where would you like to put a ship (x,y)\nx = ";
	while (x < 1 || x > _w)
	{
		std::cin >> x;
		if (x < 1 || x > _w)
		{
			std::cout << "This is not a valid answer. Please try again.\n";
			std::cout << "x = ";
		}
	}
	return x-1;
}

int AddShipy(int _l)
{
	int y = 0;
	std::cout << "y = ";
	while (y < 1 || y > _l)
	{
		std::cin >> y;
		if (y < 1 || y > _l)
		{
			std::cout << "This is not a valid answer. Please try again.\n";
			std::cout << "y = ";
		}
	}
	return y-1;
}