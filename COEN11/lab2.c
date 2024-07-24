#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAX_LIST_SIZE  10
#define MAX_NAME_LENGTH 10

int counter =0;
int drinks [MAX_NAME_LENGTH];

char Name[MAX_NAME_LENGTH][10];

void AddOrder();
void FfOrder();
void list();
void quit();

int main ()
{
    int i;
    int option;
    
    for (i=0; i<MAX_NAME_LENGTH; i++)
	Name[i][0] = '\0';
    
    while(1)
    {
	printf ("Boba Menu \n 1 - Add Order \n 2 - Fullfill Order\n 3 - List Orders\n 0 -  Quit\n");
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

	    case 0:
		
		return (0);
		break;
	}
    }
}

void AddOrder () // function used to add an order
{

    int i;
    int Order_size;

    if (counter == 10)
	printf ("No available Orders\n");
    else
    {
	for (i=0; i<MAX_NAME_LENGTH; i++)
	{
	    if (Name[i][0]== '\0')
	    {
		printf ("Please enter your name \n");
		scanf ("%s", Name[i]);

		    while ( Order_size == 0)
		    {
			printf ("How many drinks would you like?\n");
			scanf ("%d", &Order_size);

			drinks [i] = Order_size;
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

    printf ("How many drinks do you want to make\n" );
    scanf ("%d", &amount_of_drinks);

    for (i=0; i< MAX_NAME_LENGTH ; i++)
    {
	if (drinks[i]!=0)
	{
	    if (amount_of_drinks > drinks [i] || amount_of_drinks == drinks[i] ) 
	    {   
		amount_of_drinks= amount_of_drinks - drinks[i];
		printf ("Order for %s with %d  has been fullfilled\n ", Name[i], drinks[i]);
		for (j=i+1 ; j < MAX_NAME_LENGTH; j++)
		{
		    strcpy (Name [j-1], Name[j]);
		    drinks [j-1] = drinks [j];
		}
		counter--;
		Name[counter][0]='\0';
		drinks [counter]=0;
	    }
	}
    }
}

void list ()
{
    int i;

    for (i=0; i < MAX_LIST_SIZE; i++)
    {
	if(drinks[i]!=0)
	    printf("%s: %d drinks\n", Name[i], drinks[i]);
    }
}



//1. In my code, nothing occured if the customers name was over 100 characters. 
//2. My code can handle any input that isn't listed without existing with it having all the variables and arrays pre initiallized. By having my arrays and variables initiallized, I can aside a value through an input to each array and variable. 
//3. I can use true or false when it comes to checking if the employee has made enough drinks to satisfy orders. 
