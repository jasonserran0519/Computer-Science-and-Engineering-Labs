#include "lab8.h"

void AddOrder (char *name,int size) // CASE 1:  function used to add order
{
    NODE *p,*q;
    NODE *TEMP;
    TEMP = (NODE*) malloc(sizeof(NODE));
    p = Head;
    strcpy (TEMP -> Name, name);
    TEMP -> drinks = size;
    
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

void Reverse() // option 5 used to reverse list
{
    NODE *p = Head;
    
    Reverse_list(p);
    return;
}

void listL()  // CASE 6 used to count the amount of customers in the list
{
    NODE *p = Head;
    int counter = 0;

    counter = Length_of_List (p,counter);
    printf("%d orders\n", counter);
    return;
}

void delete () 
{
    NODE *p = Head;

    delete_list(p);
    return;
}
    
int check_duplicates(char* name)
{
    NODE *p = Head;
    while(p!=NULL)
    {
	if (strcmp (p -> Name, name)==0)
	{	
	    printf("There is someonee with that name in the list \n");
	    return(0);
	}
	p=  p-> next;
    }
    return (1);
}


int Reverse_list(NODE *p)
{
    if(p -> next == NULL){
	printf("%s: %d drinks\n", p -> Name, p -> drinks);
	return;
    }
    else{
	Reverse_list(p -> next);
	printf("%s:  %d drinks\n", p -> Name, p -> drinks);
    }
}

int Length_of_List(NODE *p, int counter)
{
    counter ++;
    if(p -> next == NULL){
	return counter;
    }
    else{
	counter = Length_of_List(p-> next, counter);
    }
}

int delete_list(NODE *p)
{
    if (p ->next == NULL){
	free (p);
	return;
    }
    else{
	delete_list(p -> next);
	free (p);
    }
}
