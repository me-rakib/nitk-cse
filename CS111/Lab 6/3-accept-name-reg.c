#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#define MAX_SIZE 100

//structure
typedef struct
{
    char name[MAX_SIZE];
    int reg_number;
    float marks[6];
} student_info;

//functions
void sort_name(int n, student_info student[]);
void sort_by_reg(int n, student_info student[]);
void search_by_reg_binary(int n, student_info student[]);
void avg_ascending(int n, student_info student[]);
void search_by_reg(int n, student_info student[]);
void sort_reg(int n, int temp[], student_info student[]);

int main()
{
    int n, i, j, option;
    printf("Total Student: ");
    scanf("%d", &n);
    student_info student[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter information of student %d:\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]%*c", student[i].name);
        printf("Enter register number: ");
        scanf("%d", &student[i].reg_number);
        printf("Enter number of 6 subjects: ");
        for (j = 0; j < 6; j++)
        {
            scanf("%f", &student[i].marks[j]);
        }
    }

    printf("\nMenu: \n");
    printf("1. Sort Based on name\n");
    printf("2. Sort based on register number.\n");
    printf("3. Accept a register number and search for this student using binary search\n");
    printf("4. Find the average marks for each student and sort them in ascending order of average marks\n");
    printf("5. Display the details of a student given his register number.\n");
    printf("Select option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        sort_name(n, student);
        break;
    case 2:
        sort_by_reg(n, student);
        break;
    case 3:
        search_by_reg_binary(n, student);
        break;
    case 4:
        avg_ascending(n, student);
        break;
    case 5:
        search_by_reg(n, student);
        break;
    default:
        printf("Wrong Input, program closed.");
        break;
    }
    return 0;
}

//sort based on name 
void sort_name(int n, student_info student[]) 
{
    int i, j;
    char temp[MAX_SIZE];
    char store_name[n][MAX_SIZE];
    for(i=0; i<n; i++)
    {
        store_name[i][MAX_SIZE] 
    }

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            
        }
    }
}

//sort regster number
void sort_reg(int n, int temp[], student_info student[])
{
    int i, j, t;
    for (i = 0; i < n; i++)
    {
        temp[i] = student[i].reg_number;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (temp[i] > temp[j])
            {
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
}

//sort based on register number
void sort_by_reg(int n, student_info student[])
{
    int i, j, k, temp[n];

    //sorting register number
    sort_reg(n, temp, student);
    for (i = 0; i < n; i++)
    {
        printf("\nRegister number %d:\n", temp[i]);
        for (j = 0; j < n; j++)
        {
            if (temp[i] == student[j].reg_number)
            {
                printf("Name: %s\n", student[j].name);
                printf("Marks: ");
                for (k = 0; k < 6; k++)
                {
                    printf("%.2f ", student[j].marks[k]);
                }
            }
            printf("\n");
        }
    }
}

// input register, search using binary
void search_by_reg_binary(int n, student_info student[])
{
    int reg, low, up, mid, i, j, temp[n];
    bool find = false;
    printf("\nEnter register number: ");
    scanf("%d", &reg);
    sort_reg(n, temp, student);
    low = 0;
    up = n-1;
    while(low<=up) 
    {
        mid = (low+up)/2;
        if(temp[mid] != reg) 
        {
            if(temp[mid] < reg)
            {
                low = mid+1;
            }
            else if (temp[mid] > reg) 
            {
                up = mid-1;
            }
        }
        else 
        {
            find = true;
            break;
        }
    }
    if(find) 
    {
        for(i=0; i<n; i++)
        {
            if(reg == student[i].reg_number) 
            {
                printf("\nRegister Number %d found:\n", student[i].reg_number);
                printf("Name: %s\n", student[i].name);
                printf("Marks: ");
                for(j=0; j<6; j++)
                {
                    printf("%.2f ", student[i].marks[j]);
                }
            }
        }
    }
    else 
    {
        printf("\nRegister Number %d Not Found", reg);
    }
}

//avg marks and sort ascending
void avg_ascending(int n, student_info student[])
{
    int i, j;
    float temp, avg[n];
    for (i = 0; i < n; i++)
    {
        temp = 0;
        for (j = 0; j < 6; j++)
        {
            temp += student[i].marks[j];
        }
        avg[i] = temp / 6;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (avg[i] > avg[j])
            {
                temp = avg[i];
                avg[i] = avg[j];
                avg[j] = temp;
            }
        }
    }
    printf("\nAverage marks in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%.2f ", avg[i]);
    }
}

// search by register number
void search_by_reg(int n, student_info student[])
{
    int reg, i, temp;
    bool find = false;
    printf("\nEnter Register Number: ");
    scanf("%d", &reg);
    for (i = 0; i < n; i++)
    {
        if (reg == student[i].reg_number)
        {
            find = true;
            temp = i;
            break;
        }
    }
    if (find)
    {
        printf("Details of %d:\n", reg);
        printf("Name: %s\n", student[temp].name);
        printf("Marks: ");
        for (i = 0; i < 6; i++)
        {
            printf("%.2f ", student[temp].marks[i]);
        }
    }
    else
    {
        printf("Student Not found");
    }
}