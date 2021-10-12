#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float coeffi;
    int expo;
    struct Node *next;
};

void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("(%.1fx^%d)", head->coeffi, head->expo);
        head = head->next;
        if(head != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Node *insert(struct Node *head, float co, int exp)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->coeffi = co;
    newP->expo = exp;
    newP->next = NULL;

    if (head == NULL || exp > head->expo)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL && exp < temp->next->expo)
        {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}

int main()
{
    struct Node *head = NULL;
    head = insert(head, 10, 1);
    head = insert(head, 11, 2);
    head = insert(head, 12, 3);
    head = insert(head, -13, 4);
    head = insert(head, 14, 5);
    head = insert(head, 15, 6);
    print(head);
    return 0;
}