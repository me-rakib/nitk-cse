#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node *insert_data(struct Node * head, int num) 
{
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp -> data = num;
    temp -> next = head;
    head = temp;
    return head;
}

void print(struct Node *head) 
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head -> next;
    }
    printf("\n");
    
} 


int main() 
{
    struct Node *head = NULL;
    int n, num, i;
    printf("Enter total node: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) 
    {
        printf("Enter number: ");
        scanf("%d", &num);
        head = insert_data(head, num);
        print(head);
    }
    return 0;
}