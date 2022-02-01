#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

#define RIGHT_ARROW 16
#define DOWN_ARROW 31
#define TRANSPARENT 176
#define OPAQUE 178
#define MINE_SWEAPER_INDEX 1




int playMineRound();

void initBoard(int size, char board[size][size]);
void plantMine(int size, char board[size][size], int difficulty);

void displayBoard(int size, char board[size][size], int x, int y, int selected);
void printBlankBoard(int size, char mineBoard[size][size]);

int checkDone(int size, char mineBoard[size][size]);
int localMines(int size, char mineBoard[size][size], char Board[size][size], int x, int y, int* points);
int sweapMines(int size, char mineBoard[size][size], char board[size][size], int x, int y, int* points);
int clearMines(int size, char mineBoard[size][size], char board[size][size], int x, int y, int* points);

char intToChar(int number);
int getMove();
void pressKey();
int YesNo();

void howToPlay();

int firstSelection(struct player *currentAccount);
int secondSelection();
int thirdSelection();

void writeAccount(struct player *currentAccount);




int playMineSweaper(struct player* currentAccount)
{
	int size, difficulty, points, alive, playing = 1, YN;
	int input;

	firstSelection(currentAccount);
	size = secondSelection();
	difficulty = thirdSelection();

	while(playing == 1)
	{
		alive = 1;
		points = 0;

		currentAccount->attempts[MINE_SWEAPER_INDEX] = currentAccount->attempts[MINE_SWEAPER_INDEX] + 1;

		while(alive == 1)
		{
			alive = playMineRound(&points,size, difficulty);
			if(alive == 1)
			{
				printf("\n\n");
				system("cls");
				do
				{
					printf("Well Done Press Enter to procced to next board or ESC to return to menue:\n");
					input = getMove();
				}while(input != 5 && input != 6);

				if(input == 6)
				{
					alive = 0;
				}
			}
		}

		system("cls");
		printf("On your %dth attempt of the game you scored %d points:\n\n", currentAccount->attempts[MINE_SWEAPER_INDEX], points);
		if(points > currentAccount->scores[MINE_SWEAPER_INDEX])
		{
			printf("New High Score\n\n");
			currentAccount->scores[MINE_SWEAPER_INDEX] = points;
		}

		else if(points == currentAccount->scores[MINE_SWEAPER_INDEX])
		{
			printf("Almose a New High Score\n\n");
		}
		pressKey();

		printf("\n\n");
		writeAccount(currentAccount);
		system("cls");
		printf("Do you want to play again:");
		YN = YesNo();
		if(YN == 1)
		{
			playing = 0;
		}
	}
}


int playMineRound(int *points, int size, int difficulty)
{
	char board[size][size];
	char primedBoard[size][size];
	
	int input, counter;

	int playing = 1, y = 0, x = 0, selection = 0, con = 1;
	int selected = 0;

	char selectionOptions[3][20] = {
		"Clear",
		"Flag ",
		"Back "
	};


	initBoard(size,board);

	initBoard(size,primedBoard);
	plantMine(size, primedBoard, difficulty);


	while(playing == 1)
	{
		con = 1;
		selected = 0;
		displayBoard(size, board, x,y, selected);
		printf("\n\n\n");
		printf("\nPress Enter to select this cell:");
		printf("\n\n\n");

		input = getMove();
		// changing x, y values
		if(input == 1)
		{
			y --;
		}

		else if(input == 2)
		{
			y ++;
		}

		else if(input == 3)
		{
			x --;
		}

		else if(input == 4)
		{
			x ++;
		}


		// making sure x,y values are within the board
		if(y >= size)
		{
			y = 0;
		}

		else if(y < 0)
		{
			y = size - 1;
		}

		if(x >= size)
		{
			x = 0;
		}

		else if(x < 0)
		{
			x = size - 1;
		}

		// other i/o things



		if(input == 5)
		{
			selected = 1;

			if(primedBoard[y][x] == '~')
			{
				printf("\n\n");
				system("cls");
				printf("You have already cleared this cell:\n");
				pressKey();
				con = 0;
				selected = 0;
			}

			else if(board[y][x] == 'F')
			{
				printf("You have flagged this cell:");
				do
				{
					printf("\nPress enter to contino or ESC to return to board:");
					input = getMove();
				}while(input != 5 && input != 6);
			
				if(input == 6)
				{
					con = 0;
					selected = 0;
				}
			}

			if(con == 1)
			{
				do
				{
					displayBoard(size, board, x,y, selected);
					printf("Chose what you would like to do: ");

					printf("\n\t      ----------\n");
					for(counter = 0; counter < 3; counter ++)
					{
						printf("\t     |%s", selectionOptions[counter]);
						if(counter == selection)
						{
							printf("   < |\n");
						}

						else
						{
							printf("     |\n");
						}
					}
					printf("\t      ----------");

					input = getMove();

					if(input == 1)
					{
						selection --;
					}

					else if(input == 2)
					{
						selection ++;
					}


					if(selection < 0)
					{
						selection = 2;
					}

					else if(selection >= 3)
					{
						selection = 0;
					}

					
				}while(input != 5 && input != 6);

				if(input == 5)
				{
					switch(selection)
					{
						case 0:
						if(sweapMines(size, primedBoard, board, x,y, points) == -1)
						{
							printf("\n");
							printBlankBoard(size, primedBoard);
							return 0;
						}

						else if(checkDone(size, primedBoard) == 1)
						{
							return 1;
						}
						break;

						case 1:
						board[y][x] = 'F';
						selection = 0;
						break;

						case 2:
						selection = 0;
						break;
					}
				}

				else if(input == 6)
				{
					selection = 0;
				}
			}
		}
	}
}


void initBoard(int size, char board[size][size])
{
	int counter1, counter2;

	for(counter1 = 0; counter1 < size; counter1 ++)
	{
		for(counter2 = 0; counter2 < size; counter2 ++)
		{
			board[counter1][counter2] = '#';
		}
	}
}

void plantMine(int size, char board[size][size], int difficulty)
{
	int counter1, xBuf, yBuf;
	float mines = size * size;

	switch(difficulty)
	{
		case 0:
		mines *= 0.08;
		break;

		case 1:
		mines *= 0.12;
		break;

		case 2:
		mines *= 0.16;
		break;
	}
	srand(time(NULL));
	for(counter1 = 0; counter1 < mines; counter1 ++)
	{
		xBuf = rand() % size;
		yBuf = rand() % size;
		if(board[yBuf][xBuf] == 'M')
		{
			counter1 --;
		}

		else
		{
			board[yBuf][xBuf] = 'M';
		}
	}
}

void displayBoard(int size, char board[size][size], int x, int y, int selected)
{
	int counter1, counter2;

	system("cls");
	printf("   ");

	for(counter2 = 0; counter2 < size; counter2 ++)
	{
		if(counter2 == x)
		{
			printf("  %c  ", DOWN_ARROW);
		}

		else
		{
			printf("    ");
		}
	}

	printf("\n");

	printf("    ---");



	for(counter1 = 1; counter1 < size; counter1 ++)
	{
		printf("----");
	}

	printf("\n");

	for(counter1 = 0; counter1 < size; counter1 ++)
	{
		if(counter1 == y)
		{
			printf(" %c ", RIGHT_ARROW);
		}

		else
		{
			printf("   ");
		}

		printf("|");
		for(counter2 = 0; counter2 < size; counter2 ++)
		{
			if(counter1 == y && counter2 == x)
			{
				if(selected == 1)
				{
					printf(" %c |", OPAQUE);
				}

				else
				{
					printf(" %c |", TRANSPARENT);
				}
			}

			else
			{
				printf(" %c |", board[counter1][counter2]);
			}
		}

		printf("\n");
	}

	printf("    ---");
	for(counter1 = 1; counter1 < size; counter1 ++)
	{
		printf("----");
	}
	printf("\n");
}

int localMines(int size, char mineBoard[size][size], char Board[size][size], int x, int y, int* points)
{
	int mines = 0;
	int xMod, yMod;

	if(mineBoard[y][x] == 'M')
	{
		return -1;
	}

	else
	{
		for(xMod = -1; xMod <= 1; xMod ++)
		{
			for(yMod = -1; yMod <= 1; yMod ++)
			{
				if(y + yMod < size && y + yMod >= 0 && x+xMod < size && x + xMod >= 0 && mineBoard[y + yMod][x + xMod] == 'M')
				{
					mines ++;
				}
			}
		}
	}

	if(intToChar(mines) == 0)
	{
		Board[y][x] = '~';
	}

	else
	{
		Board[y][x] = intToChar(mines);
	}

	mineBoard[y][x] = '~';
	*points = *points + 1;
	return mines;
}

int sweapMines(int size, char mineBoard[size][size], char board[size][size], int x, int y, int* points)
{
	int local = localMines(size,mineBoard, board, x, y, points);

	if(local == -1)
	{
		return -1;
	}

	else if(local == 0)
	{
		clearMines(size,mineBoard, board, x, y, points);
	}

	return 1;
}

int clearMines(int size, char mineBoard[size][size], char board[size][size], int x, int y, int* points)
{
	int xMod,yMod;

	for(xMod = -1; xMod <= 1; xMod += 2)
	{
		if(mineBoard[y][x + xMod] != 'M' && mineBoard[y][x + xMod] != '~')
		{
			if(x + xMod < size && x + xMod >= 0 && localMines(size, mineBoard, board, x + xMod, y, points) == 0)
			{
				clearMines(size, mineBoard, board, x + xMod, y, points);
			}
		}
	}

	for(yMod = -1; yMod <= 1; yMod += 2)
	{
		if(y + yMod < size && y + yMod >= 0 && mineBoard[y + yMod][x] != 'M' && mineBoard[y + yMod][x] != '~')
		{
			if(localMines(size, mineBoard, board, x, y + yMod, points) == 0)
			{
				clearMines(size, mineBoard, board, x, y + yMod, points);
			}
		}
	}
}

char intToChar(int number) {return 48 + number;}

int checkDone(int size, char mineBoard[size][size])
{
	int yCount, xCount;

	for(yCount = 0; yCount < size; yCount ++)
	{
		for(xCount = 0; xCount < size; xCount ++)
		{
			if(mineBoard[yCount][xCount] != 'M' && mineBoard[yCount][xCount] != '~')
			{
				return 0;
			}
		}
	}
	return 1;
}

void printBlankBoard(int size, char mineBoard[size][size])
{
	int counter1, counter2;


	printf(" ---");
	for(counter1 = 1; counter1 < size; counter1 ++)
	{
		printf("----");
	}

	printf("\n");

	for(counter1 = 0; counter1 < size; counter1 ++)
	{
		printf("|");
		for(counter2 = 0; counter2 < size; counter2 ++)
		{
			if(mineBoard[counter1][counter2] == 'M')
			{
				printf(" M |");
			}

			else
			{
				printf(" # |");
			}
		}
		printf("\n");
	}

	printf(" ---");
	for(counter1 = 1; counter1 < size; counter1 ++)
	{
		printf("----");
	}
	printf("\n");
}

int getMove()
{
	char input = 'N';
	int moveing = 1;
	
	while(moveing == 1)
	{
		do
		{
			input = getch();
		}while(input == -32|| input == 0);


		if(input == 119 || input == 87 || input == 72)
		{
			return 1;
		}

		else if(input == 115 || input == 83 || input == 80)
		{	
			return 2;
		}

		else if(input == 97 || input == 65 || input == 75)
		{
			return 3;
		}

		else if(input == 100 || input == 68 || input == 54)
		{
			return 4;
		}

		else if(input == 13)
		{
			return 5;
		}

		else if (input == 27)
		{
			return 6;
		}
	}
}

void pressKey()
{
	int input;
	do
	{
		printf("\nPress enter to continuo: ");
		input = getMove();
	}while(input != 5);
}


void howToPlay()
{
	int input;
	
	do
	{
		printf("This should be filled with useful information about how to play mine sweaper ");
		
		printf("\n\nPress enter to return to the previous screen");
		input = getMove();
	}while(input != 5);
}

int firstSelection(struct player *currentAccount)
{
	int selection = 0, counter, size1 = 2, input;

	char option1[2][13] = {
		"Play        ",
		"How to Play "
	};

	system("cls");
	printf("Hello, %s, what would you like to do?", currentAccount->userName);
	printf("\n\n\n");


	do
	{
		printf("\t\t\t     -----------------\n");
		for(counter = 0; counter < size1; counter ++)
		{
			printf("\t\t\t    | %s ", option1[counter]);
			if(counter == selection)
			{
				printf(" < |");
			}

			else
			{
				printf("   |");
			}
			printf("\n");
		}
		printf("\t\t\t     -----------------\n");

		input = getMove();

		if(input == 1)
		{
			selection ++;
			if(selection >= size1)
			{
				selection = 0;
			}
		}

		else if(input == 2)
		{
			selection --;
			if(selection < 0)
			{
				selection = size1 - 1;
			}
		}

		else if(input == 5)
		{
			switch(selection)
			{
				case 0:
				return 0;
				break;

				case 1:
				howToPlay();
				system("cls");
				break;
				
			}
		}
	printf("\n\n\n");
	system("cls");
	}while(1);
}

int secondSelection()
{
	char option2[4][8] = {
		" 7 X 7 ",
		" 9 X 9 ",
		"12 X 12",
		"15 X 15"
	};

	int counter, size2 = 4, selection = 0, input;

	do
	{
		system("cls");
		printf("What size grid would you like to play on?");
		printf("\n\n\n\t\t\t        ----------- \n");
		for(counter = 0; counter < size2;counter ++)
		{
			printf("\t\t\t       | %s ", option2[counter]);

			if(counter == selection)
			{
				printf("< |");
			}

			else
			{
				printf("  |");
			}
			printf("\n");
		}
		printf("\t\t\t        -----------\n");

		input = getMove();

		switch(input)
		{
			case 2:
			selection ++;
			if(selection >= size2)
			{
				selection = 0;
			}
			break;

			case 1:
			selection --;
			if(selection < 0)
			{
				selection = size2 - 1;
			}
			break;

			case 5:
			switch(selection)
			{
				case 0:
				return 7;
				break;

				case 1:
				return 9;
				break;

				case 2:
				return 12;
				break;

				case 3:
				return 15;
				break;
			}
			break;
		}
	}while(1);
}

int thirdSelection()
{
	int size3 = 3, counter3, input, selection = 0;

	char option3[3][7] = {
		"Easy  ",
		"Medium",
		"Hard  "
	};

	do
	{
		system("cls");
		printf("Chose you difficulty");

		printf("\n\n\n\t\t\t        ----------- \n");
		for(counter3 = 0; counter3 < size3; counter3 ++)
		{
			printf("\t\t\t       | %s ", option3[counter3]);
			if(selection == counter3)
			{
				printf(" < |");
			}

			else
			{
				printf("   |");
			}

			printf("\n");
		}
		printf("\t\t\t        -----------");
		input = getMove();

		printf("\n\n\n");
		system("cls");

		switch(input)
		{
			case 2:
			selection ++;
			if(selection >= size3)
			{
				selection = 0;
			}
			break;

			case 1:
			selection --;
			if(selection < 0)
			{
				selection = size3 - 1;
			}
			break;

			case 5:
			return selection;
			break;
		}
	}while(1);
}


int YesNo()
{
	char choices[2][5] = {
		"Yes",
		"No "
	};

	int counter, selection = 0, input;

	do
	{
		printf("\n\n\t\t    -------\n");
		for(counter = 0; counter < 2; counter ++)
		{
			printf("\t\t   | %s ", choices[counter]);
		
			if(counter == selection)
			{
				printf("< |");
			}

			else
			{
				printf("  |");
			}
			printf("\n");
		}
		printf("\t\t    -------\n");
		input = getMove();

		if(input == 1)
		{
			selection --;
			if(selection < 0)
			{
				selection = 1;
			}
		}

		else if(input == 2)
		{
			selection ++;
			if(selection >= 2)
			{
				selection = 0;
			}
		}
	}while(input != 5);
	return selection;
}

void writeAccount(struct player *currentAccount)
{
	FILE *fp;
	fp = fopen("accountInfo.bin", "rb+");
	fseek(fp, currentAccount->location * sizeof(struct player), SEEK_SET);
	fwrite(currentAccount, sizeof(struct player), 1, fp);
	fclose(fp);
}
