#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// implementation of stack
struct stack_node
{
    struct Node *t;
    struct stack_node *next;
};

void push(struct stack_node **top, struct Node *tree);
struct Node *pop(struct stack_node **top);
bool isEmpty(struct stack_node *top);

// creating new node for tree
struct Node *create_node(struct Node *head, int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->left = NULL;
    newP->right = NULL;
    return newP;
}

// inserting data into tree
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

// return address containg max value
struct Node *BST_Findmax(struct Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// return address containing min value
struct Node *BST_Findmin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// searching data
struct Node *BSTSearch(struct Node *root, int data)
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
        return BSTSearch(root->left, data);
    }
    else if (root->data < data)
    {
        return BSTSearch(root->right, data);
    }
}

// deleting data
struct Node *BST_delete(struct Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data > data)
    {
        root->left = BST_delete(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = BST_delete(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }
        else
        {
            struct Node *temp = BST_Findmin(root->right);
            root->data = temp->data;
            root->right = BST_delete(root->right, temp->data);
        }
    }
    return root;
}

// get successor
struct Node *inorder_successor(struct Node *root, int data)
{
    struct Node *current = BSTSearch(root, data);
    if (current == NULL)
    {
        return NULL;
    }
    else if (current->right != NULL)
    {
        return BST_Findmin(current->right);
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

// get predecessor
struct Node *inorder_predecessor(struct Node *root, int data)
{
    struct Node *pre = NULL;
    struct Node *current = root;

    if (current == NULL)
    {
        return NULL;
    }
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
        pre = BST_Findmax(current->left);
    }
    return pre;
}

// inorder traversal using stack
void BST_inorder_stack(struct Node *root)
{
    struct Node *current = root;
    struct stack_node *s = NULL;

    while (true)
    {
        if (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                printf("%d ", current->data);
                current = current->right;
            }
            else
            {
                break;
            }
        }
    }
}

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

int main()
{
    struct Node *root = NULL;
    int i, n, num, t_n;
    printf("1. BSTInsert\n");
    printf("2. BSTSearch\n");
    printf("3. BSTInorderStack\n");
    printf("4. BSTDelete\n");
    printf("5. BST_Successor\n");
    printf("6. BST_Predecessor\n");
    printf("7. BST_Findmin\n");
    printf("8. BST_Findmax\n");
    printf("0. Exit Program\n");
    while (1)
    {
        printf("\nEnter Option: ");
        scanf("%d", &n);
        if (n == 0)
        {
            printf("Program Exit");
            break;
        }
        switch (n)
        {
        case 1:
            printf("Total Node: ");
            scanf("%d", &t_n);
            for (i = 0; i < t_n; i++)
            {
                printf("Enter Number: ");
                scanf("%d", &num);
                root = BSTInsert(root, num);
            }
            break;
        case 2:
            printf("Enter number to search: ");
            scanf("%d", &num);
            if (BSTSearch(root, num))
            {
                printf("%d is listed in the tree\n", BSTSearch(root, num)->data);
            }
            else
            {
                printf("Not Found\n");
            }
            break;
        case 3:
            printf("Inorder: ");
            BST_inorder_stack(root);
            printf("\n");
            break;
        case 4:
            printf("Enter data to delete: ");
            scanf("%d", &num);
            printf("Before delete: ");
            inorder(root);
            root = BST_delete(root, num);
            printf("\nAfter delete: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter number: ");
            scanf("%d", &num);
            printf("Successor of %d is %d\n", num, inorder_successor(root, num)->data);
            break;
        case 6:
            printf("Enter number: ");
            scanf("%d", &num);
            printf("Predecessor of %d is %d\n", num, inorder_predecessor(root, num)->data);
            break;
        case 7:
            printf("\nMinimun data: %d\n", BST_Findmin(root)->data);
            break;
        case 8:
            printf("\nMaxmum data: %d\n", BST_Findmax(root)->data);
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    }
}

void push(struct stack_node **top, struct Node *tree)
{
    struct stack_node *newP = (struct stack_node *)malloc(sizeof(struct stack_node));
    newP->t = tree;
    newP->next = *top;
    *top = newP;
}

bool isEmpty(struct stack_node *top)
{
    return (top == NULL) ? true : false;
}

struct Node *pop(struct stack_node **top)
{
    struct Node *res;
    struct stack_node *temp;
    temp = *top;
    res = temp->t;
    *top = temp->next;
    return res;
}