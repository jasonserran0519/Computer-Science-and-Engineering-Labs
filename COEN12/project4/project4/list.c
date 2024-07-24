/* 
 * File: List.c
 *
 * Jason Serrano
 * 5/5/22
 *
 *
 */


#include "list.h"

LIST *createList(int(*compare)())
{
    struct list *lp;
    lp = malloc(sizeof(struct list));
    assert(lp != NULL);
    lp -> count = 0;
    lp -> compare = compare;
    lp -> head = malloc(sizeof(struct node));
    assert(lp -> head != NULL);
    lp -> head -> next = lp -> head;
    lp -> head -> prev = lp -> head;
    return lp;
}

void destroyList(LIST *lp)
{
    NODE *pDel, *pNext;
    assert(lp != NULL);
    pDel = lp -> head; 
    do{
        pNext = pDel -> next;
	free(pDel);
	pDel = pNext;
    }while (pDel!= lp -> head);
    free(lp);
}

int numItems(LIST *lp)
{
    assert(lp != NULL);
    return lp -> count;
} 

void addFirst(LIST *lp, void *item)
{
    assert (lp != NULL && item != NULL);
    NODE *Newlp = malloc(sizeof(struct node));
    assert (Newlp != NULL);
    Newlp -> data = item;

    Newlp -> next = lp -> head -> next;
    Newlp -> prev = lp -> head;
    lp -> head -> next -> prev = Newlp;
    lp -> head -> next = Newlp;

    lp -> count ++;
    return;
}

void addLast(LIST *lp, void *item)
{
    assert (lp != NULL && item != NULL);
    NODE *Newlp = malloc(sizeof(struct node));
    assert(Newlp != NULL);
    Newlp -> data = item;

    
    Newlp -> next = lp -> head;
    Newlp -> prev = lp -> head -> prev;
    lp -> head -> prev -> next = Newlp;
    lp -> head -> prev = Newlp;

    lp -> count ++;
    return;
}

void *removeFirst(LIST *lp)
{
    assert (lp != NULL);
    NODE *q = lp -> head -> next;
    void *data = q -> data;
    
    
    lp -> head -> next = q -> next;
    q -> next -> prev = lp -> head;

    free(q);
    lp -> count --;
    return data;
}

void *removeLast(LIST *lp)
{
    assert (lp != NULL);
    NODE *Dellp = lp -> head -> prev;
    void *data = Dellp -> data;

    Dellp -> prev -> next = lp -> head;
    lp -> head -> prev = Dellp -> prev;

    free (Dellp);
    lp -> count --;
    return data;
}

void *getFirst(LIST *lp)
{
    assert (lp != NULL);

    return lp -> head -> next -> data;
}

void *getLast(LIST *lp)
{
    assert (lp != NULL);
    NODE *p = lp -> head -> prev;

    return p -> data;
}

void removeItem(LIST *lp, void *item)
{
    assert(lp != NULL && item != NULL);
    NODE *q = lp -> head; 
    
    while (q -> next != NULL){
	if (item == q -> data){
	    q -> prev -> next = q -> next;
	    q -> next -> prev = q -> prev;
	    free (q);
	}
	q = q -> next;
    }
}

/*
void *findItem(LIST *lp, void *item)
{
    assert(lp != NULL && item != NULL);
    NODE *q = lp -> head;

    while (q -> next != NULL){
	if (item == q -> data){
	    return (q -> data);
	}
	q = q -> next;
    }
    return NULL;
}


void *getItems(LIST *lp)
{
    assert( lp != NULL);
    NODE*

*/



