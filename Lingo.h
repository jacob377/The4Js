#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define FIVE 5757
#define SIX 2856
#define SEVEN 1371

void getWord(char outWord[7], int size);

int playLingo()
{
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

