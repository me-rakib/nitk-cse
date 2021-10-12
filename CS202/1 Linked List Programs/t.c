#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
 
    *head = newNode;
}
 
// Recursive function to reverse a given linked list. It reverses the
// given linked list by fixing the head pointer and then `.next`
// pointers of every node in reverse order
void reverse(struct Node* curr, struct Node* prev, struct Node** head)
{
    // base case: end of the list reached
    if (curr == NULL)
    {
        // fix head pointer
        *head = prev;
        return;
    }
 
    // recur for the next node and pass the current node as a previous node
    reverse(curr->next, curr, head);
 
    // fix current node (nodes following it are already fixed)
    curr->next = prev;
}
 
// Reverse a given linked list. The function takes a pointer
// (reference) to the head pointer
void Reverse(struct Node** head) {
    reverse (*head, NULL, head);
}
 
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >=0; i--) {
        push(&head, keys[i]);
    }
 
    Reverse(&head);
 
    printList(head);
 
    return 0;
}