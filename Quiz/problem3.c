// A 'majority element' is an element that makes up half or more than half of the items in an array.
// Write a C function which takes a positive integer array as argument and returns the majority element.
// If there is no majority element return -1. Do this in O(N) time complexity and O(1) space complexity. 
// Example : Input : {1,2,5,9,5,9,5,5,5}
// OutPut : 5


// Author : Gautam Meena
// 15 March 2019
// Week : 2, Problem : 2

#include <stdio.h>
#include <stdlib.h>

// Helper functions
int majority_index(int arr[], int size);
int maj_element(int arr[], int size, int a);


int main()
{
	int size;
	scanf("%d", &size);

	int arr[size];
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	int index = majority_index(arr, size);
	int ans = maj_element(arr, size, index);
	printf("%d\n", ans);
}


// Finding candidates for majority elements
int majority_index(int arr[], int size)
{
	int maj_index = 0, count = 1;

	for (int i = 1; i < size-1; i++)
	{
		if(arr[maj_index] ==  arr[i])
		{
			count++;
		}
		else
		{
			count--;
		}

		if (count == 0)
		{
			maj_index = i;
			count = 1;
		}
	}

	return arr[maj_index];
}

// Finding majority elements 
int maj_element(int arr[], int size, int a)
{
	int b = arr[size-1];
	int count1 = 0, count2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == a)
		{
			count1++;
		}

		else if (arr[i] == b)
		{
			count2++;
		}

	}

	if (2*count1 >= size)
	{
		return a;
	}

	else if (2*count2 >= size)
	{
		return b;
	}

	else
	{
		return -1;
	}
}
