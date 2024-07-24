#include <stdio.h>
#include <string.h>
#define SIZE 5

int option; 
int appointments =0;
int schedule[SIZE]={0,0,0,0,0};
int i,j;
int groupSize[SIZE];

char name[20];
char Nschedule[SIZE][20];
char phone[SIZE][20];

void OptRequest();
void OptCancel();
void OptList();
void OptName();
void OptGroups();

int main ()
{

    for (i=0; i < SIZE; i++)
	Nschedule[i][0] = '\0';

    while(1)
    {
	printf ("Menu\n 1-Schedule\n 2-Cancel\n 3-list\n 4-Show name\n 5-Groups\n 9-Quit\n");
	scanf ("%d", &option);	
	switch(option)
	{
	    case 1:
		
		OptRequest();
		break;

	    case 2: 

		OptCancel();
		break;

	    case 3:

		OptList();
		break;

	    case 4: 

		OptName();
		break;

	    case 5:

		OptGroups();
		break;

	    case 9:
		return (0);
		break;
	    
	    default:
		printf("Bad option \n");
	}
    }
}

void OptRequest() // function if user wishes to make an appointment
{
    int group=0;
    int stop =0; 
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
		
		for (j=0; j<SIZE; j++)// scans to see if there are duplicates of name
		    if (strcmp (name, Nschedule[j])==0)
		    {
			printf("There is already someone with that name for an appointment\n");
			break;
		    }
		strcpy(Nschedule[i], name);

		while (group==0)
		{
		    printf ("What is the Size of your party?\n");
		    scanf ("%d", &group);

		    if (group > 4)
		    {
			printf ("Your party is too big \n");
			group = 0;
			continue;
		    }
		    groupSize[i] = group;
		}
		printf ("What phone number would you like to put down\n");
		scanf ("%s", &phone [i]); 
		schedule[i]= i+1;
		printf ("You have an appointment at %d pm\n", schedule[i]);
		appointments++;
		break;
	    }
	}
    }
}
void OptCancel () // for when user wants to cancel appointment
{
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
		    {
		
			strcpy( Nschedule[j-1], Nschedule[j]);
			strcpy( phone[j-1], phone[i]);
			groupSize[j-1] = groupSize[j];
			printf("%s changes from %d to %d\n", Nschedule[j-1], j+1,j);
			groupSize[j]=0;
		    }
			    
			appointments--;
			Nschedule[appointments][0]='\0';
			schedule[appointments]=0;
			printf("your appointment has been cancelled\n");
			break;
		}
	}
}

void OptList () // Lists all the appointments (Name, phone# and group size)
{
    for (i=0; i<SIZE; i++)
    {
	if (schedule[i]!=0)
	    printf ("%dpm: %s phone#: %s groupsize: %d  \n",i+1,Nschedule[i], phone[i], groupSize[i]);
	else
	    printf ("%dpm: Free\n",i+1);
    }
}

void OptName()
{
    char Initial;

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
}

void OptGroups()
{
 int GroupP;

    if (appointments ==0)
	printf ("There are no appointments");
    else
    {
	printf(" What is the group size");
	scanf("%d", &GroupP);
	for(i=0; i<SIZE; i++)
	{
	    if (groupSize[i]==GroupP)
		printf("%s %dpm\n", Nschedule[i], schedule[i]);
	}
    }
}



