#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//#include "/home/ubuntu/Desktop/C/Data_structures/Queue/queue.h"
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

static Node *current ;

typedef struct BinaryTree
{
    Node *root;

} BinaryTree;

static BinaryTree *binarytree;

Node *create_node(int data)
{
    Node *node = (Node *)malloc(sizeof(node));
    if (node == NULL)
    {
        return false;
    }

    else
    {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
}

BinaryTree *create_tree()
{
    BinaryTree *binarytree = (BinaryTree *)malloc(sizeof(BinaryTree));
    binarytree->root = NULL;
}

// void add(BinaryTree *binarytree, int data)
// {
//     Node* node = create_node(data);
//     Node *current = binarytree->root;
//     assert(node != NULL);
//     if (binarytree->root == NULL)
//     {
//         binarytree->root = node;
//     }

//     else
//     {
//         if (data < current->data)
//         {
//             while(current->left != NULL)
//             {
//                 current = current->left;
//                 break;
//             }
//             current->left = node;
//         }

//         else
//         {
//             while(current->right != NULL)
//             {
//                 current = current->right;
//                 break;
//             }

//             current->right = node;
//         }
//     }
// }

Node* add(Node* pnode, int data)
{
    Node* node = create_node(data);
    Node *current = pnode;
    assert(node != NULL);
    if (binarytree->root == NULL)
    {
        binarytree->root = node;
    }

    else
    {
        if(data < current->data)
        {
            if(current->left != NULL)
            {
                add(current->left, data);
            }
            else
            {
                current->left = node;
            }
            
        }
        else
        {
            if(current->right != NULL)
            {
                add(current->right, data);
            }
            else
            {
                current->right = node;
            }
        }
        
    }
    

}


void preorder(Node *node)
{
    if (node != NULL)
    {
        printf("%d \n", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node *node)
{
    if(node != NULL)
    {   
        inorder(node->left);
        printf("%d \n", node->data);
        inorder(node->right);
    }
}

void postorder(Node *node)
{
    if(node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d \n",node->data);
    }
}

Node* minValueNode(Node* node)
{
    while(node && node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, int key)
{
    assert(root != NULL && "Root node was null");
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }

    if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }

    if(root->left == NULL)
    {
        Node* temp = root->right;
        free(root);
        return temp;
    }
    if(root->right == NULL)
    {
        Node* temp = root->left;
        free(root);
        return temp;
    }
    //Both children exist
    else
    {
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
        
    }
    return root;
}

int main()
{
    binarytree = create_tree();
    add(binarytree->root,27);
    add(binarytree->root,14);
    add(binarytree->root,35);
    add(binarytree->root,10);
    add(binarytree->root,19);
    add(binarytree->root,31);
    add(binarytree->root,42);
    
    //preorder(binarytree->root);
    //inorder(binarytree->root);
    postorder(binarytree->root);
    return 0;
}