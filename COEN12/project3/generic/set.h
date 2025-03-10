/*
 * File:        set.h
 *
 * Copyright:	2021, Darren C. Atkinson
 *
 * Description: This file contains the public function and type
 *              declarations for a set abstract data type for generic
 *              pointer types.  A set is an unordered collection of
 *              distinct elements.
 */

# ifndef SET_H
# define SET_H
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct set{
   int count;
   int length;
   void **data;
   char *flags;
   int (*compare)();
   unsigned(*hash)();
}SET;

SET *createSet(int maxElts, int (*compare)(), unsigned (*hash)());

void destroySet(SET *sp);

int numElements(SET *sp);

void addElement(SET *sp, void *elt);

void removeElement(SET *sp, void *elt);

void *findElement(SET *sp, void *elt);

void *getElements(SET *sp);

# endif /* SET_H */
