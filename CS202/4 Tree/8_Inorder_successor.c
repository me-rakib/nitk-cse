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
    else if(root->data == data)
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

struct Node *find_min(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct Node *inorder_successor(struct Node *root, int data)
{
    struct Node *current = search(root, data);
    if (current == NULL)
    {
        return NULL;
    }
    else if (current->right != NULL)
    {
        return find_min(current->right);
    }
    else
    {
        struct Node *successor = NULL;
        struct Node *ancestor = root;
        while (ancestor != current)
        {
            if (ancestor->data > current->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
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
    root = insert(root, 17);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, 16);
    root = insert(root, 27);
    inorder(root);
    printf("\n");
    struct Node *successor = inorder_successor(root, 12);
    printf("%d ", successor->data);
    return 0;
}