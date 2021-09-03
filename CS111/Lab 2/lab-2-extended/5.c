#include<stdio.h>
int main()
{
    float total_price, profit;
    printf("Total selling price(15 items) & profit: ");
    scanf("%f %f",&total_price, &profit);
    float actual_cost, per_piece_price;

    //calculation
    actual_cost = total_price - profit;
    per_piece_price = actual_cost/15;

    printf("\nThe cost price of one item: %.2f\n",per_piece_price);
    return 0;
}
