#include<stdio.h>
int main()
{
    int lower, upper, i, j, k=0, z=0, len, num, prime_num;
    printf("Enter the lower and upper bound: ");
    scanf("%d %d", &lower, &upper);
    len = (upper - lower)-1;          //total number between upper and lower 
    int prime[len], not_prime[len];
    num = lower+1;
    for(i=0; i<len; i++) 
    {
        if(num<2)
        {
            num = 2;       //lowest prime number is 2
            continue;
        }
        prime_num = 1;      //prime number? 1 means yes
        for(j=2; j<num; j++) 
        {
            if(num % j == 0) 
            {   
                prime_num = 0;   // prime number? 0 means false 
                break;
            }
        }
        if(prime_num == 0) 
        {
            not_prime[z] = num;  // storing non-prime in an array
            z++;
        }
        else 
        {
            prime[k] = num;   //storing prime in an array
            k++;
        }
        num++;
    }
    printf("Prime = ");
    for(i=0; i<k; i++) 
    {
        printf("%d ",prime[i]);
    }
    printf("\nNot prime = ");
    for(i=0; i<z; i++) 
    {
        printf("%d ",not_prime[i]);
    } 
    return 0;
}