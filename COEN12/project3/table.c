/* Jason Serrano
 * 4/21/22
 * Sorted.c collects data from coen12 folder and stores the elements in a sorted array in set sp;
 *
 */


#include "set.h"

//function used for hasing values
//Big O: O(n)
unsigned strhash(char *s)
{
    unsigned hash = 0;
    while(*s != '\0')
	hash = 31 * hash + *s ++;
    return hash;
}


// Initiallizes and allocates memory for creating the set
// Big O: O(n)
SET *createSet(int maxElts)
{
    int i;
    SET *sp;

    sp = malloc(sizeof(SET));
    assert(sp!=NULL);
    sp -> count = 0;
    sp -> length = maxElts;
    sp -> data = malloc(sizeof(char*)*maxElts);
    sp -> flags = malloc(sizeof(char*)*maxElts);
    assert(sp->data != NULL);
    assert(sp-> flags !=NULL);

    for(i=0; i < sp -> length; i++)
	sp -> flags[i] = 'E';

    return sp;
}

//Private Search Function: uses Binary search
//Big O: O(n)
static int search(SET *sp, char *elt, bool *found)
{
    assert (sp!=NULL);
    int ADDY, i;


    for (i=0; i< sp -> length; i++){
	ADDY = (strhash(elt)+i) % sp -> length;
	
	if(sp -> flags[ADDY] == 'F' && strcmp(elt, sp -> data[ADDY])==0){
	    *found = true;
	    return ADDY;
	}
	if(sp -> flags[ADDY] == 'E'){
	    break;
	}
    }
    return ADDY;

}


//Adds element to sorted array data pointed by SET sp
//Big O: O(n)
void addElement(SET *sp, char *elt)
{
    assert (sp != NULL && elt !=NULL);

    int i;
    char *copy; 
    bool found = false;
    int idx =search(sp, elt, &found);

    if (found ==false){
	//assert (sp->count < sp -> length);
	copy = strdup(elt);
	assert (elt!= NULL);
	sp -> data[idx] = copy;
	sp -> flags[idx] = 'F';
	sp -> count ++;
	return;
    }	
}

//States the amount of elements in the set
//Big O: O(1)
int numElements (SET *sp)
{
    assert(sp!=NULL);
    return sp->count;
}

//Removes element from the SET
//Big O: O(n)
void removeElement(SET *sp, char *elt)
{
    int i;
    bool found = false;

    int idx = search(sp, elt, &found);

    if (found == true){
       free (sp ->data[idx]);
       sp -> flags[idx] = 'D';
       sp -> count -= 1;
       return;
    }
}

// finds element in the set pointed by SET sp
//Big O: O(n)
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
//big O: O(n)
char **getElements(SET *sp)
{
    int i, j = 0;
    char **temp;
    assert (sp!=NULL);

    temp = malloc(sizeof(char*)*sp->count);
    assert(temp != NULL);

    for (i=0; i < sp -> length; i++){
	if (sp -> flags[i] == 'F'){
	    temp[j] = sp -> data[i];
	    j++;
	}
    }
    return temp;

}

//function deallocates and deletes elements in SET pointed by sp
//Big O: O(n)
void destroySet(SET *sp)
{
    int i;

    assert(sp!=NULL);
    
    for (i=0; i<sp->count; i++)
	if (sp -> flags[i] == 'F')
	    free(sp->data[i]);

    free(sp->flags);
    free(sp->data);
    free(sp);
    return;
}
