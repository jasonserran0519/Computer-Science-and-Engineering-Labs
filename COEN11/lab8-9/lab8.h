#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIST_SIZE  10
#define MAX_NAME_LENGTH 10
#define NODE struct node 

struct node {
    char Name[MAX_NAME_LENGTH];
    int drinks;
    NODE *next;
};

NODE *Head;
NODE *Tail;
int counter;

void AddOrder(char *, int);
void FfOrder();
void list();
void Drink_Size();
void Reverse();
void listL();
void delete();

int check_duplicates();
int  read();
int save();
int Reverse_list(NODE *);
int Length_of_List();
int delete_list();

