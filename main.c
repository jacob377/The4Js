#include"lingo.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define OPTIONS 5

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


	char options[OPTIONS][20] = {
		"Lingo    ",
		"Option 2 ",
		"Option 3 ",
		"Option 4 ",
		"Exit     "
	};

	int counter, lineCounter, letterCounter, optionCounter, flag = 1, selection = 0;

	char input;

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
		}while(input == -32);

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
				//lingo
				system("cls");
				playLingo();
				break;

				case 4:
				flag = 0;
				for(counter = 0; counter < 15; counter ++)
				{
					for(letterCounter = 0; letterCounter < 70; letterCounter ++)
					{
						printf("%c", end[counter][letterCounter]);
					}
				}
				break;

			}
		}



		if(selection  == OPTIONS)
		{
			selection = 0;
		}

		else if(selection == -1)
		{
			selection = OPTIONS - 1;
		}
	}
}
