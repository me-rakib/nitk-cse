#include<stdio.h>
int binary(int target, int lb, int ub, int arr[]);
int main()
{
    int arr[50] = {1,2,3,4,5,6,7,8,9,10,20};
    int res = binary(20, 0, 10, arr);
    if(res != 0) 
    {
        printf("Found in position %d", res+1);
    }
    else 
    {
        printf("Not found");
    }
    return 0;
}

int binary(int target, int lb, int ub, int arr[]) {
    int mid = (lb+ub)/2;
    if(arr[mid] == target) 
    {
        return lb;
    }
    else if(lb>ub) 
    {
        return 0;
    }
    else
    {
        if(arr[mid] <target) 
        {
            binary(target, mid+1, ub, arr);
        }
        else
        {
            binary(target, lb, mid-1, arr);
        }
    }
}