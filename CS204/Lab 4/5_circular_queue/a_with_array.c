#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

// functions decleration
bool is_full();
bool is_empty();
void enqueue(int data);
void dequeue();
void print();

int arr[MAX_SIZE], front = -1, rear = -1;

int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    print();
    dequeue();
    print();
    dequeue();
    print();
}

// adding element into rear
void enqueue(int data)
{
    if (is_full(front, rear))
    {
        printf("\nQueue is full\n");
        return;
    }
    else if (is_empty(front, rear))
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }
    arr[rear] = data;
}

// deleting element from front
void dequeue()
{
    if (is_empty(front, rear))
    {
        printf("\nQueue is empty\n");
        return;
    }
    front = (front + 1) % MAX_SIZE;
}

// printing data
void print()
{
    int i, ind, size;
    size = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
    for (i = 0; i < size; i++)
    {
        ind = (front + i) % MAX_SIZE;
        printf("%d ", arr[ind]);
    }
    printf("\n");
}

// checking the queue is full or not
bool is_full()
{
    return (rear + 1) % MAX_SIZE == front ? true : false;
}

// checking if the queue has element or not
bool is_empty()
{
    return (front == -1 && rear == -1);
}