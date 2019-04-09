// Write a c function, which takes two integer arrays as arguments.
// From these two arrays find a pair of values (one from each array) that 
// you can swap to give the two arrays the same sum. Print these two values 
// separated by a comma to output on a new line. If no such pair exists print "Not Possible".
// (You could have more than one valid pair for given input, in such cases printing any one valid pair is acceptable)
// Example : Input : {4,1,2,1,1,2} and {3,6,3,3}
// 		     OutPut : {1,3}


// Author : Gautam Meena
// 15 March 2019
// Week : 2, Problem : 2


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

// Input array
void get_input(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
}


// Finds the required pair if present
void foo(int arr1[], int size1, int arr2[], int size2)
{
	int sum1 = 0, sum2 = 0;

	// Calculates the sum of elements of array
	for (int i = 0; i < size1; i++){
		sum1 += arr1[i];
	}

	for (int i = 0; i < size2; i++){
		sum2 += arr2[i];
	}


	// If pair is not possible
	if ((sum1 + sum2)%2 != 0)
	{
		printf("Not Possible");
		return;
	}

	int diff = (sum1 - (sum1 + sum2)/2);
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if ((arr1[i] - arr2[j]) == diff)
			{
				printf("%d,%d", arr1[i], arr2[j]);
				return;
			}
		}
	}

	printf("Not Possible");
}