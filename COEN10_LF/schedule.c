#include <stdio.h>
#define SIZE 5

int main ()
{
    int option;
    int appointments =0;
    int schedule[SIZE]={0,0,0,0,0};
    int Cancel;
    while(1)
    {
	int i;
	printf ("Menu\n 1-Schedule\n 2-Cancel\n 3-list\n 9-Quit\n");
	scanf ("%d", &option);
	if (option==1)  // If user selects to make an appointment
	{
	    if (appointments==5)
		 printf ("No avalaible appointments\n");
	    else
	    {
	    for(i=0; i<SIZE; i++)
	    {
		if (schedule[i]==0)
		{
		schedule[i]= i+1;
		printf (" You have an appointment at %d pm\n",schedule[i]);
		appointments++;
		break;
		}
	    }
	    }
	}
	if (option==2) // if user selects to Cancel appointment
	{
	    printf ("Which Time Slot would you like to Cancel?\n");
	    scanf ("%d",&Cancel);
	    if (schedule[Cancel-1]==0)
		printf ("There is no appointment during that time\n");
	    else
	    { schedule[Cancel-1]=0;
		appointments--;
		printf("lesson has already been cancelled\n");
	    }
	}
	if (option==3) // Shows the user current appointments
	{
	    for (i=0; i<SIZE; i++)
	    {
		if (schedule[i]!=0)
		    printf ("%dpm: Occupied\n",i+1);
		else
		    printf ("%dpm: Free\n",i+1);
	    }
	}
	if (option ==9) // Allows user to quit program
	    return (0);
    }
}






