#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define FIVE 5757
#define SIX 2856
#define SEVEN 1371
#define HEART 3
#define MAX_ATTEMPTS 6
#define LINGO_INDEX 0


void getWord(char outWord[7], int size);
int playLingoRound(int size, char word[size], int *points);
void changeBoard(int size, char Board[MAX_ATTEMPTS][size], char template[size], int attemptNumber);
int inString(char letter, int size, char string[size]);
void innitOverlay(int size, char overLay[MAX_ATTEMPTS][size]);
void displayWords(int size, char wrongPlaceLoc[MAX_ATTEMPTS][size], char pastAttempts[MAX_ATTEMPTS][size], int attemptNumber);
void printfLine(int size, char wrongPlaceLoc[size], char pastAttempts[size], int attempt);

struct player
{
	char userName[10];
	char password[10];
	int scores[4];
	int attempts[4];
	int money;
	int location;
};

void writeAcount(struct player *currentAccount);

int playLingo(struct player* currentAccount)
{
	int size, playing = 1, points = 0, active = 1;
	char input;
	char acctiveWord[7];


//	getting word size
	do
	{
		system("cls");
		printf("Do you want to play with 5, 6 or 7 letter words? ");
		scanf("%d", &size);
	}while(size != 5 && size != 6 && size != 7);

//	game loop

	do
	{
		getWord(acctiveWord, size);
		active = playLingoRound(size, acctiveWord, &points);
	}while(active == 1);

	do
	{
		system("cls");
		currentAccount->attempts[LINGO_INDEX] = currentAccount->attempts[LINGO_INDEX] + 1;
		printf("You scored %d points:", points);
		printf("\n\n");
		printf("Total attempts = %d\n", currentAccount->attempts[LINGO_INDEX]);
		printf("Best previous score =");

		if(points < currentAccount->scores[LINGO_INDEX])
		{
			printf(" %d", currentAccount->scores[LINGO_INDEX]);
		}

		else if(points > currentAccount->scores[LINGO_INDEX])
		{
			currentAccount->scores[LINGO_INDEX] = points;
			printf(" %d  \nNEW High Score!!!\n");
		}

		else
		{
			printf(" %d \nAlmost a New High Score...\n");
		}
		

		writeAcount(currentAccount);
		printf("\nPress enter to return to main menu...\n");
		input = getch();
	}while(input != 13);

	return points;
}


void getWord(char outWord[7], int size)
{
	FILE *textFile;
	char text[21], word[size + 1];
	int wordAddress, mod, counter;

	sprintf(text, "words\\%d letter words.txt", size);

	//RNG
	srand(time(NULL));
	int rng = rand();
	//

	switch (size)
	{
		case 5:
		mod = FIVE;
		break;


		case 6:
		mod = SIX;
		break;

		case 7:
		mod = SEVEN;
		break;
	}



	textFile = fopen(text, "r");

	if(textFile != NULL)
	{
		wordAddress = rng%mod;
		for(counter =0; counter < wordAddress; counter ++)
		{
			fscanf(textFile, "%s", word);
		}
		fclose(textFile);
	}

	else
	{
		printf("there is a file error\n\n");
	}
	strcpy(outWord, word);
}



int playLingoRound(int size, char word[size], int *points)
{
	char testing;

	char altWord[size];
	char template[size];
	char wrongPlaceLoc[MAX_ATTEMPTS][size];
	char pastAttempts[MAX_ATTEMPTS][size];
	char input[size];
	char inputLetter;
	int flag = 1, correct = 1;
	int counterTwo, counter,letterCounter, attemptNumber = 1;

	strcpy(altWord, word);
	innitOverlay(size, wrongPlaceLoc);


	template[0] = altWord[0];
	for(counter = 1; counter < size; counter ++)
	{
		template[counter] = '*';
	}



	changeBoard(size, pastAttempts, template, attemptNumber);

//playing game
	while(attemptNumber <= MAX_ATTEMPTS && flag == 1)
	{
		flag = 1;
		//displaying board and getting user input
		do
		{
			system("cls");


			// for(counter = 0; counter < MAX_ATTEMPTS; counter ++)
			// {
			// 	for(letterCounter = 0; letterCounter < size; letterCounter ++)
			// 	{
			// 		printf("%c ", wrongPlaceLoc[counter][letterCounter]);
			// 	}
			// 	printf("\n");

			// 	for(letterCounter = 0; letterCounter< size; letterCounter ++)
			// 	{
			// 		printf("%c ", pastAttempts[counter][letterCounter]);
			// 	}

			// 	if(counter == attemptNumber - 1)
			// 	{
			// 		printf("\t<<<");
			// 	}
			// 	printf("\n\n");
			// }
			displayWords(size, wrongPlaceLoc, pastAttempts, attemptNumber);

			input[size] = 'o';
			printf("\nEnter a %d letter word: ", size);
			fflush(stdin);
			gets(input);
		}while(input[size] != '\0');

		strcpy(pastAttempts[attemptNumber-1], input);

		for(counter = 1; counter < size; counter ++)
		{
			//checking for correct letter location
			if(input[counter] == altWord[counter] && input[counter] != '*')
			{
				template[counter] = altWord[counter];
				altWord[counter] = '*';
				input[counter] = '*';
				*points += 1;
				correct += 1;
			}
		}


		//checking for wrong letter locations
		for(counter = 1; counter < size; counter ++)
		{
			if(inString(input[counter], size, altWord) == 1)
			{
				wrongPlaceLoc[attemptNumber - 1][counter] = '?';
			}
		}

		attemptNumber ++;
		

		changeBoard(size, pastAttempts, template, attemptNumber);
		if (strcmp(template, word) == 0)
		{
			points += (MAX_ATTEMPTS - attemptNumber + 1) * 3;
			flag = 0;
		}
	}

	if(flag == 1)
	{
		printf("the word was ");
		puts(word);
		printf("\n\n");
		return -1;
	}

	else
	{
		do
		{
			printf("well done would you like to play again, to get more points(Y/N): ");
			scanf("%c", inputLetter);
			system("cls");
		}while (inputLetter != 'Y' && inputLetter != 'N' && inputLetter != 'n' && inputLetter != 'y');

		if(inputLetter == 'Y' || inputLetter == 'y')
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}

void changeBoard(int size, char Board[MAX_ATTEMPTS][size], char template[size], int attemptNumber)
{
	int counter;

	for(counter = attemptNumber; counter <= MAX_ATTEMPTS; counter ++)
	{
		strcpy(Board[counter-1], template);
	}
}


int inString(char letter, int size, char string[size])
{
	int counter;
	for(counter = 1; counter < size && letter != '*'; counter ++)
	{
		if(string[counter] == letter && string[counter] != '*')
		{
			return 1;
		}
	}
	return 0;
}

void innitOverlay(int size, char overLay[MAX_ATTEMPTS][size])
{
	int counterIn, counterOut;
	for(counterIn = 0; counterIn < MAX_ATTEMPTS; counterIn ++)
	{
		for(counterOut = 0; counterOut< size; counterOut ++)
		{
			overLay[counterIn][counterOut] = ' ';
		}
	}
}

void writeAcount(struct player *currentAccount)
{
	FILE *fp;
	fp = fopen("accountInfo.bin", "rb+");
	fseek(fp, currentAccount->location, SEEK_SET);
	fwrite(currentAccount, sizeof(struct player), 1, fp);
}

void displayWords(int size, char wrongPlaceLoc[MAX_ATTEMPTS][size], char pastAttempts[MAX_ATTEMPTS][size], int attemptNumber)
{
	int counter;

	for(counter = 0; counter < MAX_ATTEMPTS; counter ++)
	{
		printfLine(size, wrongPlaceLoc[counter], pastAttempts[counter], counter == attemptNumber - 1);
	}
}

void printfLine(int size, char wrongPlaceLoc[size], char pastAttempts[size], int attempt)
{
	int counter1, counter2, counter3;

	printf(" ");
	for(counter1 = 0; counter1 <= size * 4 - 2; counter1 ++)
	{
		printf("-");
	}
	printf("\n");

	for(counter1 = 0; counter1 < 3; counter1 ++)
	{
		for(counter2 = 0; counter2 < size; counter2++)
		{
			if(counter1 == 1)

			{
			printf("|%c%c%c", wrongPlaceLoc[counter2], pastAttempts[counter2], wrongPlaceLoc[counter2]);
			}

			else
			{
				printf("|%c%c%c", wrongPlaceLoc[counter2], wrongPlaceLoc[counter2], wrongPlaceLoc[counter2]);
			}
			
		}
		if(attempt == 1 && counter1 == 1)
		{
			printf("| <<<\n");
		}
		else
		{
			printf("|\n");
		}
	}

	printf(" ");
	for(counter1 = 0; counter1 <= size * 4 - 2; counter1 ++)
	{
		printf("-");
	}
	printf("\n\n\n");
}
