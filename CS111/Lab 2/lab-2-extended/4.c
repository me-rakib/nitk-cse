#include<stdio.h>
int main()
{
    int num, rev_num=0;
    printf("Enter number(five digit): ");
    scanf("%d", &num);
    if((num>4999) && (num<100000))
    {
        // let num = 12345
        int rem = num%10;  // 12345%10 = 5
        rev_num += rem*10000;        // 0+5*10000 = 50000
        rem = (num/10)%10; // (12345/10=1234)%10=4
        rev_num += rem*1000;        // 50000+4*1000 =54000
        rem = (num/100)%10; //(12345/100=123)%10=3
        rev_num += rem*100;         // 54000+3*100=54300
        rem = (num/1000)%10; // (12345/1000=12)%10=2
        rev_num += rem*10;          //54300+2*10 = 54320
        rem = (num/10000)%10; //(12345/10000=1)%10=1
        rev_num += rem*1;           // 54320+1*1=54321
        printf("\nReversed Number: %d\n", rev_num);
    }
    else
        printf("\nInvalid Input\n");
}
