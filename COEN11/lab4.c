#include "lab4.h"
int counter = 0;

struct customer orders[10];

int main ()
{
    int i;
    int option;
    
    
    while(1)
    {
	printf ("Boba Menu \n 1 - Add Order \n 2 - Fullfill Order\n 3 - List Orders\n 4- List by size\n 0 -  Quit\n" );
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
    int option;

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
	    
	   
		printf ("Are you ordering for pickup at the store or Bobadash?\n 1 - Bobadash\n 2 - In-store\n");
		scanf ("%d", &orders[i].order_origin);
		if (orders[i].order_origin == 1)  // if order origin is Bobadash
		    {
			printf ("What is your Phone number?");
			scanf ("%s", orders[i].number.PhoneNum);
			break;
		    }
		if (orders[i].order_origin ==2)  // if order origin is in store
		    {		
			printf ("What is your confirmation number?");
			scanf ("%d", &orders[i].number.Order_Num);
			break;
		    }
		counter++;
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
		    orders[j-1] = orders[j];
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
	{
	    if (orders[i].order_origin ==1)
		printf("%s: %d drinks  %s \n", orders[i].Name, orders[i].drinks, orders[i].number.PhoneNum);
	    if (orders[i].order_origin ==2)
		printf("%s: %d drinks %d Order Number \n", orders[i].Name, orders[i].drinks, orders[i].number.Order_Num);
	}	
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


// 1. The size of my union is 2 data types of one being a string for the phone numbers and order number for the drink orders
// 2. All the members in my struct and union is the names of the customers, drinks size, the order origin of the order. My union contains the phone numbers and the order number.
// 3. An order cannot have both a phone number and an order number since it is determined based off of if the client ordered from bobadash or 


