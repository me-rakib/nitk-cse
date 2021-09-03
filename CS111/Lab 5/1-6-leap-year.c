#include <stdio.h>
void check_year(int year);
int main()
{
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
    check_year(year);
    return 0;
}

void check_year(int year)  // function
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        printf("\nLeap Year\n");
    }
    else
    {
        printf("\nNot Leap year\n");
    }
}