#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *pre;
    int data;
    struct Node *next;
};

struct Node * circularDoubly(int data) 
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->pre = temp;
    temp->data = data;
    temp->next = temp;

    return temp;
}

int main()
{
    struct Node *tail = NULL;
    tail = circularDoubly(10);

    printf("%d", tail->data);
    return 0;
}