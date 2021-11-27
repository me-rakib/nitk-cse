#include <stdio.h>
#include <stdlib.h>

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

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct Node *search(struct Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == data)
    {
        return root;
    }
    else if (root->data > data)
    {
        return search(root->left, data);
    }
    else if (root->data < data)
    {
        return search(root->right, data);
    }
}

struct Node *find_max(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node * inorder_predecessor(struct Node *root, int data)
{
    struct Node *pre = NULL;
    struct Node *current = root;

    if (root == NULL)
        return NULL;
    while (current && current->data != data)
    {
        if (current->data > data)
        {
            current = current->left;
        }
        else
        {
            pre = current;
            current = current->right;
        }
    }
    if (current && current->left)
    {
        pre = find_max(current->left);
    }
    return pre;
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
    root = insert(root, 17);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, 16);
    root = insert(root, 27);
    inorder(root);
    printf("\n");
    struct Node *pre = inorder_predecessor(root, 11);
    printf("%d ", pre->data);
    return 0;
}