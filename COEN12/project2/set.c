#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct set{
    int count;
    int length;
    char **data;
}SET;

SET *createSet(int maxElts);
void addElement(SET *sp, char *elt);
int numElement(SET *sp);
void removeElement(SET *sp, char *elt);
bool findElement(SET *sp, char *elt);
char **getElements(SET *sp);
void destroySet(SET *sp);


