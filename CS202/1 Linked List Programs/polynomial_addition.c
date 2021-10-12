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
        if (head != NULL)
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

struct Node *create_head(struct Node *head)
{
    int n, i, ex;
    float co;
    printf("Enter total expo in node: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%f %d", &co, &ex);
        head = insert(head, co, ex);
    }
    return head;
}


void add(struct Node *head1, struct Node *head2)
{
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;
    struct Node *head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, head1->coeffi + head2->coeffi, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeffi, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3 = insert(head3, ptr2->coeffi, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coeffi, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coeffi, ptr2->expo);
        ptr2 = ptr2->next;
    }  
    print(head3);

}

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    head1 = create_head(head1);
    head2 = create_head(head2);
    print(head1);
    print(head2);
    add(head1, head2);
    return 0;
}