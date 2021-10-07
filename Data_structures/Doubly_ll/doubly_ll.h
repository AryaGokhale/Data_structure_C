#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedList
{
    Node *head;

} DoublyLinkedList;

bool add(int data, DoublyLinkedList *doublyll);
bool insert(int data, int position, DoublyLinkedList *doublyll);
bool del(int position, DoublyLinkedList *doublyll);
void display(DoublyLinkedList *doublyll);
