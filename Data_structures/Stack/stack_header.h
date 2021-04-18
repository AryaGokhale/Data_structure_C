#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack_node 
{
    int data;
    struct Stack_node *next;

}Node;

typedef struct Stack
{
    Node* top;

}Stack;

Stack* createStack();

bool push(int data, Stack* stack);

int pop(Stack* stack);

void display(Stack* stack);


