// Implemented insertion sort function



// Sort the given array using insertion sort
void insertion_sort(int arr[], int size)
{
	int i = 0;
	while (i<size)
	{
		int x = arr[i];
		int j = i;
		while (j > 0 && x < arr[j-1])
		{
				arr[j] = arr[j-1];
				j--;
		}

		arr[j] = x;
		i++;
	}

}
