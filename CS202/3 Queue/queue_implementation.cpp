#include <iostream>
#define MAX_SIZE 100
using namespace std;

class Queue
{
private:
    int A[MAX_SIZE];
    int rear, front;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool is_empty()
    {
        return (front == -1 && rear == -1);
    }

    bool is_full()
    {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    int Front()
    {
        if (is_empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return A[front];
    }

    void Enqueue(int x)
    {
        if (is_full())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (is_empty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        A[rear] = x;
    }

    void Dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is already empty" << endl;
            return;
        }
        else if (rear == front)
        {
            rear = front = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void Print()
    {
        int total, i, ind;
        total = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
        for (i = 0; i < total; i++)
        {
            ind = (front + i) % MAX_SIZE;
            cout << A[ind] << " ";
        }
        cout << " " << endl;
    }
};

int main()
{
    Queue Q;
    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.Enqueue(4);
    Q.Enqueue(5);
    Q.Dequeue();
    Q.Print();
    cout << Q.Front() << endl;
    return 0;
}