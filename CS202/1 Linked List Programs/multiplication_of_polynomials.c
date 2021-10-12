#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float coefficient;
    int exponent;
    struct Node *next;
};

void print(struct Node *head)
{
    if (head == NULL)
    {
        printf("Noting in the list");
    }
    else
    {
        while (head != NULL)
        {
            printf("(%.1fx^%d)", head->coefficient, head->exponent);
            head = head->next;
            if (head != NULL)
            {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

struct Node *insert(struct Node *head, float co, int expo)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->coefficient = co;
    temp->exponent = expo;
    temp->next = NULL;

    if (head == NULL || expo > head->exponent)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        struct Node *temp1 = head;
        while (temp1->next != NULL && expo < temp1->next->exponent)
        {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
    return head;
}

struct Node *create_node(struct Node *head)
{
    int i, n, exponent;
    float coeffi;
    printf("Total node: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%f %d", &coeffi, &exponent);
        head = insert(head, coeffi, exponent);
    }
    return head;
}

void multiplication(struct Node *head1, struct Node *head2)
{
    struct Node *ptr1 = head1;
    struct Node *ptr2 = NULL;
    struct Node *head3 = NULL;

    float co;
    int expo;
    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2 != NULL)
        {
            co = ptr1->coefficient * ptr2->coefficient;
            expo = ptr1->exponent + ptr2->exponent;
            head3 = insert(head3, co, expo);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    print(head3);

    struct Node *ptr3 = head3;
    struct Node *temp = NULL;

    while(ptr3->next != NULL)
    {
        if(ptr3->exponent == ptr3->next->exponent)
        {
            ptr3->coefficient = ptr3->coefficient + ptr3->next->coefficient;
            temp = ptr3->next;
            ptr3->next = ptr3->next->next;
            free(temp);
            temp = NULL;
        }
        else
        {
            ptr3 = ptr3->next;
        }
    }
    print(head3);
    
}

void mull_effi(struct Node *head)
{
    struct Node *temp = NULL;
    struct Node *ptr = head;

    while (ptr->next != NULL)
    {
        if (ptr->coefficient == ptr->next->coefficient)
        {
            ptr->coefficient = ptr->coefficient + ptr->next->coefficient;
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
            temp = NULL;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    print(head);
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;
    head1 = create_node(head1);
    head2 = create_node(head2);
    print(head1);
    print(head2);
    multiplication(head1, head2);
    
    return 0;
}