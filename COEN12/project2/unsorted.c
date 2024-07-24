/* Jason Serrano
 * 4/7/22
 * Unsorted.c collects data from the COEN12 folder and stores any differnet different elements in SET sp;
 *
 */
#include "set.h"

// Private Search function
static int search(SET *sp, char *elt, bool *found)
{
    assert (sp!=NULL);
    int i;

    for(i=0; i< sp->count; i++){
	if (strcmp (sp->data[i],elt)==0){
	    *found = true;
	    return i;
	}
    }

    return -1;
}

// Initiallizes and allocated memory for creating the set
SET *createSet(int maxElts)
{
    SET *sp;

    sp = malloc(sizeof(SET));
    assert(sp!=NULL);
    sp->count = 0;
    sp->length = maxElts;
    sp->data = malloc(sizeof(char*)*maxElts);
    assert(sp->data != NULL);

    return sp;
}


// Adds a new element onto array Set sp
void addElement(SET *sp, char *elt)
{
    bool found = false;

    search (sp, elt, &found);
    if (found == false){
	sp->data[sp->count] = strdup(elt);
	sp->count++;
	return;
    }
}

// States the amount of elements in the set
int numElements (SET *sp)
{
    assert(sp!=NULL);
    return sp->count;
}


//Removes element from the SET
void removeElement(SET *sp, char *elt)
{
    int ADDY;
    bool found = false;

    ADDY = search (sp, elt, &found);
    if (found == true){
	free (sp -> data[ADDY]);
	sp -> data[ADDY] = sp ->data[sp->count-1];
	free (sp -> data[sp -> count -1]);
	sp -> count--;
	return;
    }
    
}


//Finds element in the set pointed by SET sp 
bool findElement(SET *sp, char *elt)
{
    int ADDY;
    bool found = true;

    ADDY = search (sp, elt, &found);
    if(found == true)
	return sp ->data [ADDY];
    return NULL;
}

//Allocates a new array to return the elements fo the set
char **getElements(SET *sp)
{ 
    int i;
    char **temp;

    assert(sp!= NULL);

    temp = malloc(sizeof(char*)*sp->count);
    assert(temp != NULL);
    
    return memcpy(temp, sp -> data, sizeof(char *) * sp ->count);   
}

//Function Deallocates and deletes elements in Set pointed by sp
void destroySet(SET *sp)
{
    int i;

    assert(sp != NULL);
    for (i=0; i<sp->count; i++)
	free(sp->data[i]);
    
    free(sp->data);
    free (sp);
    return;
}


