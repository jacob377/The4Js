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

struct player
{
	char name[5];
	int score;
};


void getWord(char outWord[7], int size);
int playRound(int size, char word[size], int *points);
void changeBoard(int size, char Board[MAX_ATTEMPTS][size], char template[size], int attemptNumber);
int inString(char letter, int size, char string[size]);
void innitOverlay(int size, char overLay[MAX_ATTEMPTS][size]);



int playLingo()
{
	int size, playing = 1, points = 0;
	char acctiveWord[7];


//	getting word size
	do
	{
		system("cls");
		printf("Do you want to play with 5, 6 or 7 letter words? ");
		scanf("%d", &size);
	}while(size != 5 && size != 6 && size != 7);

//	game loop
	while(playing == 1)
	{
		getWord(acctiveWord, size);
		puts(acctiveWord);
		printf("\n\n");
		playRound(size, acctiveWord, &points);
		playing = 0;
	}
	
	return 0;
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



int playRound(int size, char word[size], int *points)
{
	char altWord[size];
	char template[size];
	char wrongPlaceLoc[MAX_ATTEMPTS][size];
	char pastAttempts[MAX_ATTEMPTS][size];
	char input[size];
	int flag, correct = 1;
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
	while(attemptNumber <= MAX_ATTEMPTS)
	{
		//displaying board and getting user input
		do
		{
			system("cls");


			for(counter = 0; counter < MAX_ATTEMPTS; counter ++)
			{
				for(letterCounter = 0; letterCounter < size; letterCounter ++)
				{
					printf("%c ", wrongPlaceLoc[counter][letterCounter]);
				}
				printf("\n");

				for(letterCounter = 0; letterCounter< size; letterCounter ++)
				{
					printf("%c ", pastAttempts[counter][letterCounter]);
				}

				if(counter == attemptNumber - 1)
				{
					printf("   <<<");
				}
				printf("\n\n");
			}

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
			//checking for wrong letter location
			else if(inString(input[counter], size, altWord) == 1)
			{
				wrongPlaceLoc[attemptNumber-1][counter] = '?';
			}
		}
		attemptNumber ++;
		changeBoard(size, pastAttempts, template, attemptNumber);
	}
	printf("the word was ");
	puts(word);
	printf("\n\n");
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
