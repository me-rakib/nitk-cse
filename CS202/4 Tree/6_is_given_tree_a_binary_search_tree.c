#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(struct Node *root, int data)
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
        root = create_node(root, data);
    }
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// bool check_left(struct Node *root, int data)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     if (root->data < data && check_left(root->left, data) &&
//              check_left(root->right, data))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool check_right(struct Node *root, int data)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     if (root->data > data && check_right(root->left, data) &&
//              check_right(root->right, data))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool is_binary_search_tree(struct Node *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     else if (check_left(root->left, root->data) && check_right(root->right, root->data) && is_binary_search_tree(root->left) && is_binary_search_tree(root->right))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool is_BST(struct Node *root, int min, int max)
// {
//     if(root == NULL)
//     {
//         return true;
//     }
//     else if(root->data > min && root->data < max && is_BST(root->left, min, root->data) && is_BST(root->right, root->data, max))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

bool is_BST(struct Node *root, int prev)
{
    if (root)
    {
        if (!is_BST(root->left, prev))
            return false;
        if (root->data < prev)
            return false;
        return is_BST(root->right, root->data);
    }
    return true;
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

    if (is_BST(root, -1000))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}