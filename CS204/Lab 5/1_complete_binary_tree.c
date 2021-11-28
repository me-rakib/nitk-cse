#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// creating node with data
struct Node *create_node(int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->left = NULL;
    newP->right = NULL;
    return newP;
}

// creating completing bt
struct Node *create_complete_bt(struct Node *root, int *arr, int n, int i)
{
    if (i < n)
    {
        struct Node *temp = create_node(arr[i]);
        root = temp;
        root->left = create_complete_bt(root->left, arr, n, 2 * i + 1);
        root->right = create_complete_bt(root->right, arr, n, 2 * i + 2);
    }
    return root;
}

// returning maximum value
int get_max(int n1, int n2)
{
    return (n1 > n2) ? n1 : n2;
}

// height of the tree
int height(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return get_max(height(root->left), height(root->right)) + 1;
}

// preorder travarsal
void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// inorder travarsal
void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// postorder travarsal
void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// printing level order
void print_level(struct Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}

void level_order(struct Node *root)
{
    int i, level = height(root) + 1;
    for (i = 1; i <= level; i++)
    {
        print_level(root, i);
    }
}

int main()
{
    struct Node *root;
    int i, n, s, *arr;
    printf("1. Insert\n");
    printf("2. Height\n");
    printf("3. Preorder\n");
    printf("4. Postorder\n");
    printf("5. Inorder\n");
    printf("6. Levelorder\n");
    printf("0. Exit\n");

    while (true)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        if (n == 0)
        {
            printf("Program Closed");
            break;
        }
        switch (n)
        {
        case 1:
            printf("Total element: ");
            scanf("%d", &s);
            arr = (int *)malloc(s * sizeof(int));
            for (i = 0; i < s; i++)
            {
                printf("Enter element: ");
                scanf("%d", arr + i);
            }
            root = create_complete_bt(root, arr, s, 0);
            break;
        case 2:
            printf("Tree height: %d\n", height(root));
            break;
        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 6:
            printf("Level order: ");
            level_order(root);
            printf("\n");
            break;
        default:
            printf("\nWrong Input\n");
            break;
        }
    }
    return 0;
}