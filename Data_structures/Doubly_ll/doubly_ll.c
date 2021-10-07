#include <stdio.h>
#include <stdbool.h>
#include "doubly_ll.h"

Node *create_node(int data)
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
        node->prev = NULL;
    }

    return node;
}

DoublyLinkedList *create_list()
{
    DoublyLinkedList *doublyLL = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    doublyLL->head = NULL;
    return doublyLL;
}

bool add(int data, DoublyLinkedList *doublyll)
{
    Node *node = create_node(data);
    Node *current = NULL;

    if (node == NULL)
    {
        return false;
    }

    else
    {
        if (doublyll->head == NULL)
        {
            doublyll->head = node;
        }
        else
        {
            current = doublyll->head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = node;
            node->prev = current;
        }
    }
    return true;
}

bool insert(int data, int position, DoublyLinkedList *doublyll)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        return false;
    }
    else
    {
        if (position == 1)
        {
            node->next = doublyll->head;
            doublyll->head->prev = node;
            doublyll->head = node;
        }
        else
        {
            Node *current = doublyll->head;
            for (int i = 1; i < position; i++)
            {
                current = current->next;
            }

            if (current != NULL)
            {
                current->next->prev = node;
                node->next = current->next;
                node->prev = current;
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

bool del(int position, DoublyLinkedList *doublyll)
{
    if (position < 1)
    {
        return false;
    }

    if (position == 1)
    {
        Node *current = doublyll->head;
        if (current != NULL)
        {
            doublyll->head = current->next;
            free(current);
        }
    }

    else
    {
        Node *current = doublyll->head;
        for (int i = 1; i < position; i++)
        {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = current->next->next;
        current->next->next->prev = current;
        free(temp);
    }
    return true;
}

void display(DoublyLinkedList *doublyll)
{
    Node *current = doublyll->head;
    if(current == NULL)
    {
        printf("ERROR");
    }

    for(;current != NULL; current = current->next)
    {
        printf("%d",current->data);
    }
}
