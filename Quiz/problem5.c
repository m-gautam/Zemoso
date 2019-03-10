#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int size1, size2;
	scanf("%d %d", &size1, &size2);

	int arr1[size1];
	int arr2[size2];

	get_input(arr1, size1);
	get_input(arr2, size2);

	void sub_array(arr1, size1, arr2, size2);

}


void get_input(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
}


void sub_array(int arr1[], int size1, int arr2[], int size2)
{

	}