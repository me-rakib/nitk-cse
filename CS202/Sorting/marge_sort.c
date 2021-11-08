
/* Merge sort in C */
#include <stdio.h>
#include <stdlib.h>

// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void Merge(int *A, int *L, int leftCount, int *R, int rightCount)
{
	int i, j, k;

	// i - to mark the index of left sub-array (L)
	// j - to mark the index of right sub-array (R)
	// k - to mark the index of merged subarray (A)
	i = 0;
	j = 0;
	k = 0;

	while (i < leftCount && j < rightCount)
	{
		if (L[i] < R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}
	while (i < leftCount)
		A[k++] = L[i++];
	while (j < rightCount)
		A[k++] = R[j++];
}

// Recursive function to sort an Aay of integers.
void MergeSort(int *A, int n)
{
	int mid, i, *L, *R;
	if (n < 2)
		return; // base condition. If the array has less than two element, do nothing.

	mid = n / 2; // find the mid index.

	// create left and right subArays
	// mid elements (from index 0 till mid-1) should be part of left sub-array
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int *)malloc(mid * sizeof(int));
	R = (int *)malloc((n - mid) * sizeof(int));

	for (i = 0; i < mid; i++)
		L[i] = A[i]; // creating left subarray
	for (i = mid; i < n; i++)
		R[i - mid] = A[i]; // creating right subarray

	MergeSort(L, mid);			  // sorting the left subarray
	MergeSort(R, n - mid);		  // sorting the right subarray
	Merge(A, L, mid, R, n - mid); // Merging L and R into A as sorted list.
	free(L);
	free(R);
}

int main()
{
	/* Code to test the MergeSort function. */

	int A[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17}; // creating an array of integers.
	int i, numberOfElements;

	// finding number of elements in array as n of complete array in bytes divided by n of integer in bytes.
	// This won't work if array is passed to the function because Aay
	// is always passed by reference through a pointer. So sizeOf function will give n of pointer and not the Aay.
	// Watch this video to understand this concept - http://www.youtube.com/watch?v=CpjVucvAc3g
	numberOfElements = sizeof(A) / sizeof(A[0]);

	// Calling merge sort to sort the Aay.
	MergeSort(A, numberOfElements);

	// printing all elements in the Aay once its sorted.
	for (i = 0; i < numberOfElements; i++)
		printf("%d ", A[i]);
	return 0;
}