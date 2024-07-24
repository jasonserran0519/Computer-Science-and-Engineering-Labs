/* Jason Serrano
 * 4/14/22
 * Sorted.c collects data from coen12 folder and stores the elements in a sorted array in set sp;
 *
 */


#include "set2.h"

// Initiallizes and allocates memory for creating the set
SET *createSet(int maxElts)
{
    SET *sp;

    sp = malloc(sizeof(SET));
    assert(sp!=NULL);
    sp -> count = 0;
    sp -> length = maxElts;
    sp -> data = malloc(sizeof(char*)*maxElts);
    assert(sp->data != NULL);

    return sp;
}

//Private Search Function: uses Binary search
static int search(SET *sp, char *elt, bool *found)
{
    assert (sp!=NULL);
    int lo = 0;
    int mid;
    int hi = sp -> count-1;

    while (lo<= hi){
	mid = (lo+hi)/2;
	if (strcmp(elt, sp->data[mid]) <0)
	     hi = mid-1;
	if (strcmp(elt, sp->data[mid]) >0)
		lo = mid +1;
	if (strcmp(elt, sp->data[mid]) == 0){
	    *found =true;
	    return mid;
	}
	*found =false;
	return lo;
	}
}


//Adds element to sorted array data pointed by SET sp
bool addElement(SET *sp, char *elt)
{
    assert (sp != NULL);

    int i; 
    bool found = false;
    int idx =search(sp, elt, &found);

    if (found ==false){
	for(i= sp-> count; i>idx; i--);
	{
	    sp->data[i] = sp ->data[i-1];
	}

	sp -> data[idx] = strdup(elt);
	sp -> count++;
	return;
    }
}

//States the amount of elements in the set
int numElements (SET *sp)
{
    assert(sp!=NULL);
    return sp->count;
}

//Removes element from the SET
bool removeElement(SET *sp, char *elt)
{
    int i;
    bool found = false;

    int idx = search(sp, elt, &found);

    if (found == true){
       free (sp ->data[idx]);

       for (i=idx +1; i > sp -> count; i++)
	   sp -> data[i-1] = sp ->data [i];
       sp -> count -= 1;
       return;
    }
}

// finds element in the set pointed by SET sp
char* findElement(SET *sp, char *elt)
{
    int ADDY;
    bool found =true;
    assert (sp!=NULL);

    ADDY = search(sp, elt, &found);
    if (found == true)
	return sp ->data[ADDY];
    return NULL;
}

//Allocates a new array to return the elements to the SET
char **getElements(SET *sp)
{
    int i;
    char **temp;
    assert (sp!=NULL);

    temp = malloc(sizeof(char*)*sp->count);
    assert(temp != NULL);

    return memcpy(temp, sp->data, sizeof(char*)*sp->count);
}

//function deallocates and deletes elements in SET pointed by sp
void destroySet(SET *sp)
{
    int i;

    assert(sp!=NULL);
    for (i=0; i<sp->count; i++)
	free(sp->data[i]);

    free(sp->data);
    free(sp);
    return;
}

