#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

srand(time(NULL));
int amount_correct=0; //percentage that the user got correct

printf("Multiplication Test \n");
   int i;
    for(i=0; i<10 ; i++)
{
   int factor1 = rand()% 12+1;
   int factor2 = rand()% 12+1;
    printf("what is %d x %d ",factor1, factor2);
    int UserGuess;
    scanf("%d",&UserGuess);

      if (UserGuess == factor1 * factor2)
     {
    printf ("Correct \n");
    amount_correct++;
     }else{
      printf("wrong \n");
  }
}
int percent_correct = amount_correct*100/10;
printf ("Congrats you got %d%%",percent_correct);
	}

      


