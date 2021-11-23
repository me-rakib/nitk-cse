#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(struct Node *head, int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->left = NULL;
    newP->right = NULL;
    return newP;
}

struct Node *BSTInsert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = create_node(root, data);
    }
    else if (root->data > data)
    {
        root->left = BSTInsert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = BSTInsert(root->right, data);
    }
    return root;
}

int BST_Findmax(struct Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int BST_Findmin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

bool BSTSearch(struct Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (root->data > data)
    {
        return BSTSearch(root->left, data);
    }
    else if (root->data < data)
    {
        return BSTSearch(root->right, data);
    }
}

int main()
{
    struct Node *root = NULL;
    root = BSTInsert(root, 15);
    root = BSTInsert(root, 10);
    root = BSTInsert(root, 20);
    root = BSTInsert(root, 25);
    root = BSTInsert(root, 8);
    root = BSTInsert(root, 12);
    printf("%d\n", BST_Findmax(root));
    printf("%d\n", BST_Findmin(root));

    if (BSTSearch(root, 25))
    {
        printf("Found");
    }
    else
    {
        printf("Not Found");
    }
    return 0;
}