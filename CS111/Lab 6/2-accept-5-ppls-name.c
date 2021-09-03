#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct //structure
{
    char name[MAX_SIZE];
    char address[MAX_SIZE];
    int tel_num;
} person_info;

//functions
void search(char name[], person_info person[]);
void search_tel(int n, person_info person[]);
void show_info(int n, person_info person[]);

int main()
{
    person_info person[5];
    int i, n, tel;
    char name[MAX_SIZE];
    for (i = 0; i < 5; i++)
    {
        printf("\nEnter Information for person %d:\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]%*c", &person[i].name);
        printf("Enter address: ");
        scanf(" %[^\n]%*c", &person[i].address);
        printf("Entre telephone number: ");
        scanf("%d", &person[i].tel_num);
    }
    printf("\nSearch Menu: \n");
    printf("1. Based on name.\n");
    printf("2. Based on telephone number\n");
    printf("Select menu: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Enter name: ");
        scanf(" %[^\n]%*c", name);
        search(name, person);
        break;
    case 2:
        printf("Enter telephone number: ");
        scanf("%d", &tel);
        search_tel(tel, person);
        break;
    default:
        printf("Wrong Input. Program closed");
        break;
    }
    return 0;
}

//search by name
void search(char name[], person_info person[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(name, person[i].name) == 0)
        {
            break;
        }
    }
    show_info(i, person);
}

//search by telephone number
void search_tel(int n, person_info person[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (n == person[i].tel_num)
        {
            break;
        }
    }
    show_info(i, person);
}

//show result
void show_info(int i, person_info person[])
{
    if (i >= 5)
    {
        printf("\nNOT FOUND");
    }
    else
    {
        printf("\nInformation of \"%s\": \n", person[i].name);
        printf("Address: %s\n", person[i].address);
        printf("Telephone Number: %d", person[i].tel_num);
    }
}