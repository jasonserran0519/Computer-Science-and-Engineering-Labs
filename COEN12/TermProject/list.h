/*
 * File:	list.h
 *
 * Copyright:	2020, Darren C. Atkinson
 *
 * Description:	This file contains the public function and type
 *		declarations for a list abstract data type for generic
 *		pointer types.  The list supports deque operations, in
 *		which items can be easily added to or removed from the
 *		front or rear of the list, as well as indexing.
 */

# ifndef LIST_H
# define LIST_H


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct list{
   int count;
   struct node *head;
   struct node *tail;
}LIST;

typedef struct node{
    int front;
    void **data;
    struct node *next;
    struct node *prev;
    int count;
    int length;
}NODE;

extern LIST *createList(void);

extern NODE *newNode(int length);

extern void destroyList(LIST *lp);

extern int numItems(LIST *lp);

extern void addFirst(LIST *lp, void *item);

extern void addLast(LIST *lp, void *item);

extern void *removeFirst(LIST *lp);

extern void *removeLast(LIST *lp);

extern void *getFirst(LIST *lp);

extern void *getLast(LIST *lp);

extern void *getItem(LIST *lp, int index);

extern void setItem(LIST *lp, int index, void *item);

# endif /* LIST_H */
