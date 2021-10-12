#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node * Insert(struct Node *temp, int num) 
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = num;
    temp1->next = NULL;
    temp -> next = temp1;
    return temp1;
}
void print() 
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}
void delete (int pos) {
    struct Node *temp = head;
    if(pos == 1) 
    {
        head = temp->next;
        free(temp);
        return;
    }
    struct Node *temp1 = NULL;
    int i;
    for(i=0; i<pos-2; i++) 
    {
        temp = temp -> next;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);

}

int main()
{
    int n, i, num, pos;
    struct Node *temp;
    printf("Total node: ");
    scanf("%d", &n);
    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &num);
    head ->data = num;
    head ->next = NULL;
    temp = head;
    for(i=1; i<n; i++) 
    {
        printf("Enter data: ");
        scanf("%d", &num);
        temp = Insert(temp, num);
    }
    print();

    printf("\nEnter a position to delete: ");
    scanf("%d", &pos);
    delete(pos);
    print();
    return 0;
}