/* Jason Serrano
 * 4/31/22
 * CODE for counting words in a text file
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 30 

int count();


int main (int argc, char *argv[])  // main function
{
    int counter;

    if (argc != 2 ){ // used to check if the file opened properly
	printf("error with the file\n");
	return;
    }

    counter = count (argv[1]);
    printf ("%d total words\n", counter);
    return(0);
}


int count (char *file) // function used to read the amount of words in a file. 
{
    FILE *fp;
    int counter;
    char word[30];

    fp = fopen (file, "r");

    while (fscanf (fp, "%s", word)==1)
    {
	counter++;  // adds a value to the counter for every word
    }
    fclose (fp);
    return counter ;
}
