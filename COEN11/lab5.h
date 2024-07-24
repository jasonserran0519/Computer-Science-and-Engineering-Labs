#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LIST_SIZE  10
#define MAX_NAME_LENGTH 10 

struct customer{
    char Name[MAX_NAME_LENGTH];
    int drinks;
}; 

int counter =0;


void AddOrder(struct customer *, int);
void FfOrder(struct customer *);
void list(struct customer *);
void Drink_Size(struct customer *);
int Resize_order(struct customer *);
