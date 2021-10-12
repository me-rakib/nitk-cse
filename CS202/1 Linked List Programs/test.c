#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\n");
}

struct Node *insert(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp->link = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *temp1 = head;
        while(temp1->link != NULL)
        {
            temp1 = temp1->link;
        }
        temp1->link = temp;
    }
    return head;
}

// struct Node *reverse(struct Node *head)
// {
//     struct Node *prev, *current, *next;
//     current = head;
//     prev = NULL;
//     while (current != NULL)
//     {
//         next = current->link;
//         current->link = prev;
//         prev = current;
//         current = next;
//     }
//     head = prev;
//     return head;
// }

// struct Node *insert(struct Node *head, int data)
// {
//     struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
//     temp -> data = data;
//     temp ->link = NULL;

//     if(head == NULL) 
//     {
//         head = temp;
//     }
//     else 
//     {
//         struct Node *temp1 = head;
//         temp->link = temp1;
//         head = temp;   
//     }
//     return head;
// }

// struct Node * delete_1st(struct Node * head) 
// {
//     struct Node *temp = head;
//     head = temp->link;
//     free(temp);
//     return head;
// }

// struct Node *delete_lst(struct Node *head) 
// {
//     struct Node * to_delete = head, *second_last_node=NULL;
//     while(to_delete->link != NULL) 
//     {
//         second_last_node = to_delete;
//         to_delete = to_delete->link;
//     }
//     if(to_delete == head) 
//     {
//         head = NULL;
//     }
//     else
//     {
//         second_last_node->link = NULL;
//     }
//     free(to_delete);
//     return head;
// }

// struct Node *delete_nth(struct Node *head, int pos)
// {
//     struct Node * temp = head;
//     if(pos == 1) 
//     {
//         head = temp->link;
//         free(temp);
//     }
//     else
//     {
//         struct Node *temp1 = NULL;
//         int i;
//         for(i=0; i<pos-2; i++) 
//         {
//             temp = temp->link;
//         }
//         temp1 = temp->link;
//         temp->link = temp1->link;

//         free(temp1);
//     }
//     return head;
// }

struct Node *insert_nth(struct Node *head, int pos, int data) 
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp ->data = data;
    temp->link = NULL;
    if(pos == 1) 
    {
        temp->link = head;
        head = temp;
    }
    else
    {
        int i;
        struct Node *temp1 = head;
        for(i=0; i<pos-2; i++) 
        {
            temp1 = temp1->link;
        }
        temp->link = temp1->link;
        temp1->link = temp;
    }
    return head;
}

// void recursion_print(struct Node *p) 
// {
//     if(p==NULL) 
//     {
//         return;
//     }
//     printf("%d ", p->data);
//     recursion_print(p->link);
// }

// void reverse_print(struct Node *p) 
// {
//     if(p==NULL) return;
//     reverse_print(p->link);
//     printf("%d ", p->data);
// }

int main()
{
    struct Node *head = NULL;
    head = insert(head, 5);
    head = insert(head, 50);
    head = insert(head, 10);
    head = insert(head, 100);
    print(head);
    // head = delete_1st(head);
    // head = delete_lst(head);
    // head = delete_nth(head, 3);
    head = insert_nth(head, 3, 12);
    print(head);
    // printf("Print using recursion: ");
    // recursion_print(head);
    // printf("\nPrint reverse order: ");
    // reverse_print(head);
    head = recursion_reverse(head)
    return 0;
}