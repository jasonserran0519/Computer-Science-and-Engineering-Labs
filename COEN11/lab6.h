#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIST_SIZE  10
#define MAX_NAME_LENGTH 10

typedef union CONFIRM {
    char PhoneNum[15];
    int Order_Num;
} Confirm;

struct customer{
    char Name[MAX_NAME_LENGTH];
    int drinks;
    int order_origin;
    Confirm number;
};

extern struct customer orders[10];
extern  int counter;

void AddOrder();
void FfOrder();
void list();
void Drink_Size();
void Resize_Order(); 
    
