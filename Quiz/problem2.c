#include <stdio.h>
#include <stdlib.h>


// Helper functions
void get_input(int arr[], int size);
void foo(int a[], int s1, int b[], int s2);


int main(void)
{
	int size1, size2;

	scanf("%d %d", &size1, &size2);

	int arr1[size1], arr2[size2];

	get_input(arr1, size1);
	get_input(arr2, size2);

	foo(arr1, size1, arr2, size2);

}


void get_input(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
}


void foo(int arr1[], int size1, int arr2[], int size2)
{
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < size1; i++){
		sum1 += arr1[i];
	}

	for (int i = 0; i < size2; i++){
		sum2 += arr2[i];
	}

	if ((sum1 + sum2)%2 != 0)
	{
		printf("Not Possible");
		return;
	}

	int diff = abs(sum1 - (sum1 + sum2)/2);
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (abs(arr1[i] - arr2[j]) == diff)
			{
				printf("%d,%d", arr1[i], arr2[j]);
				return;
			}
		}
	}

	printf("Not Possible");
}