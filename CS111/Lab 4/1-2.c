#include<stdio.h>
int main() 
{
    int n, i, temp, rem, rev, count=0;
    printf("Total number in list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the numbers: ");
    for(i=0; i<n; i++) 
    {
        scanf("%d", (arr+i));
        //palindromes check
        temp = *(arr+i);
        rev = 0;
        while(temp != 0) 
        {
            rem = temp % 10;
            rev = (rev*10) + rem;  //reversed number
            temp /= 10;
        }
        if((*(arr+i) == rev) || *(arr+i) == 0)
        {
            count++;
        }
    }
    printf("Total palindrome = %d", count);
    return 0;
}