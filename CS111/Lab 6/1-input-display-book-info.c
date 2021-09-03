#include<stdio.h>
#define MAX_SIZE 100

typedef struct {
    char book_title[MAX_SIZE];
    char author[MAX_SIZE];
    int isbn;
    int price;
} book_info;

int main()
{
    int n, i;
    printf("How many books? > ");
    scanf("%d", &n);
    book_info book[n];
    for(i=0; i<n; i++)      //taking input
    {
        printf("\nEnter information for book %d: \n", i+1);
        printf("Enter title: ");
        scanf(" %[^\n]%*c", book[i].book_title);
        printf("Enter author name: ");
        scanf(" %[^\n]%*c", book[i].author);
        printf("Enter ISBN: ");
        scanf("%d", &book[i].isbn);
        printf("Enter price: ");
        scanf("%d", &book[i].price);
    }
    for(i=0; i<n; i++)      // printing information
    {
        printf("\n\nInformation of \"%s\":\n", book[i].book_title);
        printf("Author name: %s\n", book[i].author);
        printf("ISBN: %d\n", book[i].isbn);
        printf("Price: %d", book[i].price);
    }
    return 0;
}
