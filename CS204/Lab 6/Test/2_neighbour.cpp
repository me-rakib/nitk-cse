#include<iostream>
using namespace std;
int main()
{
    int ver, edg, r, c, i, j, adjmat[50][50];
    cin >> ver >> edg;
    for(i=0; i<edg; i++)
    {
        cin >> r >> c;
        adjmat[r][c] = 1;
        adjmat[c][r] = 1;
    }
    for(i=0; i<ver; i++)
    {
        cout << i << " connected with -> ";
        for(j=0; j<ver; j++)
        {
            if(adjmat[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}