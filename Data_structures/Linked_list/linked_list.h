#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

typedef struct LinkedList
{
    Node *head;

} LinkedList;


LinkedList* createLinkedList();

bool add(int data, LinkedList *list);

bool insert(int data, int position, LinkedList *list);

bool del(int position, LinkedList *list);

void display(LinkedList * list);