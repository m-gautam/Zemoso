// Implemented merge sort function




// Copy the value to other array
void copy_array(int temp_array[], int A[], int start, int end)
{
	for (int i = start; i <= end; ++i)
	{
		A[i] = temp_array[i];
	}
}



// Merges the array in sorted order
void merge_array(int A[], int start, int end)
{
	int mid = (start+end)/2;
	int temp_array[50];

	int i = start;
	int j = mid+1;
	int k = start; 
	while (i <= mid && j <= end)
	{
		if (A[i] > A[j])
		{
			temp_array[k] = A[j];
			j++;
		}
		else
		{
			temp_array[k] = A[i];
			i++;
		}
		k++;
	}

	while (i <= mid)
	{
		temp_array[k] = A[i];
		i++;	
		k++;
	}

	while (j <= end)
	{
		temp_array[k] = A[j];
		j++;
		k++;
	}


	copy_array(temp_array, A, start, end);
	return;
}






// Divides he array into two parts and calls the merge function
void merge_sort(int A[], int start, int end)
{

	if (start >= end)
	{
		return;
	}

	int mid = (start + end)/2;

	merge_sort(A, start, mid);
	merge_sort(A, mid+1, end);

	merge_array(A, start, end);
}


