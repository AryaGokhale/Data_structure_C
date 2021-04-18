#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_header.h"

Node* createNode(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    
    if (node==NULL)
        return false;
    
    else
    {
        node->data = data;
        node->next = NULL;
    }
    
    return node;

}

Stack* createStack()
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
}

bool push(int data, Stack* stack)
{
    Node* stack_node = (Node*)malloc(sizeof(Node));
    
    if(stack_node != NULL)
    {
        stack_node->data = data;

        if(stack->top==NULL)
        {
            stack->top = stack_node;
        }
        else
        {
            stack_node->next = stack->top;
            stack->top = stack_node;
        }
    }

    else
    {
        return false; 
    }

    return true;
}

int pop(Stack* stack)
{
    if(stack->top != NULL)
    {
        int value = stack->top->data;
        Node* temp = stack->top;
        stack->top = temp->next;
        free(temp);
        return(value);
    }

    else
    {
        return (0);
    }
}

void display(Stack* stack)
{
    Node* current = stack->top;

    if(current == NULL)
    {
        printf("Stack does not exist");
    }
    
    for(;current != NULL; current= current->next)
    {
        printf("%d \n",current->data);

    }

}