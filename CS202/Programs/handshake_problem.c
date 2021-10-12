#include <stdio.h>
int handshake(int n);
int main()
{
    int n;
    printf("Total people: ");
    scanf("%d", &n);
    printf("Total Handshake: %d", handshake(n));
    return 0;
}

int handshake(int n)
{
    if (n < 2)
    {
        return 0;
    }
    else
    {
        return (n-1) + handshake(n - 1);
    }
}