#include<iostream>
using namespace std;
int main()
{
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);

    int M, N, i, j, **arr;
    cin >> M;
    cin >> N;

    // dynamically allocating memory
    arr = (int **) calloc(M, sizeof(int *));
    for(i=0; i<M; i++) 
    {
        *(arr+i) = (int *) calloc(N, sizeof(int));
    }

    //taling input
    for(j=1; j<N; j++) 
    {
        scanf("%d", *(arr+0)+j);
    }
    for(i=1; i<M; i++) 
    {
        scanf("%d", *(arr+i)+0);
    }

    //calculating
    for(i=1; i<M; i++)
    {
        for(j=1; j<N; j++) 
        {
            *(*(arr+i)+j) = *(*(arr+i)+0) + *(*(arr+0)+j);
        }
    }

    //printing
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++) 
        {
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
    free(arr);
    return 0;
}