#include "lab8.h"


int counter =0;


int main ( int argc, char *argv[])
{
    int option;
    FILE *fp;
    read(argv[1]);
    

    while(1)
    {
	printf ("Boba Menu \n 1 - Add Order \n 2 - Fullfill Order\n 3 - List Orders\n 4- List by size\n 5 -List backwards\n 6 - Length of list\n 0 -Quit\n" );
	scanf ("%d", &option);

	switch (option)
	{
	    case 1:   // creates and order
		{
		int size;
		char name[MAX_NAME_LENGTH];
		int flag;
		
		printf ("What is the name under?\n ");
		scanf ("%s", name);
		
		flag = check_duplicates(name); // sends the name inputed to check for duplicates
		if (flag == 0)
		    break;

		printf ("How many drinks for the order?\n");
		scanf ("%d", &size);
		AddOrder(name,size);
		break;
		}
		
	    case 2:  // fulfill an order

		FfOrder();
		break;

	    case 3: // list orders

		list();
		break;

	    case 4:

		Drink_Size();  // lists by drink size
		break;

	    case 5: 
		 
		Reverse(); // function for outputing list in reverse
		break;

	    case 6: 
		
		listL();
		break;

	    case 0:
		{		
		    save (argv[1]);
		    return(0);
		    break;
		}
		
	}
    }
}

void AddOrder (char *name,int size) // function used to add an order
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

void Reverse() // option 6 used to reverse list
{
    NODE *p = Head;
    
    Reverse_list(p);
    return;
}

void listL()
{
    NODE *p = Head;
    int counter = 0;

    counter = Length_of_List (p,counter);
    printf("%d orders\n", counter);
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


int read(char *file)  //used to open or create a file for orders 
{
    FILE *fp;
    char name[10];
    int size;

    fp = fopen(file, "r");
    if (fp == NULL)
    {
	fp = fopen(file, "w");
	fprintf(fp, "Name \n Size \n");
	fclose(fp);
	return;
    }
    fseek (fp, 10, SEEK_SET);
    while (fscanf(fp, "%s %d", name, &size)==2)
    {
	AddOrder (name, size);
    
    }
    fclose(fp);
    return;

}


int save(char *file)  // used for final save before closing
{
    NODE *p = Head;
    FILE *fp;
    fp = fopen(file, "w");
    fseek (fp,10, SEEK_SET);

    if( fp == NULL)
	printf ("no file found");
    while(p!=NULL)
    {
	fprintf(fp, "%s\t %d\n", p-> Name, p->drinks);
	p = p->next;
    }
    fclose (fp);
    return(1);
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
