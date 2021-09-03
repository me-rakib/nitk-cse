#include <stdio.h>

// structures
typedef struct
{
    double inch;
    double feet;
} distance;

typedef struct
{
    double real;
    double imaginary;
} complex;

typedef struct
{
    int sec;
    int min;
    int hour;
} time;

// functions
void add_two_distance();
void add_two_complex_number();
void add_com(complex com[]);
void difference_between_two_time();
int time_dif(time time[]);

int main()
{
    int n;
    printf("Menu: \n");
    printf("1. Add two distances(in inch-feet) using structure.\n");
    printf("2. Add two complex number by passing structure to a function.\n");
    printf("3. Calculate the difference between two time periods using structures.\n");
    printf("Select Option: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        add_two_distance();
        break;
    case 2:
        add_two_complex_number();
        break;
    case 3:
        difference_between_two_time();
        break;
    default:
        printf("Wrong Input, Program closed");
    }
    return 0;
}

//function to calculate distance
void add_two_distance()
{
    int i;
    double result = 0;
    distance dist[2];
    for (i = 0; i < 2; i++)
    {
        printf("\nEnter inch for distance %d: ", i + 1);
        scanf("%lf", &dist[i].inch);
        printf("Enter feet for distance %d: ", i + 1);
        scanf("%lf", &dist[i].feet);
    }
    for (i = 0; i < 2; i++)
    {
        result += (dist[i].inch + (dist[i].feet * 12));
    }
    printf("\nTotal Distance = %.2lf inch\n", result);
}

//function for addition of complex number
void add_two_complex_number()
{
    int i;
    complex com[2];
    for (i = 0; i < 2; i++)
    {
        printf("\nEnter Information for complex %d:\n", i + 1);
        printf("Real part: ");
        scanf("%lf", &com[i].real);
        printf("Imaginary part: ");
        scanf("%lf", &com[i].imaginary);
    }
    add_com(com);
}

//complex addition
void add_com(complex com[])
{
    int i;
    double real = 0, ima = 0;
    for (i = 0; i < 2; i++)
    {
        real += com[i].real;
        ima += com[i].imaginary;
    }
    printf("\nAddition = %.2lf + %.2lfi\n", real, ima);
}

//difference between two time
void difference_between_two_time()
{
    int i, sec_dif, h, m, s;
    time t[2];
    for (i = 0; i < 2; i++)
    {
        printf("\nEnter information for time %d:\n", i + 1);
        printf("Enter Hour: ");
        scanf("%d", &t[i].hour);
        printf("Enter Minute: ");
        scanf("%d", &t[i].min);
        printf("Enter Second: ");
        scanf("%d", &t[i].sec);
    }
    sec_dif = time_dif(t);
    h = sec_dif / 3600;
    m = (sec_dif % 3600) / 60;
    s = (sec_dif % 3600) % 60;
    printf("\nDifference is %d hours %d minutes %d seconds\n", h, m, s);
}

//time difference calculation
int time_dif(time time[])
{
    int t1, t2, dif;
    t1 = (time[0].hour * 3600) + (time[0].min * 60) + time[0].sec;
    t2 = (time[1].hour * 3600) + (time[1].min * 60) + time[1].sec;
    dif = t1 >= t2 ? (t1 - t2) : (t2 - t1);
    return dif;
}
