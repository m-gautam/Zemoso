// Implemented quick sort function
 


// Swap the values in array
void swap(int arr[], int a, int b)
{
	int x = arr[a];
	arr[a] = arr[b];
	arr[b] = x;
}




// sort the elements according to pivot
int partition(int A[], int start, int end)
{
	int pivot = A[(start+end)/2];

	int i = start;
	int j = end;

	while (1)
	{
		while (A[i] < pivot)
		{
			i++;
		}

		while (A[j] > pivot)
		{ 
			j--;
		}

		if (i >= j)
		{
			return j;
		}

		swap(A, i, j);
	}

}




// divides the array and calls partition function
void qsort(int arr[], int start, int end)
{
	if (start < end)
	{
		int pindex = partition(arr, start, end);
		qsort(arr, start, pindex -1);
		qsort(arr, pindex + 1, end);
	}
}






