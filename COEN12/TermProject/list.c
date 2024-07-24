/* 
 * File list.c 
 *
 * This file is as a submission for my term project in COEN12
 *
 * Jason Serrano
 * 6/4/22
 *
 */

#include "list.h"

// Creates a list and returns a pointer
// BIG O O(1)
LIST *createList (void)
{
    struct list *lp;
    lp = malloc(sizeof(struct list));
    assert(lp != NULL);

    lp -> head = newNode(sizeof(NODE));
    lp -> tail = newNode(sizeof(NODE));
    lp -> count = 0;
}

//function used to create a new node with a pointer to it
//BIG O O(1)
NODE *newNode(int length)
{
    NODE *np = malloc(sizeof(NODE));
    assert (np != NULL);

    np -> count = 0;
    np -> front = 0;
    np -> data = malloc(sizeof(void **) *length);

    np -> length = 50;
    np -> next = NULL;
    np -> prev = NULL;
    return np;
}

//Destroys the list
// BIG O O(n)
void destoryList(LIST *lp)
{
    NODE *pDel;
    assert(lp != NULL);
    
    do{
	pDel = lp -> head;
	lp -> head = lp -> head -> next;
	free(pDel -> data);
	free(pDel);

    }while (lp -> head != NULL);
    free(lp);
}

//Returns the number of elements in the list
//BIG O O(1)
int numItems(LIST *lp)
{
    assert(lp != NULL);
    return lp -> count;
}

//Add a new element to the front of the list (Checks to see if the first element on the list is full)
//Big O O(1)
void addFirst(LIST *lp, void *item)
{
    assert (lp != NULL && item != NULL);
    NODE *Curlp = malloc(sizeof(struct node));
    assert (Curlp != NULL);

    if (lp -> head -> count == lp -> head -> length){

	NODE *Curlp = newNode(lp -> head -> length);
	Curlp -> next = lp -> head;
	lp -> head = Curlp;
	Curlp -> next -> prev = Curlp;
    }

    int index = ((lp -> head -> front + lp -> head -> length -1 ) % lp -> head -> length);
    lp -> head -> data[index] = item;
    lp -> head -> front = index;
    lp -> count ++;

}

//Adds a new element to the end of the list (checks if last node is full)
//BIG O O(1)
void addLast(LIST *lp, void *item)
{
    assert (lp != NULL && item != NULL);
    
    if (lp -> tail -> count == lp -> tail -> length){

	NODE *Curlp = newNode(lp -> tail -> length);
	Curlp -> prev = lp -> tail;
	lp -> tail -> next = Curlp;
	lp -> tail = Curlp;
    }

    int index = ((lp -> tail -> front + lp -> tail -> count) % lp -> tail ->length);
    lp -> tail -> data [index] = item;
    lp -> tail -> count ++;
    lp -> count ++;

}

//Removes the first node in the list and free the data
//BIG O O(1)
void *removeFirst(LIST *lp)
{
    assert (lp !=NULL);
    
    if (lp -> head -> count == 0){
	lp -> head = lp -> head -> next;
	free(lp -> head -> prev);
	lp -> head -> prev = NULL;
    }

    int index = lp -> head -> front;
    int newIndex = (index+1) % lp -> head -> length;
    lp -> head -> front = newIndex;

    void *temp = lp -> head -> data[index];
    lp -> head -> count --;
    lp -> count --;

    return temp;
}

//Removes the last node and its data from the list
//Big O O(1)
void *removeLast(LIST *lp)
{
    assert (lp != NULL);
    
    if (lp -> tail -> count ==0){
	NODE *Dellp = lp -> tail;
	lp -> tail = lp -> tail -> prev;
	lp -> tail -> next = NULL;
	free(Dellp -> data);
	free(Dellp);
    }

    int index = ((lp -> tail -> front + lp -> tail -> count) % lp -> tail -> length);

    void *temp = lp -> tail -> data[index];

    lp -> tail -> count--;
    lp -> count --;

    return temp;

}

//Traverses the list and copies array of the node and returns a copy
//Big O O(logn)

void *getItem(LIST *lp, int index)
{
    assert (lp != NULL);

    NODE *Curlp = lp -> head;

    while(index >= Curlp -> count){
	index = index - Curlp -> count;
	Curlp = Curlp -> next;
    }

    void *temp = Curlp -> data[(Curlp -> front + index) % Curlp -> length];

    return temp;
}

//Traverses nodes and sorts items
//BIG O O(1)
void setItem(LIST *lp, int index, void *item)
{
    assert(lp != NULL && item != NULL);

    NODE *Curlp = lp -> head;

    while(index >= Curlp -> count){

	index = index - Curlp -> count;
	Curlp = Curlp -> next;
    }

    Curlp -> data[(Curlp -> front + index) % Curlp -> length] = item;
}

