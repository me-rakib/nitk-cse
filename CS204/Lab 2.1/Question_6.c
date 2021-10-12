#include<stdio.h>
void toh(int n, char src, char aux, char dest);

int main()
{
    //redirecting input and output
    freopen("input_6.txt", "r", stdin);
    freopen("output_6.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    printf("Steps: \n\n");
    toh(n, 'A', 'B', 'C');
    return 0;
}

//recursive function to print the steps
void toh(int n, char src, char aux, char dest) 
{
    if(n>0) 
    {
        toh(n-1, src, dest, aux);
        printf("%c -> %c\n", src,dest);
        toh(n-1, aux, src, dest);
    } 
}