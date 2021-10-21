#include <stdio.h>
#include <stdlib.h>

void marge_sort(int *arr, int total_element);
void marge(int *arr, int *L, int left_count, int *R, int right_count);

int main()
{
	int arr[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17};
	int total_element = sizeof(arr) / sizeof(arr[0]);

	marge_sort(arr, total_element);

	int i;
	for (i = 0; i < total_element; i++)
	{
		printf("%d ", *(arr + i));
	}
}

void marge_sort(int *arr, int total_element)
{
	if (total_element < 2)
	{
		return;
	}
	int i, mid, *L, *R;
	mid = total_element / 2;
	L = (int *)malloc(mid * sizeof(int));
	R = (int *)malloc((total_element - mid) * sizeof(int));
	for (i = 0; i < mid; i++)
	{
		L[i] = arr[i];
	}
	for (i = mid; i < total_element; i++)
	{
		R[i - mid] = arr[i];
	}
	marge_sort(L, mid);
	marge_sort(R, total_element - mid);
	marge(arr, L, mid, R, total_element - mid);
	free(L);
	free(R);
}

void marge(int *arr, int *L, int left_count, int *R, int right_count)
{
	int i = 0, j = 0, k = 0;
	while (i < left_count && j < right_count)
	{
		if (L[i] > R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	}
	while (i < left_count)
	{
		arr[k++] = L[i++];
	}
	while (j < right_count)
	{
		arr[k++] = R[j++];
	}
}