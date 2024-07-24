#include <stdio.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIST_SIZE  10
#define MAX_NAME_LENGTH 10
#define NODE struct node 


struct node {
    char Name[MAX_NAME_LENGTH];
    int drinks;
    NODE *next;
};


NODE *Head;
NODE *Tail;

void AddOrder();
void FfOrder();
void list();
void Drink_Size();


int counter =0;


int main ()
{
    int i;
    int option;
    
    while(1)
    {
	printf ("Boba Menu \n 1 - Add Order \n 2 - Fullfill Order\n 3 - List Orders\n 4- List by size\n  0 -  Quit\n" );
	scanf ("%d", &option);

	switch (option)
	{
	    case 1:  // create an order

		AddOrder();
		break;
		
	    case 2:  // fulfill an order

		FfOrder();
		break;

	    case 3: // list orders

		list();
		break;

	    case 4:

		Drink_Size();  // lists by drink size
		break;

	    case 0:
		
		return (0);
		break;
	}
    }
}

void AddOrder () // function used to add an order
{
    int i,j;
    int Order_size;
    char NameTemp[10];

    NODE *p,*q;

    NODE *TEMP;
 
    TEMP = (NODE*) malloc(sizeof(NODE));
    p = Head; 

	printf ("Please enter your name \n");
	scanf ("%s", &TEMP ->Name);
	while(p!=NULL)
	{
	    if (strcmp (TEMP ->Name,p-> Name)==0)
	    {
		printf("There is someonee with that name in the list \n");
		return;
	    }
	   p=  p-> next;
	}
	printf ("How many drinks would you like?\n");
	scanf ("%d", &TEMP-> drinks);
	if (Head == NULL) // if the order is the first order made of the day
	{
	    TEMP-> next = NULL;
	    Head = TEMP;
	    Tail = TEMP;
	}	
	else // if there have been multiple orders
	{
	    TEMP -> next = NULL;
	    Tail -> next = TEMP;
	    Tail = TEMP;

	}
}

void FfOrder () // function used to fullfill orders
{
    int amount_of_drinks= 0;
    int i;
    int j=0;
    NODE *q ,*p;
    p =q =Head;

    printf ("How many drinks do you want to make\n" );
    scanf ("%d", &amount_of_drinks);

    while(p!=NULL)
    {
	if (amount_of_drinks >= p->drinks) // checks if amount of drinks made is enough for an order 
	{   
	    printf ("Order for %s with %d  has been fullfilled\n ", p->Name, p->drinks);
	    amount_of_drinks = amount_of_drinks- p->drinks;
	    if(p==Head) // if order fullfilled is the first order made
		Head = Head -> next;
	    if(p== Tail)
		Tail= p;
	    q -> next = p -> next;
	    free (p);
	    return;
	}
	q=p;
	p = p -> next;
    }
}

void list () // function to view the list
{
    NODE *p =Head;
    while (p!=NULL)
    {	printf("%s: %d drinks\n", p->Name, p->drinks);
	p= p-> next;
    }
}

void Drink_Size ()  // function to list orders based off size of drink
{
    NODE *p =Head;
    int Dsize = 0;

    printf (" What is the Size of the Order?\n");
    scanf ("%d", &Dsize);

    while(p!=NULL){
	if (p->drinks == Dsize || p->drinks < Dsize)
	    printf ("%s :%d drinks\n", p->Name, p->drinks);
	p= p->next;
    }
}



