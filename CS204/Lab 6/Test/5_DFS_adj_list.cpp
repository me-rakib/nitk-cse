#include <iostream>
#include <vector>
using namespace std;

#define w 0
#define G 11
#define B 22

vector<int> adj[100];
int color[100];
int node, edge;

void visit(int x)
{
    color[x] = G;
    for (int i = 0; i < adj[x].size(); i++)
    {
        int u = adj[x][i];
        if (color[u] == w)
        {
            visit(u);
        }
    }
    color[x] = B;
    cout << x << " ";
}

void dfs()
{
    for (int i = 1; i <= node; i++)
    {
        if (color[i] == w)
        {
            visit(i);
        }
    }
}

int main()
{
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs();
}