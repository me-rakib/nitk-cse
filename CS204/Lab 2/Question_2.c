#include<stdio.h>
#include<stdlib.h>
int main()
{
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);
    int n, i, *arr, temp, len;
    scanf("%d", &n);  //total element
    
    //dynamically allocation memory
    arr = (int *)malloc(n * sizeof(int)); 
    for(i=0; i<n; i++) 
    {
        // taking array element
        scanf("%d", (arr+i));
    }
    len = n/2;

    //reversing
    for(i=0; i<len; i++) 
    {
        temp = *(arr+i);
        *(arr+i) = *(arr+n-1-i);
        *(arr+n-1-i) = temp;
    }

    // printing
    printf("Reversed array: ");
    for(i=0; i<n; i++) 
    {
        printf("%d ", *(arr+i));
    }
    return 0;
}