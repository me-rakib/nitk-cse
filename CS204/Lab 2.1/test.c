// // #include<stdio.h>
// // int main()
// // {
// //     int i=0;
// //     for(i=0; i<=20; i++)
// //     {
// //         switch(i)
// //         {
// //             case 0:
// //                 i+=5;
// //                 printf("\n%d \n",i);
// //             case 1:
// //                 i+=2;
// //                 printf("\n%d \n",i);
// //             case 2:
// //                 i+=5;
// //                 printf("\n%d \n",i);
// //             default:
// //                 i+=4;
// //                 printf("\n%d \n",i);
// //                 break;
// //         }
// //         printf("\nA = %d",i);
// //     }
// //     printf("\nx = %d", i);
// // }

// #include <stdio.h>
// int main()
// {
//     int i = 0;
//     for (i = 0; i <= 20; i++)
//     {
//         switch (i)
//         {
//         case 0:
//             i += 5;  // i = 0 + 5  
//         case 1:
//             i += 2;  // i = 5 + 2
//         case 2:
//             i += 5;  // i = 5 + 2 + 5
//         default:
//             i += 4;  // i = 5 + 2 + 5 + 4
//             break;
//         }
//         printf("i=%d", i);  // i = 16 
//     }
// }

// /*
// when initial value of i was 0, printf will print 16.
// Check the above comment. Every switch case should be 
// end using break, otherwise it will also exicute cases below of
// that if condition met.

// After the first itaration value of i is 17 (cz after evey itaration
// it will increase by 1) which is less than 20,
// this time case 0, case 1, case 2 none of these are true as i = 17,
// so only default will exicute so value of i will be 17+4 = 21. 

// So ans is i = 16 and i=21
// */



#include <stdio.h>
#include <stdlib.h>
int condition(int *arr,int r,int c,int n)
{
    int i,j;
    if(c==n)
    {
        return 2;
    }
    else if(r<n)
    {
        for(i=0;i<r;i++)
        {
            j=arr[i];        
            if(((i+j)==(r+c))||(i==r)||(j==c)||((i-j)==(r-c)))
            {
                return 0;
            }
        }
        if(i==r)
        {
            return 1;
        }
    }
    else
    {
        return -1;
    }       
}
void move(int *arr,int row,int n,int strt)
{
    int col=strt;
    int temp=condition(arr,row,col,n);
    if(temp==1)
    {
        arr[row]=col;
        move(arr,row+1,n,0);
    }
    else if(temp==0)
    {
        arr[row]=col+1;
        move(arr,row,n,arr[row]);
    }
    else if(temp==2)
    {
        arr[row]=0;
        move(arr,row-1,n,arr[row-1]);
    }
    else
    {
        return;
    }

}
int main()
{
    int n=4,i,j;
    int chess_board[n];
    move(chess_board,0,n,0);
    for(i=0;i<n;i++)
    {
        printf("%d ",chess_board[i]);
    }
}