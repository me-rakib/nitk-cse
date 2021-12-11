#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v[10];
    int vertex, edge;
    cin >> vertex >> edge;
    int i;
    for(i=0; i<edge; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(i=0; i<edge; i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}