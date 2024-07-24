#include "lab5.h"


int main (int argc, char *argv[])
{
    if (argc !=2)
	printf ("error");
    else 
	printf ("argument is %s\n", argv[1]);

    int option;
    int list_length = atoi(argv[1]);
    struct customer *orders;
    orders = (struct customer*) malloc (sizeof(struct customer)*list_length);
    
    while(1)
    {
	printf ("Boba Menu \n 1 - Add Order \n 2 - Fullfill Order\n 3 - List Orders\n 4- List by size\n 5- Resize orders \n  0 -  Quit\n" );
	scanf ("%d", &option);

	switch (option)
	{
	    case 1:

		AddOrder (orders, list_length);
		break;
		
	    case 2:

		FfOrder (orders );
		break;

	    case 3:

		list (orders);
		break;

	    case 4:

		Drink_Size(orders);
		break;

	    case 5: 

		list_length= Resize_order(orders);
		break;

	    case 0:
		
		free(orders);
		return (0);
		break;
	}
    }
}

void AddOrder (struct customer *orders, int list_length) // function used to add an order
{
    char *NP;
    int i,j;
    int Order_size;
    char NameTemp[10];
    int *DP;

    if (counter == list_length)
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

void FfOrder (struct customer *orders ) // function used to fullfill orders
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

void list (struct customer *orders) // function to view the list
{
    int i;
    for (i=0; i < MAX_LIST_SIZE; i++)
    {
	if(orders[i].drinks!=0)
	    printf("%s: %d drinks\n", orders[i].Name, orders[i].drinks);
    }
}

void Drink_Size (struct customer *orders)  // function to list orders based off size of drink
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

int Resize_order (struct customer *orders)
{
    int new_size;
    struct customer *p;

    printf ("Input new customer size");
    scanf ("%d", &new_size);
    p  = (struct customer*)realloc(orders,new_size * (sizeof(struct customer)));
    orders = p;

    return (new_size);

}

    

