#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define Y_SIZE 9
#define X_SIZE 9
#define MINES 10

int playRound();

void initBoard(char board[Y_SIZE][X_SIZE]);
void plantMine(char board[Y_SIZE][X_SIZE]);

void displayBoard(char board[Y_SIZE][X_SIZE]);
void printBlankBoard(char mineBoard[Y_SIZE][X_SIZE]);

int checkDone(char mineBoard[Y_SIZE][X_SIZE]);
int localMines(char mineBoard[Y_SIZE][X_SIZE], char Board[Y_SIZE][X_SIZE], int x, int y);
int sweapMines(char mineBoard[Y_SIZE][X_SIZE], char board[Y_SIZE][X_SIZE], int x, int y);
int clearMines(char mineBoard[Y_SIZE][X_SIZE], char board[Y_SIZE][X_SIZE], int x, int y);

char intToChar(int number);


int main()
{
	int alive = 1;
	while(alive == 1)
	{
		if(playRound() == 0)
		{
			alive = 0;
			printf("\nGame Over");
		}
	}
}


int playRound()
{
	char board[Y_SIZE][X_SIZE];
	char primedBoard[Y_SIZE][X_SIZE];
	
	char input[40];

	int playing = 1, yIn, xIn;

	initBoard(board);

	initBoard(primedBoard);
	plantMine(primedBoard);

	while(playing == 1)
	{
		yIn = -1;
		xIn = -1;

		system("cls");
		displayBoard(primedBoard);
		printf("\n\n\n");

		displayBoard(board);


		while(yIn < 0 || yIn >= Y_SIZE)
		{
			printf("Enter the y-coordnate you want to sweep: ");
			scanf("%d", &yIn);
			printf("\n");
		}

		while(xIn<0 || xIn >= X_SIZE)
		{
			printf("Enter the x-coordnate you want to sweep: ");
			scanf("%d", &xIn);
			printf("\n");
		}
		
		sweapMines(primedBoard, board, xIn, yIn);

		if(sweapMines(primedBoard, board, xIn, yIn) == -1)
		{
			printf("\n");
			printBlankBoard(primedBoard);
			return 0;
		}

		else if(checkDone(primedBoard) == 1)
		{
			return 1;
		}
	}
}


void initBoard(char board[Y_SIZE][X_SIZE])
{
	int counter1, counter2;

	for(counter1 = 0; counter1 < Y_SIZE; counter1 ++)
	{
		for(counter2 = 0; counter2 < X_SIZE; counter2 ++)
		{
			board[counter1][counter2] = '#';
		}
	}
}

void plantMine(char board[Y_SIZE][X_SIZE])
{
	int counter1, xBuf, yBuf;
	srand(time(NULL));
	for(counter1 = 0; counter1 < MINES; counter1 ++)
	{
		xBuf = rand() % X_SIZE;
		yBuf = rand() % Y_SIZE;
		board[yBuf][xBuf] = 'M';
	}
}

void displayBoard(char board[Y_SIZE][X_SIZE])
{
	int counter1, counter2;


	printf(" ---");
	for(counter1 = 1; counter1 < Y_SIZE; counter1 ++)
	{
		printf("----");
	}

	printf("\n");

	for(counter1 = 0; counter1 < Y_SIZE; counter1 ++)
	{
		printf("|");
		for(counter2 = 0; counter2 < X_SIZE; counter2 ++)
		{
			printf(" %c |", board[counter1][counter2]);
		}
		printf("\n");
	}

	printf(" ---");
	for(counter1 = 1; counter1 < Y_SIZE; counter1 ++)
	{
		printf("----");
	}
	printf("\n");
}

int localMines(char mineBoard[Y_SIZE][X_SIZE], char Board[Y_SIZE][X_SIZE], int x, int y)
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
				if(mineBoard[y + yMod][x + xMod] == 'M')
				{
					mines ++;
				}
			}
		}
	}

	Board[y][x] = intToChar(mines);
	mineBoard[y][x] = '~';
	return mines;
}

int sweapMines(char mineBoard[Y_SIZE][X_SIZE], char board[Y_SIZE][X_SIZE], int x, int y)
{
	int local = localMines(mineBoard, board, x, y);

	if(local == -1)
	{
		return -1;
	}

	else if(local == 0)
	{
		clearMines(mineBoard, board, x, y);
	}

	return 1;
}

int clearMines(char mineBoard[Y_SIZE][X_SIZE], char board[Y_SIZE][X_SIZE], int x, int y)
{
	int xMod,yMod;

	for(xMod = -1; xMod <= 1; xMod += 2)
	{
		if(mineBoard[y][x + xMod] != 'M' && mineBoard[y][x + xMod] != '~')
		{
			if(x + xMod < X_SIZE && x + xMod >= 0 && localMines(mineBoard, board, x + xMod, y) == 0)
			{
				clearMines(mineBoard, board, x + xMod, y);
			}
		}
	}

	for(yMod = -1; yMod <= 1; yMod += 2)
	{
		if(y + yMod < Y_SIZE && y + yMod >= 0 && mineBoard[y + yMod][x] != 'M' && mineBoard[y + yMod][x] != '~')
		{
			if(localMines(mineBoard, board, x, y + yMod) == 0)
			{
				clearMines	(mineBoard, board, x, y + yMod);
			}
		}
	}
}

char intToChar(int number) {return 48 + number;}

int checkDone(char mineBoard[Y_SIZE][X_SIZE])
{
	int yCount, xCount;

	for(yCount = 0; yCount < Y_SIZE; yCount ++)
	{
		for(xCount = 0; xCount < X_SIZE; xCount ++)
		{
			if(mineBoard[yCount][xCount] != 'M' && mineBoard[yCount][xCount] != '~')
			{
				return 0;
			}
		}
	}
	return 1;
}

void printBlankBoard(char mineBoard[Y_SIZE][X_SIZE])
{
	int counter1, counter2;


	printf(" ---");
	for(counter1 = 1; counter1 < Y_SIZE; counter1 ++)
	{
		printf("----");
	}

	printf("\n");

	for(counter1 = 0; counter1 < Y_SIZE; counter1 ++)
	{
		printf("|");
		for(counter2 = 0; counter2 < X_SIZE; counter2 ++)
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
	for(counter1 = 1; counter1 < Y_SIZE; counter1 ++)
	{
		printf("----");
	}
	printf("\n");
}
