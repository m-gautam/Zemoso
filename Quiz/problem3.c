#include <stdio.h>
#include <stdlib.h>




void get_input(int arr[], int size);


typedef struct node
{
	int value;
	int count = 0;
	node *next = NULL;	
}
node;

node *list = NULL;


void ht_create(int n)
{
	hash_entry *cursor = hentry;
	hash_entry *new_entry = malloc(sizeof(hash_entry));
	new_entry->next = malloc(sizeof(hashtable));

	new_entry->next->key = n;
	new_entry->next->value = 1;

	if(hentry == NULL)
	{
		hentry = new_entry;
	}
}

int main(void)
{
	int size;
	scanf("%d", &size);

	int arr[size];

	get_input(arr, size);

	ht_create(arr[0]);

	//int ans = majority_element(arr, size);
}



void get_input(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
		node *nnode = list;
		nnode = malloc(sizeof(node));

		


		if (list == NULL)
		{
			nnode->value = arr[i];
			nnode->count += 1;
			list = nnode;
		}

		else
		{
			node *cursor = list;
			while(cursor != NULL)
			{
				if (cursor->value == arr[i])
				{
					cursor->count++;
					continue;
				}
			}

			nnode->value = arr[i];
			nnode->count += 1;
			cursor = nnode;

		}
	}
}


int majority_element(int arr[], int size)
{

	node *cursor = list;

	int max_count = 0;

	while (cursor != NULL)
	{
		cursor ->

	}


}