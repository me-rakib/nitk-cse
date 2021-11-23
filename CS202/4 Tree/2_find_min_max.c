#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_new_node(int data);
struct Node *insert(struct Node *root, int data);
bool search(struct Node *root, int data);
int find_min(struct Node *root);
int find_max(struct Node *root);

int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    // int n;
    // printf("Enter number: ");
    // scanf("%d", &n);
    // if (search(root, n))
    // {
    //     printf("Found");
    // }
    // else
    // {
    //     printf("Not found");
    // }
    printf("Min = %d, Max = %d", find_min(root), find_max(root));
    return 0;
}

int find_min(struct Node *root)
{
    if(root == NULL)
    {
        printf("Error: Empty tree");
        return -1;
    }
    while (root->left != NULL) 
    {
        root = root->left;
    }
    return root->data;
}

int find_max(struct Node *root)
{
    if(root == NULL)
    {
        printf("Error: Empty tree");
        return -1;
    }
    else if(root->right == NULL)
    {
        return root->data;
    }
    return find_max(root->right);
}

struct Node *create_new_node(int data)
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
        root = create_new_node(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(struct Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}