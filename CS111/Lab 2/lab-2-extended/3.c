#include<stdio.h>
int main()
{
    int num, sum=0;
    printf("Enter number(five digit): ");
    scanf("%d", &num);
    if((num>4999) && (num<100000))
    {
        // let num = 12345
        int rem = num%10;  // 12345%10 = 5
        sum += rem;        // 0+5 = 5
        rem = (num/10)%10; // (12345/10=1234)%10=4
        sum += rem;        // 5+4 = 9
        rem = (num/100)%10; //(12345/100=123)%10=3
        sum += rem;         // 9+3=12
        rem = (num/1000)%10; // (12345/1000=12)%10=2
        sum += rem;          //12+2 = 14
        rem = (num/10000)%10; //(12345/10000=1)%10=1
        sum += rem;           // 14+1=15
        printf("\nSum of digits: %d\n", sum);
    }
    else
        printf("\nInvalid Input\n");
}
