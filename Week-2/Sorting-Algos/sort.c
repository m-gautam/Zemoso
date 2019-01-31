// Implemented  sorting  functions
 
// Author : Gautam Meena
// 31 January 2019
// Week : 2, Problem : 3


// Including the header files which contain sorting functions
#include <stdio.h>
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"


int main(void)
{
	int size;
	scanf("%d", &size);

	int arr[size];
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	// Insertion sort array output
	insertion_sort(arr, size);
	printf("Insertion sort: ");
	for (int i=0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}



	// Quick sort array output
	qsort(arr, 0, size-1);
	printf("\nQuick sort: ");
	for (int i=0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}



	// Merge sort array output
	merge_sort(arr, 0, size-1);
	printf("\nMerge sort: ");
	for (int i=0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}