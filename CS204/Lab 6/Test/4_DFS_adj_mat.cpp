#include<iostream>
using namespace std;

int adj[50][50];
int node, edge;
int color[100];

#define w 0
#define G 11
#define B 22

void visit(int x)
{
    color[x] = G;
    for(int i=1; i<=node; i++)
    {
        if(adj[x][i] == 1)
        {
            if(color[i] == w)
            {
                visit(i);
            }
        }
    }
    cout << x << " ";
    color[x] = B;
}

void DFS()
{
    for(int i=1; i<=node; i++)
    {
        if(color[i] == w)
        {
            visit(i);
        }
    }
}

int main()
{
    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        int s, d;
        cin >> s >> d;
        adj[s][d] = 1;
        adj[d][s] = 1;
    }
    DFS();
    return 0;
}