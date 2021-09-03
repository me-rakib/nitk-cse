#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
    int item_num;
    char item_name[MAX_SIZE];
    int unit_price;
    int quantity;
} items;

//functions
void list_by_unit_price(int n, items item[]);
void list_by_quantity(int n, items item[]);

int main()
{
    int n, i, option;
    printf("Total Items: ");
    scanf("%d", &n);
    items item[n];
    for (i = 0; i < n; i++)
    {
        printf("\nInformation of Item %d: \n", i + 1);
        printf("Enter Item Number: ");
        scanf("%d", &item[i].item_num);
        printf("Enter Item Name: ");
        scanf(" %[^\n]%*c", item[i].item_name);
        printf("Enter Unit Price: ");
        scanf("%d", &item[i].unit_price);
        printf("Enter Quantity: ");
        scanf("%d", &item[i].quantity);
    }
    printf("\nMenu for selecting list of items: \n");   //selecting menu
    printf("1. With unit price greater than Rs129\n");
    printf("2. With quantity in stock less than 5\n");
    printf("Select Option: ");
    scanf("%d", &option);
    printf("\n\n");
    switch (option)
    {
    case 1:
        list_by_unit_price(n, item);
        break;
    case 2:
        list_by_quantity(n, item);
        break;
    default:
        printf("Wrong Input. Program Closed");
        break;
    }
    return 0;
}

//function for getting list item with unit price > Rs 129
void list_by_unit_price(int n, items item[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (item[i].unit_price > 129)
        {
            printf("%s\n", item[i].item_name);
        }
    }
}

//function for getting list item with quantity < 5
void list_by_quantity(int n, items item[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (item[i].quantity < 5)
        {
            printf("%s\n", item[i].item_name);
        }
    }
}
