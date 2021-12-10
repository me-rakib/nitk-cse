#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

bool isEmpty(struct Queue *q);
bool isFull(struct Queue *q);
void enqueue(struct Queue *q, int data);
int dequeue(struct Queue *q);
void insert(int edge);
void BFS_display(int ver);
void BFS_connect(int ver);
void BFS_search(int ver);

int visited[MAX_SIZE], adj_matrix[MAX_SIZE][MAX_SIZE];

int main()
{

    int num, ver, edge;
    printf("Enter total vertices and edge: ");
    scanf("%d %d", &ver, &edge);

    printf("\nOptions \n");
    printf("1. Insert\n");
    printf("2. BFS_Display\n");
    printf("3. BFS_Search\n");
    printf("2. BFS_Connect\n");

    while (true)
    {
        printf("\nEnter choice: ");
        scanf("%d", &num);
        if (num == 0)
        {
            printf("Program Exit");
            break;
        }
        switch (num)
        {
        case 1:
            insert(edge);
            break;
        case 2:
            BFS_display(ver);
            break;
        case 3:
            BFS_search(ver);
            break;
        case 4:
            BFS_connect(ver);
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    }
    return 0;
}

void insert(int edge)
{
    int i, src, dest;
    for (i = 0; i < edge; i++)
    {
        printf("Enter soruce and destination: ");
        scanf("%d %d", &src, &dest);
        adj_matrix[src][dest] = 1;
        adj_matrix[dest][src] = 1;
    }
}

void BFS_display(int ver)
{
    int i, j;
    struct Queue q;
    q.size = 100;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    for (i = 0; i < ver; i++)
    {
        visited[i] = 0;
    }

    int node;
    int start;
    printf("Enter starting position: ");
    scanf("%d", &start);
    printf("%d ", start);

    visited[start] = 1;
    enqueue(&q, start);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (j = 0; j < ver; j++)
        {
            if (adj_matrix[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    printf("\n");
}

void BFS_connect(int ver)
{
    int i, j, tn = 1;
    struct Queue q;
    q.size = 100;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    for (i = 0; i < ver; i++)
    {
        visited[i] = 0;
    }

    int node;
    int start = 0;

    visited[start] = 1;
    enqueue(&q, start);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (j = 0; j < ver; j++)
        {
            if (adj_matrix[node][j] == 1 && visited[j] == 0)
            {
                tn++;
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    if (tn == ver)
    {
        printf("Connected");
    }
    else
    {
        printf("Not connected");
    }
    printf("\n");
}

void BFS_search(int ver)
{
    int i, j, search_val;
    printf("Search for: ");
    scanf("%d", &search_val);
    bool found = false;
    struct Queue q;
    q.size = 100;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    for (i = 0; i < ver; i++)
    {
        visited[i] = 0;
    }

    int node;
    int start = 0;
    printf("%d -> ", start);
    if (start == search_val)
    {
        printf("Found");
        return;
    }

    visited[start] = 1;
    enqueue(&q, start);
    while (!isEmpty(&q) && !found)
    {
        int node = dequeue(&q);
        for (j = 0; j < ver && !found; j++)
        {
            if (adj_matrix[node][j] == 1 && visited[j] == 0)
            {
                printf("%d -> ", j);
                if (search_val == j)
                {
                    found = true;
                    printf("Found");
                }
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    if (!found)
    {
        printf("Not Found");
    }
    printf("\n");
}

bool isEmpty(struct Queue *q)
{
    if (q->front == q->rear)
    {
        return true;
    }
    return false;
}

bool isFull(struct Queue *q)
{
    if (q->front == q->size - 1)
    {
        return true;
    }
    return false;
}

void enqueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is already full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = data;
    }
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is already empty\n");
        return -1;
    }
    q->front++;
    return q->arr[q->front];
}