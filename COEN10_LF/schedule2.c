#include <stdio.h>
#include <string.h>
#define SIZE 5

int main ()
{

    int option;
    int appointments =0;
    int schedule[SIZE]={0,0,0,0,0};
    int Cancel;
    int i,j;

    char Initial;
    char Nschedule [SIZE][20];
    char name[20];
    for (i=0; i < SIZE; i++)
	Nschedule[i][0] = '\0';

    while(1)
    {
	printf ("Menu\n 1-Schedule\n 2-Cancel\n 3-list\n 4-Show name\n 9-Quit\n");
	scanf ("%d", &option);
	switch(option)
	{ 
	    case 1:	// If user selects to make an appointment
	   
		if  (appointments==5)
		 printf ("No avalaible appointments\n");
	       	else
		{
		    for(i=0; i<SIZE; i++)
		    {
			if (Nschedule[i][0]=='\0')
			{
			    printf("Please enter your name \n");
			    scanf("%s",name);
			    strcpy(Nschedule[i], name);

			    schedule[i]= i+1;
			    printf ("You have an appointment at %d pm\n", schedule[i]);
			    appointments++;
			    break;
			}
		    }
		}
		break;
	    case 2:  // if user selects to Cancel appointment
		
		if (appointments==0)
		   printf("There are no appointments");
		else
		{	    
		printf ("What is the name for the appointment you would like to Cancel?\n");
		scanf ("%s", &name);
		for (i=0; i < SIZE; i++)
		    if(strcmp(name, Nschedule [i])==0)
		    {
			for (j=i +1; j < appointments; j++)
			    strcpy( Nschedule[j-1], Nschedule[j]);

			 appointments--;
			Nschedule[appointments][0]='\0';
			schedule[appointments]=0;
			printf("your appointment has been cancelled");
			break;
		    }
		}
		break;
	    case 3:  // Shows the user current appointments
		for (i=0; i<SIZE; i++)
		{
		    if (schedule[i]!=0)
			printf ("%dpm: %s \n",i+1,Nschedule[i]);
		    else
			printf ("%dpm: Free\n",i+1);
		}
		break;
	    case 4: // Allows user to search for name and time
		if (appointments == 0)
		    printf("There are no appointments");
		else
		{
		    printf("What is the first initial\n");
		    while (getchar() !='\n');
		    scanf("%c", &Initial);
			for (i=0; i<SIZE; i++)
			{
			    if (Nschedule[i][0]==Initial)
			    printf("%s %dpm\n",Nschedule[i],schedule[i]);
			}
		}
		break;
	    case 9: // Allows user to quit program
	    return (0);
	    break;
	    default:
		printf("Bad option \n");
	}
    }
}

