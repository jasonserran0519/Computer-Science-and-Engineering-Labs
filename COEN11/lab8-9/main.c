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
		    delete();
		    return(0);
		    break;
		}
		
	}
    }
}

