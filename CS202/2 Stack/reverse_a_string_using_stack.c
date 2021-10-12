#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

void push(char *ch, char c, int *top)
{
    int x = ++(*top);
    *(ch+x) = c;
}

char Top(char *ch, int top)
{
    return *(ch+top);
}

void pop(int *top)
{
    (*top)--;
}

int main()
{
    int top = -1, i, len;
    char ch1[MAX_SIZE], ch2[MAX_SIZE], ch3[MAX_SIZE];
    printf("Enter string: ");
    fgets(ch1, MAX_SIZE, stdin);
    ch1[strcspn(ch1, "\n")] = 0;
    len = strlen(ch1);
    for(i=0; i<len; i++)
    {
        push(ch2, ch1[i], &top);
    }
    for(i=0; i<len; i++)
    {
        ch3[i] = Top(ch2, top);
        pop(&top);
    }
    for(i=0; i<len; i++)
    {
        printf("%c ", ch3[i]);
    }
}

