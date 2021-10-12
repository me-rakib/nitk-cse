#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

// struct Node *add_to_empty(int data) 
// {
//     struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
//     temp->data = data;
//     temp->next = temp;
//     return temp;
// }

// struct Node * add_to_beg(struct Node *tail, int data) 
// {
//     struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
//     temp->data = data;
//     temp->next = tail->next;
//     tail->next = temp;
//     return tail;
// }

struct Node *insert(struct Node *tail, int data) 
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if(tail == NULL) 
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        return tail;
    }
}

// void print(struct Node *tail) 
// {
//     struct Node *p = tail->next;
//     do{
//         printf("%d ", p->data);
//         p= p->next;
//     } while(p != tail->next);
// }

void print(struct Node *tail) 
{
    struct Node *p = tail->next;
    do{
        printf("%d ", p->data);
        p = p->next;
    }while(p != tail->next);
}

int main()
{
    struct Node *tail = NULL;
    // tail = add_to_empty(10);
    // tail = add_to_beg(tail, 12);
    // tail = add_to_beg(tail, 20);
    tail = insert(tail, 1);
    tail = insert(tail, 2);
    tail = insert(tail, 3);
    tail = insert(tail, 4);
    tail = insert(tail, 5);
    print(tail);
    return 0;
}