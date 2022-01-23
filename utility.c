#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GAME_COUNT 4

struct player
{
	char userName[10];
	char password[10];
	int scores[4];
	int attempts[4];
};

int main()
{
	FILE *accountFile;
	struct player newPlayer;
	int counter,counter1, accounts;
	int flag = 1;
	char input;

	accountFile = fopen("accountInfo.bin", "rb");
	fseek(accountFile, 0, SEEK_END);	
	accounts = ftell(accountFile) / sizeof(struct player);
	fclose(accountFile);

	accountFile = fopen("accountInfo.bin", "rb");
	for(counter = 0; counter < accounts; counter ++)
	{
		fread(&newPlayer, sizeof(struct player), 1, accountFile);
		printf("User name  - ");
		puts(newPlayer.userName);
		printf("Password - ");
		puts(newPlayer.password);
		printf("\n");
		
		printf("Scores -\t");
		for(counter1 = 0; counter1 < GAME_COUNT; counter1 ++)
		{
			printf("%d    ", newPlayer.scores[counter1]);
		}
		printf("\n");
		
		printf("Attempts -\t");
		for(counter1 = 0; counter1 < GAME_COUNT; counter1 ++)
		{
			printf("%d    ", newPlayer.attempts[counter1]);
		}

		printf("\n\n\n");
	}

	return 0;
}