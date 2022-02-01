#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 5
struct Graph *graph;
struct Graph *gr;
int stack[MAX_SIZE], top;

struct adj_list_node
{
    int dest;
    int weight;
    struct adj_list_node *next;
};
struct adj_list
{
    struct adj_list_node *head;
};
struct Graph
{
    int V;
    int *visited;
    struct adj_list *array;
};

void push(int x)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("\n\tSTACK is over flow");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top <= -1)
    {
        printf("Stack is under flow\n");
    }
    else
    {
        top--;
    }
}

struct adj_list_node *new_adj_list_node(int dest)
{
    struct adj_list_node *newNode = (struct adj_list_node *)malloc(sizeof(struct adj_list_node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void get_transpose(struct Graph *gr, int src, int dest)
{
    struct adj_list_node *newNode = new_adj_list_node(src);
    newNode->next = gr->array[dest].head;
    gr->array[dest].head = newNode;
}

struct Graph *create_graph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct adj_list *)malloc(V * sizeof(struct adj_list));
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void add_edge(struct Graph *graph, struct Graph *gr, int src, int dest)
{
    struct adj_list_node *newNode = new_adj_list_node(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    get_transpose(gr, src, dest);
}
void print_graph(struct Graph *graph1)
{
    int v;
    for (v = 0; v < graph1->V; ++v)
    {
        struct adj_list_node *temp = graph1->array[v].head;
        while (temp)
        {
            printf("%d %d ", v, temp->dest);
            temp = temp->next;
        }
    }
}

void set_fill_order(struct Graph *graph, int v, bool visited[], int *stack)
{
    visited[v] = true;
    int i = 0;
    struct adj_list_node *temp = graph->array[v].head;
    while (temp)
    {
        if (!visited[temp->dest])
        {
            set_fill_order(graph, temp->dest, visited, stack);
        }
        temp = temp->next;
    }
    push(v);
}

void dfs_recursive(struct Graph *gr, int v, bool visited[])
{
    visited[v] = true;
    printf("%d ", v);
    struct adj_list_node *temp = gr->array[v].head;
    while (temp)
    {
        if (!visited[temp->dest])
        {
            dfs_recursive(gr, temp->dest, visited);
        }
        temp = temp->next;
    }
}

void strongly_connected_components(struct Graph *graph, struct Graph *gr, int V)
{
    bool *visited = (bool *)malloc(V * sizeof(bool));
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            set_fill_order(graph, i, visited, stack);
        }
    }
    int count = 1;
    int p = 0;
    for (int i = 0; i < V; i++)
        visited[i] = false;
    while (top != -1)
    {
        int v = stack[top];
        pop();
        if (visited[v] == false)
        {
            // printf("Strongly connected component %d:", count++);
            p++;
            dfs_recursive(gr, v, visited);
        }
    }
    if (p > 1)
        printf("\nNot strongly connected");
    else
        printf("\nstrongly conencted");
}

int main()
{
    top = -1;
    int v = 5;
    struct Graph *graph = create_graph(v);
    struct Graph *gr = create_graph(v);
    add_edge(graph, gr, 1, 0);
    add_edge(graph, gr, 0, 2);
    add_edge(graph, gr, 2, 1);
    add_edge(graph, gr, 0, 3);
    add_edge(graph, gr, 3, 4);
    strongly_connected_components(graph, gr, v);
    return 0;
}