#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct set{
    int count;
    int length;
    char **data;
    char *flags;
}SET;

SET *createSet(int maxElts);
void addElement(SET *sp, char *elt);
void removeElement(SET *sp, char *elt);
int numElements(SET *sp);
char *findElement(SET *sp, char *elt);
char **getElements(SET *sp);
void destroySet(SET *sp);

