#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float coefficient;
    int exponent;
    struct Node *next;
};

// declarig function
void print(struct Node *head);
struct Node *insert(struct Node *head, float coefficient, int exponent);
struct Node *add(struct Node *head1, struct Node *head2);

int main()
{
    freopen("5_input.txt", "r", stdin);
    freopen("5_output.txt", "w", stdout);

    struct Node *head1 = NULL, *head2 = NULL, *result = NULL;
    int i, j, n, exponent;
    float coefficient;

    // taking input for polynomial one
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%f %d",&coefficient, &exponent);
        head1 = insert(head1, coefficient, exponent);
    }  
    printf("Polynomial 1: ");
    print(head1);

    // taking input for polynomial two
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%f %d",&coefficient, &exponent);
        head2 = insert(head2, coefficient, exponent);
    }
    printf("Polynomial 2: ");
    print(head2);

    // Printing result
    result = add(head1, head2);
    printf("Addition: ");
    print(result);
    return 0;
}

// function to add two polynomials
struct Node *add(struct Node *head1, struct Node *head2)
{
    struct Node *temp1 = head1, *temp2 = head2, *result = NULL;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->exponent == temp2->exponent)
        {
            result = insert(result, temp1->coefficient + temp2->coefficient, temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->exponent > temp2->exponent)
        {
            result = insert(result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        }
        else if(temp1->exponent < temp2->exponent)
        {
            result = insert(result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL)
    {
        result = insert(result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }
    while(temp2 != NULL)
    {
        result = insert(result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }
    return result;
}

// function to insert polynomials in descending order
struct Node *insert(struct Node *head, float coefficient, int exponent)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->coefficient = coefficient;
    newP->exponent = exponent;
    newP->next = NULL;

    if (head == NULL || exponent > head->exponent)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL && temp->next->exponent > exponent)
        {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}

// function to print polynomials
void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%.1fx^%d", head->coefficient, head->exponent);
        head = head->next;
        if (head != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}