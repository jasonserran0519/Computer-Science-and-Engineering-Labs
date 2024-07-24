/* 
 * File: set.c
 *
 * Jason Serrano
 * 5/12/22
 *
 * 
 */


#include "list.h"
#include "set.h"

SET *createSet(int maxElts, int(*compare)(), unsigned(*hash)())
{
    int i;
    SET *sp;
    assert (compare != NULL && hash != NULL);
    sp = malloc(sizeof(SET));
    assert(sp != NULL);

    sp -> length = maxElts;
    sp -> compare = compare;
    sp -> hash = hash; 
    sp -> count = 0; 

    sp -> lists = malloc(sizeof(LIST*)*maxElts/20);
    assert(sp -> lists != NULL);

    for (i = 0; i < sp -> length; i ++)
    {
	sp -> lists[i] = malloc(sizeof(LIST));
	assert( sp -> lists[i] != NULL);
    }
    return sp;
}

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

int numItems(LIST *lp)
{
    assert(lp != NULL);
    return lp -> count;
} 

void addFirst(LIST *lp, void *item)
{
    assert (lp != NULL && item != NULL);
    NODE *Newlp = malloc(sizeof(struct node));

    Newlp -> next = lp -> head;
    lp -> head = Newlp;
}

void addLast(LIST *lp, void *item)
{
    assert (lp != NULL && item != NULL);
    NODE *Newlp = malloc(sizeof(struct node));

    lp -> head -> next = Newlp;
    Newlp -> prev = lp -> head;

}

void *removeFirst(LIST *lp)
{
    assert (lp != NULL);
    
    NODE *q = lp -> head;
    free(q);
}

void *removeLast(LIST *lp)
{
    assert (lp != NULL);
    NODE *q,*p;
    q = p = lp -> head;

    while (q != NULL)
    {
	q -> next = p -> next;
	p = p -> next;
    }
    free(p);
}

void *getFirst(LIST *lp)
{
    assert (lp != NULL);

    return lp -> head;
}

void *getLast(LIST *lp)
{
    assert (lp != NULL);
    NODE *p = lp -> head;

    while (p-> next != NULL)
	p = p -> next;

    return p;
}


void destoryList(LIST *lp)
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

void removeItem(LIST *lp, void *item)
{
    assert(lp != NULL && item != NULL);
    NODE *q = lp -> head;

    while (q -> next != NULL){
	if ( item == q -> data){
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

    while( q -> next != NULL){
	if (item == q -> data){
	    return (q -> data);
	}
       q = q -> next;
    }
    
    return NULL;
}
*/ 
//void *getItems(LIST *lp)
//{
   // assert( lp != NULL);
   // NODE *
