/*
1. Store each vertex’s In-Degree in an array D

2. Initialize queue with all “in-degree=0” vertices

3. While there are vertices remaining in the queue:

              (a) Dequeue and output a vertex

              (b) Reduce In-Degree of all vertices adjacent to it by 1

              (c) Enqueue any of these vertices whose In-Degree became zero

 4. If all vertices are output then success, otherwise there is a cycle.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

int vertex, adj_matrix[MAX_SIZE][MAX_SIZE], indegree[MAX_SIZE];
int queue[MAX_SIZE], front = -1, rear = -1;

void create_graph();
void calc_indegree();
void enqueue(int ver);
int dequeue();
int isEmpty();

int main()
{
    int i, v, count = 0, res[MAX_SIZE];
    create_graph();
    calc_indegree();

    while (!isEmpty() && count < vertex)
    {
        v = dequeue();
        res[count++] = v;
        for (i = 0; i < vertex; i++)
        {
            if (adj_matrix[v][i] == 1)
            {
                adj_matrix[v][i] = 0;
                indegree[i] = indegree[i] - 1;
                if (indegree[i] == 0)
                {
                    enqueue(i);
                }
            }
        }
    }
    
    for(i=0; i<vertex; i++)
    {
        printf("%d ", res[i]);
    }

    // 6
    // 5 2, 5 0, 4 0, 4 1, 2 3, 3 1
}

void create_graph()
{
    int src, dest;
    printf("Enter total vertex: ");
    scanf("%d", &vertex);

    while (true)
    {
        printf("Enter src & dest (-1,-1 to quit): ");
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
        {
            break;
        }
        adj_matrix[src][dest] = 1;
    }
}

void calc_indegree()
{
    int i, j, ind;
    for (i = 0; i < vertex; i++)
    {
        ind = 0;
        for (j = 0; j < vertex; j++)
        {
            if (adj_matrix[j][i] == 1)
            {
                ind++;
            }
        }
        indegree[i] = ind;
        if (indegree[i] == 0)
        {
            enqueue(i);
        }
    }
}

void enqueue(int ver)
{
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = ver;
}

int isEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
} 

int dequeue()
{
    int temp = queue[front];
    front++;
    return temp;
}