#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define Y_SIZE 9
#define X_SIZE 9
#define MINES 10

void initBoard(char board[Y_SIZE][X_SIZE]);
void displayBoard(char board[Y_SIZE][X_SIZE]);
void plantMine(char board[Y_SIZE][X_SIZE]);


int main()
{
	char board[Y_SIZE][X_SIZE];
	char primedBoard[Y_SIZE][X_SIZE];
	initBoard(board);

	initBoard(primedBoard);
	plantMine(primedBoard);

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

