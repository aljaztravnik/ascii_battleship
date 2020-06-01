#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void makeEmpty(char tabela[][6], int n)
{
	for(unsigned short i = 0; i < n; i++)
		for(unsigned short j = 0; j < n; j++)
			tabela[i][j] = 'O';
}

void fillRandom(char compField[][6])
{
	bool navpicno = rand() % 2;
	unsigned short posGlavaX, posGlavaY;
	if(navpicno)
	{
		posGlavaX = rand() % 6;
		posGlavaY = rand() % (5 - 1) + 1;
		if(posGlavaY - 1 >= 0 && posGlavaY + 1 <= 5)
		{
			compField[posGlavaY][posGlavaX] = 'X';
			compField[posGlavaY - 1][posGlavaX] = 'X';
			compField[posGlavaY + 1][posGlavaX] = 'X';
		}
	}
	else
	{
		posGlavaX = rand() % (5 - 1) + 1;
		posGlavaY = rand() % 6;
		if(posGlavaX - 1 >= 0 && posGlavaX +1 <= 5)
		{
			compField[posGlavaY][posGlavaX] = 'X';
			compField[posGlavaY][posGlavaX - 1] = 'X';
			compField[posGlavaY][posGlavaX + 1] = 'X';
		}
	}
	for(unsigned short i = 0; i < 2; i++)
	{
		navpicno = rand() % 2;
		if(navpicno)
		{
			while(true)
			{
				posGlavaX = rand() % 6;
				posGlavaY = rand() % (6 - 1) + 1;
				if(compField[posGlavaY][posGlavaX] != 'X' && compField[posGlavaY - 1][posGlavaX] != 'X')
				{
					compField[posGlavaY][posGlavaX] = 'X';
					compField[posGlavaY - 1][posGlavaX] = 'X';
					break;
				}
			}
		}
		else
		{
			while(true)
			{
				posGlavaX = rand() % (6 - 1) + 1;
				posGlavaY = rand() % 6;
				if(compField[posGlavaY][posGlavaX] != 'X' && compField[posGlavaY][posGlavaX - 1] != 'X')
				{
					compField[posGlavaY][posGlavaX] = 'X';
					compField[posGlavaY][posGlavaX - 1] = 'X';
					break;
				}
			}
		}
	}
}

unsigned short makeRandomGuess(char playerField[][6])
{
	unsigned short xPos = rand() % 6;
	unsigned short yPos = rand() % 6;
	if(playerField[yPos][xPos] == 'X')
	{
		playerField[yPos][xPos] = 'H';
		std::cout << "Racunalnik je zadel vaso ladjo!\n"; 
		return 1;
	}
	std::cout << "Racunalnik je zgresil vase ladjevje.\n";
	return 0;
}

void fillPlayer(char playerField[][6])
{
	bool prosto = false, navpicno = true;
	unsigned short xPos, yPos;
	std::cout << "Vnesi orientacijo bojne ladje z 3 mesti [1 = navpicno, 0 = vodoravno]: ";
	std::cin >> navpicno;
	if(navpicno)
	{
		while(true)
		{
			std::cout << "Vnesi X pozicijo sredine ladje [0 - 5], Y pozicijo [1 - 4]:\n";
			std::cin >> xPos >> yPos;
			if(xPos >= 0 && xPos <= 5 && yPos >= 1 && yPos <= 4) break;
			else std::cout << "Napacen vnos.\n";
		}
		playerField[yPos][xPos] = 'X';
		playerField[yPos + 1][xPos] = 'X';
		playerField[yPos - 1][xPos] = 'X';
	}
	else
	{
		while(true)
		{
			std::cout << "Vnesi X pozicijo sredine ladje [1 - 4], Y pozicijo [0 - 5]:\n";
			std::cin >> xPos >> yPos;
			if(xPos >= 1 && xPos <= 4 && yPos >= 0 && yPos <= 5) break;
			else std::cout << "Napacen vnos.\n";
		}
		playerField[yPos][xPos] = 'X';
		playerField[yPos][xPos + 1] = 'X';
		playerField[yPos][xPos - 1] = 'X';
	}
	for(unsigned short i = 0; i < 2; i++)
	{
		std::cout << "Vnesi orientacijo bojne ladje z 2 mesti [1 = navpicno, 0 = vodoravno]: ";
		std::cin >> navpicno;
		if(navpicno)
		{
			while(true)
			{
				std::cout << "Vnesi X pozicijo ladje [0 - 5], Y pozicijo [1 - 5]:\n";
				std::cin >> xPos >> yPos;
				if(xPos >= 0 && xPos <= 5 && yPos >= 1 && yPos <= 5)
				{
					if(playerField[yPos][xPos] != 'X' && playerField[yPos - 1][xPos] != 'X')
					{
						playerField[yPos][xPos] = 'X';
						playerField[yPos - 1][xPos] = 'X';
						break;
					}
				}
				else
				{
					std::cout << "Napacen vnos.\n";
					continue;
				}
			}
		}
		else
		{
			while(true)
			{
				std::cout << "Vnesi X pozicijo ladje [1 - 5], Y pozicijo [0 - 5]:\n";
				std::cin >> xPos >> yPos;
				if(xPos >= 1 && xPos <= 5 && yPos >= 0 && yPos <= 5)
				{
					if(playerField[yPos][xPos] != 'X' && playerField[yPos][xPos - 1] != 'X')
					{
						playerField[yPos][xPos] = 'X';
						playerField[yPos][xPos - 1] = 'X';
						break;
					}
				}
				else
				{
					std::cout << "Napacen vnos.\n";
					continue;
				}
			}
		}
	}
}

unsigned short makeGuess(char compField[][6])
{
	unsigned short xPos, yPos;
	std::cout << "Vnesi X pozicijo ladje [0 - 5], Y pozicijo [0 - 5]:\n";
	while(true)
	{
		std::cin >> xPos >> yPos;
		if(xPos >= 0 && xPos <= 5 && yPos >= 0 && yPos <= 5) break;
		else std::cout << "Napacen vnos.\n";
	}
	if(compField[yPos][xPos] == 'X')
	{
		compField[yPos][xPos] = 'H';
		std::cout << "Zadeli ste racunalnikovo ladjo!\n"; 
		return 1;
	}
	std::cout << "Zgresili ste racunalnikovo ladjevje.\n";
	return 0;
}

void printPolje(char compField[][6], char playerField[][6])
{
	std::cout << "  COMPUTER FIELD:                    PLAYER FIELD:\n";
	for(unsigned short i = 0; i < 6; i++)
	{
		for(unsigned short j = 0; j < 6; j++)
			std::cout << std::setw(3) << compField[i][j];
		std::cout << "              ";
		for(unsigned short j = 0; j < 6; j++)
			std::cout << std::setw(3) << playerField[i][j];
		std::cout << '\n';
	}
	std::cout << '\n';
}

int main()
{
	srand(time(NULL));
	char playerField[6][6];
	char compField[6][6];
	unsigned short playerHitCount = 0, compHitCount = 0;
	int i = 0;

	makeEmpty(compField, 6);
	makeEmpty(playerField, 6);
	fillRandom(compField);
	fillPlayer(playerField);
	printPolje(compField, playerField);
	while(compHitCount < 7 && playerHitCount < 7)
	{
		if(i % 2 == 0)	playerHitCount += makeRandomGuess(playerField);
		else compHitCount += makeGuess(compField);
		printPolje(compField, playerField);
		i++;
	}
	return 0;
}