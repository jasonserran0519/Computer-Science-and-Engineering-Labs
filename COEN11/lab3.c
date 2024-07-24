#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAX_LIST_SIZE  10
#define MAX_NAME_LENGTH 10

struct customer{
    char Name[MAX_NAME_LENGTH];
    int drinks; 
};

struct customer orders[10];
int counter =0;


void AddOrder();
void FfOrder();
void list();
void quit();
void Drink_Size();

int main ()
{
    int i;
    int option;
    
    for (i=0; i<MAX_NAME_LENGTH; i++)
	Name[i][0] = '\0';
    
    while(1)
    {
	printf ("Boba Menu \n 1 - Add Order \n 2 - Fullfill Order\n 3 - List Orders\n 4- List by size\n  0 -  Quit\n" );
	scanf ("%d", &option);

	switch (option)
	{
	    case 1:

		AddOrder();
		break;
		
	    case 2:

		FfOrder();
		break;

	    case 3:

		list();
		break;

	    case 4:

		Drink_Size();
		break;

	    case 0:
		
		return (0);
		break;
	}
    }
}

void AddOrder () // function used to add an order
{
    char *NP;
    int i,j;
    int Order_size;
    char NameTemp[10];
    int *DP;

    if (counter == 10)
	printf ("No available Orders\n");
    else
    {
	printf ("Please enter your name \n");
	scanf ("%s", NameTemp);
	for (i=0; i<MAX_NAME_LENGTH; i++)
	{
	    NP=&orders[i].Name[0];
	    if (strcmp (NameTemp,orders[i].Name)==0)
	    {
		printf("There is someonee with that name in the list \n");
		break;
	    }
	    if (*NP=='\0')
	    {
		strcpy (orders[i].Name, NameTemp);	
		while ( Order_size == 0)
		    {
			printf ("How many drinks would you like?\n");
			scanf ("%d", &Order_size);

			orders[i].drinks = Order_size;
		    }
		counter++;
		break;
	    }
	}
    }
}

void FfOrder () // function used to fullfill orders
{
    int amount_of_drinks= 0;
    int i;
    int j=0;
    int *DP;

    printf ("How many drinks do you want to make\n" );
    scanf ("%d", &amount_of_drinks);

    for (i=0; i< MAX_NAME_LENGTH; i++)
    {
	DP=&orders[i].drinks;
	    if ( amount_of_drinks >= *DP && *DP!=0 ) 
	    {   
		printf ("Order for %s with %d  has been fullfilled\n ", orders[i].Name, orders[i].drinks);
		amount_of_drinks = amount_of_drinks- *DP;
		for (j=i+1 ; j < counter; j++)
		{
		    strcpy (orders[j-1].Name , orders[j].Name);
		   orders[j-1].drinks = orders[j].drinks;
		}
		counter--;
		orders[counter].Name[0]='\0';
		orders[counter].drinks =0;
		i--;
	    }
	}
    }

void list () // function to view the list
{
    int i;
    for (i=0; i < MAX_LIST_SIZE; i++)
    {
	if(orders[i].drinks!=0)
	    printf("%s: %d drinks\n", orders[i].Name, orders[i].drinks);
    }
}

void Drink_Size ()  // function to list orders based off size of drink
{
    int i;
    int Dsize = 0;

    printf (" What is the Size of the Order?\n");
    scanf ("%d", &Dsize);

    for (i=0; i < MAX_LIST_SIZE; i++)
    {
	if (orders[i].drinks == Dsize || orders[i].drinks < Dsize)
	    printf ("%s :%d drinks\n", orders[i].Name, orders[i].drinks);
    }
}


//1. The struct definition for a customer is defined as their name and their drink size. 
//2. I prefer struct as it can keep everything more organized as it is easy to change.
//3. I would allow for the string containing the customers names to be greater than 10. 

