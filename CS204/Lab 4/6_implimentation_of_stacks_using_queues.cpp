#include <iostream>
#include <queue>

using namespace std;

class Stack
{
private:
    queue<int> q1, q2;

public:
    void push(int data)
    {
        q2.push(data);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
    }
    void print()
    {
        int total = q1.size();
        for (int i = 0; i < total; i++)
        {
            printf("%d ", q1.front());
            q1.pop();
        }
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.pop();
    s.push(14);
    s.push(15);
    s.pop();
    s.print();
    return 0;
}