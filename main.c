#include"lingo.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define OPTIONS 6
#define SELECTIONS 5 



struct player
{
	char userName[10];
	char password[10];
	int scores[4];
};

struct stat
{
	char userName[10];
	int score;
};

int logIn(struct player* player);
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
		"Lingo    ",
		"Option 2 ",
		"Option 3 ",
		"Option 4 ",
		"Scores   ",
		"Exit     "
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

			printf("\t\t\t\t   --------------\n");

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

			printf("\t\t\t\t   --------------\n");
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
					playLingo();
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
							if(strcmp(playerBuffer.userName, InUserName) == 0 && strcmp(playerBuffer.password, InPassWord))
							{
								printf("You have Succsessfuly logged in\n\n");
								pressTo();
								logFlag = 1;
								return 1;
							}
						}
					puts("Faild to log in\n\n");
					}
				}

				else
				{
					printf("There are no accouts on this machine or an error had occured");
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
						printf("Enter a user name or type 'exit' to return to menue: ");
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
						printf("Now enter a password: ");
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
						strcpy(playerBuffer.userName, InUserName);
						strcpy(playerBuffer.password, InPassWord);

						puts(playerBuffer.userName);
						puts(playerBuffer.password);
						playerBuffer.scores[0] = 0;
						playerBuffer.scores[1] = 0;
						playerBuffer.scores[2] = 0;
						playerBuffer.scores[3] = 0;

						fclose(accountFile);
						fopen("accountInfo.bin", "ab");
						fwrite(&playerBuffer, sizeof(struct player), 1, accountFile);
						fclose(accountFile);
						return 1;
					}

					else
					{

					}
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

}

int check(char userName[10])
{
	int counter;
	int flag = 0;

	for(counter = 0; counter < 10 && flag == 0; counter ++)
	{
		if(userName[counter] == '\0')
		{
			flag = 1;
		}
	}
	return flag;
}
