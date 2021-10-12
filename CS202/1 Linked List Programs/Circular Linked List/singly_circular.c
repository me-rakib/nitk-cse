#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * circularSingly(int data) 
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp;

    return temp;
}

int main()
{
    struct Node *tail = NULL;
    tail = circularSingly(45);

    printf("%d", tail->data);
    return 0;
}