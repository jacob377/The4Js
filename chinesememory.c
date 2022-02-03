#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define z 30


void RandomBoard(char array[5][6]);
void guess(char array[5][6],char userboard[5][6],char revealed[5][6],char tempboard[5][6],int number, int tries);
void game(char array[5][6],char userboard[5][6],char revealed[5][6],char tempboard[5][6],int number,int tries);
void SoloGame(char array[5][6],char userboard[5][6],char revealed[5][6],char tempboard[5][6]);
void MultGame(char array[5][6],char userboard[5][6],char revealed[5][6],char tempboard[5][6]);

int main()
{
	char array[5][6];
	char userboard[5][6];
	char tempboard[5][6];
	char revealed[5][6];
	int x,y;
	
	for(x=0;x<5;x++)
    {
        for(y=0;y<6;y++)
        {
        	userboard[x][y] = '¦';
        	revealed[x][y] = '¦';
    	}
	}	
	int select = 0;
	printf("Welcome to Memory!\nWould you like to :\n1. Play Solo\n2. Play Local Multiplayer\n3. Exit\n\n:");
	scanf("%d",&select);
	system("cls");
	switch (select)
	{
		case 1:
			SoloGame(array,userboard,revealed,tempboard);
			break;
		case 2:
			MultGame(array,userboard,revealed,tempboard);
			break;
		case 3:
			return 0; 
		default:
			printf("Invalid Input!\n");
	}
	main();
} 	

void SoloGame(char array[5][6],char userboard[5][6],char revealed[5][6],char tempboard[5][6])
{
	int game,number,tries = 0;
	int fin,x,y,j = 0;
	for(x=0;x<5;x++)
    {
        for(y=0;y<6;y++)
        {
        	userboard[x][y] = '¦';
        	revealed[x][y] = '¦';
    	}
	}	
	printf("Solo game selected!\n");	
	RandomBoard(array);
	guess(array,userboard,revealed,tempboard,number,tries);
}
void MultGame(char array[5][6],char userboard[5][6],char revealed[5][6],char tempboard[5][6])
{
	int number = 1;
	int tries = 0;
	printf("Local Multiplayer game selected!");
	RandomBoard(array);
	guess(array,userboard,revealed,tempboard,number,tries);
}

void RandomBoard(char array[5][6])
{
	int rows, columns;
	int random, i, t;
	int r = 30;
	int d = 30;
	int ranchars[z] = {14,14,15,15,5,5,6,6,4,4,3,3,2,2,1,1,176,176,177,177,206,206,219,219,244,244,184,184,146,146};  
	srand((unsigned)time(NULL));
	printf("\t1\t2\t3\t4\t5\t6\n\n");
	for(rows=0;rows<5;rows++)
    {
    	printf("%d",t + 1);
        for(columns=0;columns<6;columns++)
            {
                random=rand()%d;
                array[rows][columns] = ranchars[random];
                for(i=random; i<r-1; i++)
        		{
      		      ranchars[i] = ranchars[i + 1];
       			}
                printf("\t%c",array[rows][columns]);
                d--;
                r--;
            }
		t++;
        printf("\n\n");
    }
} 

void guess(char array[5][6],char userboard[5][6],char revealed[5][6],char tempboard[5][6],int number,int tries)
{
	int counter,x,y,a,score = 0;
	system("cls");
	if (number == 1)
	{
		printf("Player 1 : It's your turn! : \n\n");
		number++;
	}
	else if (number == 2)
	{
		printf("Player 2 : It's your turn! : \n\n");
		number--;
	}
	printf("\t1\t2\t3\t4\t5\t6\n\n");
	for(x=0;x<5;x++)
    {
    	printf("%d",a + 1);
        for(y=0;y<6;y++)
        {
        	if (userboard[x][y] != revealed[x][y])
        	{
            	printf("\t%c",revealed[x][y]);
            	score++;
			}
			else
        	{
            	printf("\t%c",userboard[x][y]);
			}
        }
		a++;
        printf("\n\n");
    }
    if (score == 30)
    {
    	printf("\n\nGAME OVER! YOU WIN!");
    	main();
	}
    game(array,userboard,revealed,tempboard,number,tries);
}

void game(char array[5][6],char userboard[5][6],char revealed[5][6],char tempboard[5][6],int number,int tries)
{
	int userinp1, userinp2,userinp3,userinp4,h,f,g = 0;
	printf("ENTER A COORDINATE [x,y] : ");
	scanf("%d,%d",&userinp2,&userinp1);
	userinp2--;userinp1--;
	tempboard[userinp1][userinp2] = array[userinp1][userinp2];
	printf("\t1\t2\t3\t4\t5\t6\n\n");
	for(h=0;h<5;h++)
    {
    	printf("%d",g + 1);
        for(f=0;f<6;f++)
        {
        	if ((userinp1 == h) && (userinp2 == f))
			{
	            printf("\t%c",tempboard[h][f]);
			}
			else
			{
		        if (userboard[h][f] != revealed[h][f])
	        	{
	            	printf("\t%c",revealed[h][f]);
				}
				else
	        	{
	            	printf("\t%c",userboard[h][f]);
				}
			}
        }
		g++;
        printf("\n\n");
    }
    printf("\n\n");
    g = 0;
    do {
    	    printf("ENTER A SECOND COORDINATE [x,y] : ");
			scanf("%d,%d",&userinp4,&userinp3);
			userinp3--;userinp4--;
	}while((userinp3 == userinp1) && (userinp2 == userinp4));
	tempboard[userinp3][userinp4] = array[userinp3][userinp4];
	system("cls");
	for(h=0;h<5;h++)
    {
    	printf("%d",g + 1);
        for(f=0;f<6;f++)
        {
        	if (((userinp1 == h) && (userinp2 == f)) || ((userinp3 == h) && (userinp4 == f)))
			{
	            printf("\t%c",tempboard[h][f]);
			}
			else
			{
		        if (userboard[h][f] != revealed[h][f])
	        	{
	            	printf("\t%c",revealed[h][f]);
				}
				else
	        	{
	            	printf("\t%c",userboard[h][f]);
				}
			}
        }
		g++;
        printf("\n\n");
    }
    printf("\n\n");
    
    if (tempboard[userinp1][userinp2] == tempboard[userinp3][userinp4])
    {
    	revealed[userinp1][userinp2] = tempboard[userinp1][userinp2];
    	revealed[userinp3][userinp4] = tempboard[userinp3][userinp4];
    	printf("CORRECT\n\n");
	}
	else
	{
		tries++;
	}
	tempboard[userinp1][userinp2],tempboard[userinp3][userinp4] = '¦';  
	if (number == 0)
	{
		printf("Total failed tries = %d\nTotal Score = %d\n\nPRESS ANY KEY TO CONTINUE",tries,1000-tries*5);	
	} 
	getch();
	system("cls");
	guess(array,userboard,revealed,tempboard,number,tries);
}
