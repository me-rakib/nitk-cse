#include <iostream>
using namespace std;
int main()
{
    int vertices, edges, adjmat[50][50];
    cin >> vertices >> edges;
    int r, c;
    for (int i = 0; i < edges; i++)
    {
        cin >> r >> c;
        adjmat[r][c] = 1;
        adjmat[c][r] = 1;
    }
    int i, j;
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}