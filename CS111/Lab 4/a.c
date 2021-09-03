#include <stdio.h>
int main()
{
int n,temp, product=1 , sum=0 ;
scanf("%d",&n);
temp=n;
while (temp!=0) {
    int d = temp % 10;
    temp /= 10;
    if (d>0 && n%d==0) 
{
            sum+=d;
            product *= d;
        }
    }
    printf("Sum = %d ",sum);
    printf("Product = %d",product);
    return 0;
}