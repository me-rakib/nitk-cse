#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>

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
        return max(height(root->left), height(root->right)) + 1;
    }
}

void print_current_level(struct Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    else if (level == 1)
    {
        printf("%d ", root->data);
    }
    else
    {
        print_current_level(root->left, level - 1);
        print_current_level(root->right, level - 1);
    }
}

void level_order(struct Node *root)
{
    int h = height(root)+1;
    int i;
    for (i = 1; i <= h; i++)
    {
        print_current_level(root, i);
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
    level_order(root);
    return 0;
}