#include "pqueue.c"

static int Parent (int i)
{
    i = ((i-1)/2);
    return i;
}
    
static int Left_Child (int i)
{
    i = i *2 + 1;
    return i;
}

static int Right_Child (int i)
{ 
    i = i * 2 + 2;
    return i;
}


PQ *createQueue (int (*compare)())
{
    struct pqueue *pq;
    pq = malloc(sizeof(struct pqueue));
    assert(lp != NULL);
    pq -> count = 0;
    pq -> compare = compare;
    pq -> length = 10;
    pq -> data = malloc(sizeof(void*)*pq -> length);
    assert(pq -> data != NULL);
}

void destroyQueue(int (*compare)())
{
    assert(pq != NULL);

    free (pq -> data);
    free (pq);
    return;
}

int numEntries(PQ *pq)
{
    assert (pq != NULL);
    return sp->count;
}

void addEntry(PQ *pq, void *entry)
{
    assert (pq != NULL);
    int temp;

    if (pq -> count == pq -> length){
	pq -> data = (void **) realloc(pq -> data, sizeof(void *) *10)
	pq -> length = pq -> length + 10;
    }

    int i = pq -> count;
    pq -> data[i] = entry;
    while (i != 0 && (*pq -> compare)(pq -> data[Parent(i)], entry) > 0){
	temp = pq -> data[i];
	pq -> data[i] = pq -> data[Parent(i)];
	pq -> data[Parent(i)] = temp;

	i = Parent(i);
    }
    pq -> count ++;


void *removeEntry(PQ *pq)
{
    assert( pq != NULL);
    void* root = pq -> data[0];
    pq -> count --;
    pq -> data[0] = pq -> data[pq -> count];

    int min = 0;
    int compare = 0;

    while ( Left_Child < pq -> count){
	min = Left_Child[i];

	if ( (pq -> compare)(pq -> data[Right_Child(i)] > pq -> data[min]) 



    

}


