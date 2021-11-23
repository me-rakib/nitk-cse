#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *get_new_node(int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->left = NULL;
    newP->right = NULL;
    return newP;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = get_new_node(data);
    }
    else if (root->data >= data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int max(int n1, int n2)
{
    return n1 > n2 ? n1 : n2;
}

int height(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return max(height(root->left), height(root->right))+1;
    }
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 30);
    printf("%d", height(root));
    return 0;
}