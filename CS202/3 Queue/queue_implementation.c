#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

bool is_empty(int rear, int front);
bool is_full(int rear, int front);
int get_first(int *arr, int rear, int front);
void enqueue(int data, int *arr, int *rear, int *front);
void dequeue(int *rear, int *front);
void print(int *arr, int rear, int front);

int main()
{
    int arr[MAX_SIZE], front = -1, rear = -1;
    enqueue(10, arr, &rear, &front);
    enqueue(202, arr, &rear, &front);
    enqueue(30, arr, &rear, &front);
    enqueue(14, arr, &rear, &front);
    enqueue(5, arr, &rear, &front);
    dequeue(&rear, &front);
    dequeue(&rear, &front);
    print(arr, rear, front);
    return 0;
}

void enqueue(int data, int *arr, int *rear, int *front)
{
    if (is_full(*rear, *front))
    {
        printf("Queue is full\n");
        return;
    }
    else if (is_empty(*rear, *front))
    {
        *rear = 0;
        *front = 0;
    }
    else
    {
        *rear = (*rear + 1) % MAX_SIZE;
    }
    arr[*(rear)] = data;
}

void dequeue(int *rear, int *front)
{
    if (is_empty(*rear, *front))
    {
        printf("Queue is empty\n");
        return;
    }
    *front = (*front + 1) % MAX_SIZE;
}

bool is_empty(int rear, int front)
{
    return (rear == -1 && front == -1);
}

bool is_full(int rear, int front)
{
    return (rear + 1) % MAX_SIZE == front ? true : false;
}

int get_first(int *arr, int rear, int front)
{
    if (is_empty(rear, front))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return arr[front];
}

void print(int *arr, int rear, int front)
{
    int i, total, ind;
    total = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
    for (i = 0; i < total; i++)
    {
        ind = (front + i) % MAX_SIZE;
        printf("%d ", arr[ind]);
    }
    printf("\n");
}