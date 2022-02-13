#include<iostream>
using namespace std;

void down(int *x)
{
    if ((*x) > 0)
    {
        (*x)--;
    }
}

void up(int *x)
{
    (*x)++;
}

int main()
{
    int buffer[3], empty = 3, full = 0, semaphore_s = 1, choice;
    while (1)
    {
        printf("\nempty- %d full- %d semaphore- %d \n", empty, full, semaphore_s);
        printf("Enter 1- produce product, 2-consume product ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            if (empty != 0 && semaphore_s == 1)
            {
                down(&empty);
                down(&semaphore_s);
                printf("Enter product value ");
                cin >> buffer[full];
                up(&semaphore_s);
                up(&full);
            }
            else
            {
                printf("Buffer is full\n");
            }
        }
        else if (choice == 2)
        {
            if (full > 0 && semaphore_s == 1)
            {
                down(&full);
                down(&semaphore_s);
                printf("Consumed product value is %d\n", buffer[full]);
                up(&semaphore_s);
                up(&empty);
            }
            else
            {
                printf("Buffer is empty\n");
            }
        }
        else
            break;
    }

    return 0;
}