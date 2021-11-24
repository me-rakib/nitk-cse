#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node **createQueue(int *front, int *rear)
{
    struct Node **queue = (struct Node **)malloc(sizeof(struct Node *) * MAX_Q_SIZE);
    *front = *rear = 0;
    return queue;
}

void enQueue(struct Node **queue, int *rear, struct Node *newP)
{
    queue[*rear] = newP;
    (*rear)++;
}

struct Node *deQueue(struct Node **queue, int *front)
{
    (*front)++;
    return queue[*front-1];
}


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

void print_level_order(struct Node *root)
{
    int rear, front;
    struct Node **queue = createQueue(&front, &rear);
    struct Node *temp_node = root;

    while(temp_node)
    {
        printf("%d ", temp_node->data);
        if(temp_node->left)
        {
            enQueue(queue, &rear, temp_node->left);
        }
        if(temp_node->right)
        {
            enQueue(queue, &rear, temp_node->right);
        }
        temp_node = deQueue(queue, &front);
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
    print_level_order(root);
    return 0;
}