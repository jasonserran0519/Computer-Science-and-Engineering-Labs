/* Jason Serrano
 * 4/28/22
 * table.c collects data from coen12 folder and stores the elements in a sorted array in set sp, through the generic ADT.
 *
 */


#include "set.h"

//function used for hashing of values
//Big O:   O(1)

unsigned strhash(char *s)
{
    unsigned hash = 0;
    while(*s != '\0')
	hash = 31 * hash + *s ++;
    return hash;
}


// Initiallizes and allocates memory for creating the set
// Big O O(1)
SET *createSet(int maxElts, int(*compare)(), unsigned (*hash)())
{
    int i;
    SET *sp;

    sp = malloc(sizeof(SET));
    assert(sp!=NULL);
    sp -> count = 0;
    sp -> length = maxElts;
    sp -> data = malloc(sizeof(char*)*maxElts);
    sp -> flags = malloc(sizeof(char*)*maxElts);
    sp -> compare = compare;
    sp -> hash = hash;
    assert(sp->data != NULL);
    assert(sp-> flags !=NULL);

    for(i=0; i < sp -> length; i++)
	sp -> flags[i] = 'E';

    return sp;
}

//Private Search Function: uses Binary search
//Big O(n)
static int search(SET *sp, void *elt, bool *found)
{
    assert (sp!=NULL);
    int ADDY;

    ADDY = (*sp -> hash)(elt) % sp -> length;

    while(sp -> flags[ADDY] != 'E'){
	if(sp -> flags[ADDY] == 'F' && (*sp -> compare)(sp->data[ADDY],elt)==0){
	    *found = true;
	    return ADDY;
	}
	
	if(sp -> flags[ADDY] == 'D'){
	    ADDY ++;
	}
	
	if(sp -> flags[ADDY] == 'F' && (*sp -> compare)(sp->data[ADDY],elt)!=0){
	    ADDY ++;
	}
	if (ADDY == 18000)
	    ADDY = 0;
    }
    return ADDY;

}


//Adds element to sorted array data pointed by SET sp
//Big O: O(n)
void addElement(SET *sp, void *elt)
{
    assert (sp != NULL && elt !=NULL);

    int i; 
    bool found = false;
    int idx =search(sp, elt, &found);

    if (found ==false){
	//assert (sp->count < sp -> length);
	sp->data[idx] = elt;
	assert (elt!= NULL);
	sp -> flags[idx] = 'F';
	sp -> count ++;
	return;
    }	
}

//States the amount of elements in the set
//Big O(1)
int numElements (SET *sp)
{
    assert(sp!=NULL);
    return sp->count;
}

//Removes element from the SET
//Big O: O(n)
void removeElement(SET *sp, void *elt)
{
    int i;
    bool found = false;

    int idx = search(sp, elt, &found);

    if (found == true){
       //free (sp ->data[idx]);
       sp -> flags[idx] = 'D';
       sp -> count -= 1;
       return;
    }
}

// finds element in the set pointed by SET sp
//Big O  O(n)
void* findElement(SET *sp, void *elt)
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
//Big O: O(n)
void *getElements(SET *sp)
{
    int i, j = 0;
    void **temp;
    assert (sp!=NULL);

    temp = malloc(sizeof(void*)*sp->count);
    assert(temp != NULL);

    
    for(i=0; i < sp -> length; i++){
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

    free(sp->flags);
    free(sp->data);
    free(sp);
    return;
}
