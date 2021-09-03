

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char first_name[20];
    char last_name[20];
    int student_num;
    char debts[1];

    printf("Enter name:");
    scanf("%s", first_name);
    printf("Enter lastname:");
    scanf("%s", last_name);
    printf("Enter six bits length student ID:");
    scanf("%d", &student_num);
    printf("Do you have debts for university [Y/N]?");
    scanf("%s", debts);

    printf("\nYour name is %s %s.\n", first_name, last_name);
    printf("Your Student ID is %d.\n", student_num);
    printf("Debts: %s.\n", debts);
    return (EXIT_SUCCESS);
}
