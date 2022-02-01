#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int totalVertices;
    int *visited;
    struct Node **adjList;
};

int flag;
struct Graph *graph;

struct Node *createNode(int v);
struct Graph *createGraph(int v);
void printGraph();
void addEdge(int src, int dest);
void search(int vertex, int sver);
void DFS_noprint(int vertex);

void resetVisited()
{
    int i;
    for (i = 0; i < graph->totalVertices; i++)
    {
        graph->visited[i] = 0;
    }
}

void connected()
{
    int i;
    DFS_noprint(0);
    for (i = 0; i < graph->totalVertices; i++)
    {
        if (graph->visited[i] == 0)
        {
            printf("Not Connected");
            return;
        }
    }
    printf("Connected\n");
}

void DFS(int vertex)
{
    struct Node *adjList = graph->adjList[vertex];
    struct Node *temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0)
        {
            DFS(connectedVertex);
        }
        temp = temp->next;
    }
}

void insert()
{
    int i, src, dest, edge;
    printf("Total edge: ");
    scanf("%d", &edge);
    for (i = 0; i < edge; i++)
    {
        printf("Enter src & dest: ");
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }
    printf("\n");
}

int main()
{
    int i, ver, op, total_node;
    printf("Total node: ");
    scanf("%d", &total_node);
    graph = createGraph(total_node);
    printf("\n1. Insert\n");
    printf("2. DFS_Display\n");
    printf("3. DFS_Search\n");
    printf("4. DFS_Connected\n");
    printf("0. Exit\n\n");

    while (1)
    {
        printf("Enter Option: ");
        scanf("%d", &op);
        if (op == 0)
        {
            printf("Exit");
            break;
        }
        switch (op)
        {
        case 1:
            insert();
            break;
        case 2:
            resetVisited();
            printf("Enter vertex: ");
            scanf("%d", &ver);
            DFS(ver);
            printf("\n\n");
            break;
        case 3:
            flag = 0;
            resetVisited();
            printf("Search for: ");
            scanf("%d", &ver);
            search(0, ver);
            if (flag == 0)
            {
                printf("Not Found");
            }
            printf("\n\n");
            break;
        case 4:
            connected();
            break;
        default:
            printf("Wrong Input\n\n");
            break;
        }
    }

    // for(i=0; i<total_node; i++)
    // graph = createGraph(4);
    // addEdge(0, 1);
    // addEdge(0, 2);
    // addEdge(1, 2);
    // addEdge(2, 3);
    // // printGraph();
    // DFS(2);
}

struct Node *createNode(int v)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->vertex = v;
    newP->next = NULL;
    return newP;
}

struct Graph *createGraph(int v)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->totalVertices = v;
    graph->adjList = (struct Node **)malloc(v * sizeof(struct Node *));
    graph->visited = (int *)malloc(v * sizeof(int));
    int i;
    for (i = 0; i < v; i++)
    {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph()
{
    int v;
    for (v = 0; v < graph->totalVertices; v++)
    {
        struct Node *temp = graph->adjList[v];
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void search(int vertex, int sver)
{
    struct Node *adjList = graph->adjList[vertex];
    struct Node *temp = adjList;

    if (flag == 0)
    {
        graph->visited[vertex] = 1;
        printf("%d -> ", vertex);
        if (vertex == sver)
        {
            printf("Found ");
            flag = 1;
        }

        while (temp != NULL)
        {
            int connectedVertex = temp->vertex;

            if (graph->visited[connectedVertex] == 0)
            {
                search(connectedVertex, sver);
            }
            temp = temp->next;
        }
    }
}

void DFS_noprint(int vertex)
{
    struct Node *adjList = graph->adjList[vertex];
    struct Node *temp = adjList;

    graph->visited[vertex] = 1;
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0)
        {
            DFS_noprint(connectedVertex);
        }
        temp = temp->next;
    }
}