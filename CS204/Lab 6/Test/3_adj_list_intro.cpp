#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v[5];
    v[0].push_back(0);
    v[0].push_back(1);
    v[0].push_back(3);

    v[1].push_back(3);
    v[1].push_back(3);
    v[1].push_back(3);

    for (int i = 0; i < v[0].size(); i++)
    {
        cout << v[0][i] << " ";
    }
    return 0;
}