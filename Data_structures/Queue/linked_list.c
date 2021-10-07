#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

Node *createnode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
    {
        return false;
    }

    else
    {
        node->data = data;
        node->next = NULL;
    }

    return node;
}

LinkedList *createQueue()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

bool add(int data, LinkedList *list)
{
    Node *current = NULL;
    Node *node = createnode(data);

    if (node == NULL)
    {
        return false;
    }

    else
    {
        if (list->head == NULL)
        {
            list->head = node;
        }

        else
        {
            current = list->head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = node;
        }
    }

    return true;
}

bool del(LinkedList *list)
{

    Node *current = list->head;

    if (current != NULL)
    {
        list->head = current->next;
        free(current);
    }

    return true;
}

void display(LinkedList *list)
{
    Node *current = list->head;
    if (list->head == NULL)
    {
        printf("ERROR");
    }

    for (; current != NULL; current = current->next)
    {
        printf("%d ", current->data);
    }
}
