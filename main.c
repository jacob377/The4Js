#include"lingo.h"
#include"Mine Sweeper.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define OPTIONS 6
#define SELECTIONS 5 


// redundnt by import on lingo.h and will cause an error
// struct player
// {
// 	char userName[10];
// 	char password[10];
// 	int scores[4];
// 	int attempts[4];
// };

struct stat
{
	char userName[10];
	int score;
};

int logIn(struct player* playerStorage);
void pressTo();
int check(char userName[10]);


int main()
{
	char Screen[23][76] = {
	" #######                                                       # ###       \n",
	"    #    #    # ######    ######  ####  #    # #####           # ###  #### \n",
	"    #    #    # #         #      #    # #    # #    #          #  #  #     \n",
	"    #    ###### #####     #####  #    # #    # #    #          # #    #### \n",
	"    #    #    # #         #      #    # #    # #####     #     #          #\n",
	"    #    #    # #         #      #    # #    # #   #     #     #     #    #\n",
	"    #    #    # ######    #       ####   ####  #    #     #####       #### \n",
	"                                                                           \n",
	"             #######                  #######                              \n",
	"                #     ####  #####     #        ####  #    # #####          \n",
	"                #    #    # #    #    #       #    # #    # #    #         \n",
	"                #    #    # #    #    #####   #    # #    # #    #         \n",
	"                #    #    # #####     #       #    # #    # #####          \n",
	"                #    #    # #         #       #    # #    # #   #          \n",
	"                #     ####  #         #        ####   ####  #    #         \n",
	"                                                                           \n",
	"                          #####                                            \n",
	"                         #     #   ##   #    # ######  ####                \n",
	"                         #        #  #  ##  ## #      #                    \n",
	"                         #  #### #    # # ## # #####   ####                \n",
	"                         #     # ###### #    # #           #               \n",
	"                         #     # #    # #    # #      #    #               \n",
	"                          #####  #    # #    # ######  ####                \n"                                                                                                                                
	};


	char end[15][70] =
	{
	" #######                                       #######               \n",
	"    #    #    #   ##   #    # #    #  ####     #        ####  #####  \n",
	"    #    #    #  #  #  ##   # #   #  #         #       #    # #    # \n",
	"    #    ###### #    # # #  # ####    ####     #####   #    # #    # \n",
	"    #    #    # ###### #  # # #  #        #    #       #    # #####  \n",
	"    #    #    # #    # #   ## #   #  #    #    #       #    # #   #  \n",
	"    #    #    # #    # #    # #    #  ####     #        ####  #    # \n",
	"                                                                     \n",
	"             ######                                                  \n",
	"             #     # #        ##   #   # # #    #  ####              \n",
	"             #     # #       #  #   # #  # ##   # #    #             \n",
	"             ######  #      #    #   #   # # #  # #                  \n",
	"             #       #      ######   #   # #  # # #  ###             \n",
	"             #       #      #    #   #   # #   ## #    #             \n",
	"             #       ###### #    #   #   # #    #  ####              \n"
	};

	char stats[7][45] =
	{
		"  #####                                     \n",
		" #     #  ####   ####  #####  ######  ####  \n",
		" #       #    # #    # #    # #      #      \n",
		"  #####  #      #    # #    # #####   ####  \n",
		"       # #      #    # #####  #           # \n",
		" #     # #    # #    # #   #  #      #    # \n",
		"  #####   ####   ####  #    # ######  ####  \n"		
	};


	char options[OPTIONS][20] = {
		"Lingo        ",
		"Mine Sweaper ",
		"Option 3     ",
		"Option 4     ",
		"Scores       ",
		"Exit         "
	};

	int counter, lineCounter, letterCounter, optionCounter, flag = 1, selection = 0, loggedIn = 0;
	struct player acctiveAccount;
	char input;


	while(loggedIn == 0)
	{
		loggedIn = logIn(&acctiveAccount);
	}

	if(loggedIn == 1)
	{
		while(flag == 1)
		{
			for(lineCounter = 0; lineCounter < 23; lineCounter ++)
			{
				for(letterCounter = 0; letterCounter < 76; letterCounter ++)
				{
					printf("%c", Screen[lineCounter][letterCounter]);
				}
			}

			printf("\n\n\n\n\n");

			printf("\t\t\t\t   ------------------\n");

			for(counter = 0; counter < OPTIONS; counter ++)
			{
				printf("\t\t\t\t  | ");
				for(letterCounter = 0; options[counter][letterCounter] != '\0'; letterCounter ++)
				{
					printf("%c", options[counter][letterCounter]);
				}

				if(counter == selection)
				{
					printf("<<< |");
				}

				else
				{
				printf("    |");
				}
				printf("\n");
			}

			printf("\t\t\t\t   ------------------\n");
			fflush(stdin);
			do
			{
				input = getch();
			}while(input == -32 || input == 0);

			printf("\n\n\n\n\n\n");

			system("cls");


			if(input == 'w' || input == 'W' || input == 72)
			{
				selection --;
			}

			else if(input == 'S' || input == 's' || input == 80)
			{
				selection ++;
			}



			if(selection  == OPTIONS)
			{
				selection = 0;
			}

			else if(selection == -1)
			{
				selection = OPTIONS - 1;
			}


			else if(input == 13)
			{
				switch(selection)
				{
					case 0:
					//lingo
					system("cls");
					playLingo(&acctiveAccount);
					break;

					case 1:
					// Mine Sweaper
					system("cls");
					playMineSweaper(&acctiveAccount);
					break;

					case 4:
					system("cls");
					for(counter = 0; counter < 7; counter ++)
					{
						printf("\t       ");
						for(letterCounter = 0; letterCounter < 45; letterCounter++)
						{
							printf("%c",stats[counter][letterCounter]);
						}
					}
					
					printf("\nFinish the stats part later\n");
					//finish latter when games have been finished
					pressTo();
					break;

					case 5:
					system("cls");
					for(counter = 0; counter < 15; counter ++)
					{	printf("   ");
						for(letterCounter = 0; letterCounter < 70; letterCounter ++)
						{
							printf("%c", end[counter][letterCounter]);
						}

					}
					printf("\n\n\n\n\n\nPress enter to Exit or esc to return:");
					do
					{
						input = getch();
					}while(input != 13 && input != 27);

					if(input == 13)
					{
						flag = 0;
					}
					break;

				}
			}
		}
	}
}





int logIn(struct player* playerStorage)
{
	FILE * accountFile;
	struct player playerBuffer;
	int flag = 1, counter, letterCounter, selection = 0, logFlag = 0, accounts, conflict = 0;
	char input;
	char InUserName[10], InPassWord[10];

				
	accountFile = fopen("accountInfo.bin", "rb");
	fseek(accountFile, 0, SEEK_END);
	accounts = ftell(accountFile) / sizeof(struct player);
	fclose(accountFile);

	char options[SELECTIONS][20] = 
	{
		"Log in\t",
		"Sign up\t",
		"Deleate an account",
		"View Leader Board ",
		"Exit\t"
	};

	while(flag == 1)
	{
		printf("Which of these operations would you like to proceed with:\n\n\n");

		for(counter = 0; counter < SELECTIONS; counter ++)
		{
			for(letterCounter = 0; options[counter][letterCounter] != '\0'; letterCounter ++)
			{
				printf("%c", options[counter][letterCounter]);
			}

			if(counter == selection)
			{
				printf("  <<<");
			}
			printf("\n");
		}



		fflush(stdin);
		do
		{
			input = getch();
		}while(input == -32 || input == 0);

		printf("\n\n\n\n\n\n");

		system("cls");


		if(input == 'w' || input == 'W' || input == 72)
		{
			selection --;
		}

		else if(input == 'S' || input == 's' || input == 80)
		{
			selection ++;
		}

		else if(input == 13)
		{
			switch(selection)
			{



				case 0:
				if(accountFile == NULL)
				{
					accountFile = fopen("accountInfo.bin", "wb");
					fclose(accountFile);

				}

				fclose(accountFile);
				accountFile = fopen("accountInfo.bin", "rb");
				if(accounts > 0)
				{
					while(logFlag == 0)
					{
						system("cls");
						printf("Enter a user name or type 'exit' to return to menue: ");
						fflush(stdin);
						gets(InUserName);

						if(strcmp(InUserName, "exit") == 0)
						{
							return 0;
						}


						printf("\n\nEnter a password: ");
						fflush(stdin);
						gets(InPassWord );

						for(counter = 0; counter < accounts && logFlag == 0; counter ++)
						{
							fread(&playerBuffer, sizeof(struct player), 1, accountFile);
							if(strcmp(playerBuffer.userName, InUserName) == 0 && strcmp(playerBuffer.password, InPassWord) == 0)
							{
								printf("You have Succsessfuly logged in\n\n");
								pressTo();
								logFlag = 1;
								strcpy(playerStorage->userName, playerBuffer.userName);
								strcpy(playerStorage->password, playerBuffer.password);

								playerStorage->attempts[0] = playerBuffer.attempts[0];
								playerStorage->attempts[1] = playerBuffer.attempts[1];
								playerStorage->attempts[2] = playerBuffer.attempts[2];
								playerStorage->attempts[3] = playerBuffer.attempts[3];

								playerStorage->scores[0] = playerBuffer.scores[0];
								playerStorage->scores[1] = playerBuffer.scores[1];
								playerStorage->scores[2] = playerBuffer.scores[2];
								playerStorage->scores[3] = playerBuffer.scores[3];

								playerStorage->location = counter;
								return 1;
							}
						}
					puts("Faild to log in\n\n");
					printf("\n\n");
					}
				}

				else
				{
					printf("There are no accouts on this machine or an error had occured\n");
					pressTo();
				}

				fclose(accountFile);
				break;




				case 1:
				while(logFlag == 0)
				{
					accountFile = fopen("accountInfo.bin", "rb");
					conflict = 0;
					do
					{
						system("cls");
						printf("Enter a 2-10 letter user name or type 'exit' to return to menue: ");
						fflush(stdin);
						gets(InUserName);
					}while(check(InUserName) == 0);

					if(strcmp(InUserName, "exit") == 0)
					{
						return 0;
					}

					for(counter = 0; counter < accounts && conflict ==0; counter++)
					{
						fread(&playerBuffer, sizeof(struct player), 1, accountFile);
						if(strcmp(playerBuffer.userName, InUserName) == 0)
						{
							conflict = 1;
						}
					}

					if(conflict == 1)
					{
						printf("This user name has already been taken\n");
						pressTo();
						return 0;
					}

					do
					{
						system("cls");
						printf("Now enter a 2-10 letter password: ");
						fflush(stdin);
						gets(InPassWord);
					}while(check(InPassWord) == 0);

					system("cls");
					printf("Are you sure you want these credentials:\n\n\nUser Name - %s\nPassword - %s\n\n", InUserName, InPassWord);
					
					printf("\n\n\n\n\n\nPress enter to confirm or esc to return:");
					do
					{
						fflush(stdin);
						input = getch();
					}while(input != 13 && input != 27);

					if(input == 13)
					{
						printf("\n\n");
						strcpy(playerStorage->userName, InUserName);
						strcpy(playerStorage->password, InPassWord);

						playerStorage->scores[0] = 0;
						playerStorage->scores[1] = 0;
						playerStorage->scores[2] = 0;
						playerStorage->scores[3] = 0;

						playerStorage->attempts[0] = 0;
						playerStorage->attempts[1] = 0;
						playerStorage->attempts[2] = 0;
						playerStorage->attempts[3] = 0;

						fclose(accountFile);
						fopen("accountInfo.bin", "ab");
						fwrite(playerStorage, sizeof(struct player), 1, accountFile);
						fclose(accountFile);
						return 1;
					}
					return 0;
				}
				break;

				case 2:
				return 0;
				break;

				case 3:
				return 0;
				break;

				case 4:
				return -1;
				break;

			}
		}


		if(selection  == SELECTIONS)
		{
			selection = 0;
		}

		else if(selection == -1)
		{
			selection = SELECTIONS - 1;
		}

	}
	return 1;
}


void pressTo()
{
	char input;
	printf("Press enter to continue...");
	do
	{
		fflush(stdin);
		input = getch();
	}while(input != 13);

	printf("\n");
	system("cls");
}

int check(char userName[10])
{
	int counter;
	int flag = 0;

	for(counter = 2; counter < 10 && flag == 0; counter ++)
	{
		if(userName[counter] == '\0')
		{
			flag = 1;
		}
	}
	return flag;
}
