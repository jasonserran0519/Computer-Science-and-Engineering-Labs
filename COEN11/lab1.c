#include <stdio.h>
#include <stdlib.h>

#define REPS 10 // asigns the value 10 to anything that has the REPS

int amount_correct=0;
int Division(); // function for dividing and checking the answer

int main ()
{
    int i;

   printf ("Taco bell Hiring Quiz\n");
   srand(time(NULL));

    for (i=0; i < REPS; i++) // allows for the code to run 10 questions
    {
	int dividen = rand ()% 12+1; // creates a random dividen/ result
	int denominator = rand()% 12+1; // creates random denomiator

	Division(dividen,denominator);
    }
    printf ("%d/10 \n", amount_correct);
    if (amount_correct==10)             
	printf (" You pass \n");   // Displays if the user gets a 100% on the quiz
    else
	printf ("Find a different job\n "); // displays if the user doesn't recieve a 100% on the quiz
}

int Division (int dividen, int  denominator)
{
    int p= dividen;
    int q= denominator;
    int numerator = p * q ;


    printf (" %d/%d  = x \n", numerator, q);
    printf (" what is x?\n");   // user is meant to find the numerator

    int userguess;
    scanf("%d", &userguess);

    if (userguess== p)
    {
	printf ("correct \n");
	amount_correct++;
    }
    else
    {	printf ("Incorrect \n The correct answer is %d \n", p);	}
}

// 1. The program did not differ when I took out the srand(time(NULL)); of my program since my program is complide to before it was taken out. 

// 2. The compiler errors due to there being a semi colon after the 10. When something is being defined, everything to the right of what is being defined is being assigned. Because of this, the compiler substitutes 10; for repetitions instead of just 10.

// 3. I had the rand only be limited to the range of 1 and 11.
//
// 4. My program doesn't work if I remove the #includes from my file. After doing the gcc- Wall main.c, I recieved many warnings about imcompatible implicit declarations of functions such as printf and scanfd. 
