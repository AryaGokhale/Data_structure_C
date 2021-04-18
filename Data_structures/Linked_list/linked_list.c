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

LinkedList *createLinkedList()
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


bool insert(int data, int position, LinkedList *list)
{
    Node *node = createnode(data);

    if (node == NULL)
    {
        return false;
    }

    else
    {
        if (position == 1)
        {
            node->next = list->head;
            list->head = node;
        }

        else
        {

            Node *current = list->head;
            for (int i = 1; i < position - 1 && current; i++)
            {
                current = current->next;
            }

            if (current != NULL)

            {
                node->next = current->next;
                current->next = node;
            }

            else
            {
                return false;
            }

        }
    }
    return true;
}

bool del(int position, LinkedList *list)
{
    if (position < 1)
    {
        return false;
    }

    if (position == 1)
    {
        Node *current = list->head;

        if (current != NULL)
        {
            list->head = current->next;
            free(current);
        }
    }

    else

    {
        Node *current = list->head;

        for (int i = 1; i < position - 1; i++)
        {
            current = current->next;
    
        }

        if (current == NULL)
        {
            return false;
        }
        
        else
        {
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);       
        }
    }

    return true;
}


void display(LinkedList * list)
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

