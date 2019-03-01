// Outputs the encrypted string
// Implemented ceaser cipher

// Author : Gautam Meena
// 29 January 2019
// Week : 2, Problem : 2



#include <stdio.h>
#include <string.h>

// limit for the input string size
#define MAX_INPUT_LENGTH 50


// Helper functions
int get_key(char k[], int j, int key[]);
int get_input(char message[]);

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		return 1;
	}

	int size = strlen(argv[1]);
	int key[size]; 

	int res = get_key(argv[1], size, key);

	if(res == -1)
	{
		return 1;
	}

	printf("%s", argv[1]);

	char message[MAX_INPUT_LENGTH];
	printf("plaintext: ");
	int s = get_input(message);
	
	// If length of input is exceeded
	if(s == -1)
	{
		return 1; 
	}

	// Encrypting the input
	
	int j = 0;
	for (int i = 0, s = strlen(message); i < s; i++)
	{

		if (j > size)
		{
			j = 0;
		}

		// If character is capital case
		if (message[i] >= 'A' && message[i] <= 'Z')
		{	
			message[i] = 'A' + ((message[i]- 'A' + key[j])%26);
			j++;
		}
		// If character is small case
		else if (message[i] >= 'a' && message[i] <= 'z')
		{
			message[i] = 'a' + ((message[i]- 'a' + key[j])%26);
			j++;
		}
	}
	
	printf("ciphertext: %s", message);

}

// Storing key into an integer array
int get_key(char argv[], int size, int key[])
{

	for (int i = 0; i < size; i++)
	{
		char k = argv[i];
		if ( k >= 'A' && k <= 'Z')
		{
			key[i] = k - 'A';
		}

		else if ( k >= 'a' && k <= 'z')
		{
			key[i] = k - 'A';
		}

		else
		{
			return -1;
		}
	}

	return 0;

}

// Getting input function
int get_input(char message[MAX_INPUT_LENGTH]){

	int len = -1;
	do
	{
		len++;
		scanf("%c", &message[len]);

		if(len > MAX_INPUT_LENGTH)
		{
			printf("Don't exceed the size of input string\n");
			return -1;
		}
	}while(message[len] != '\n');
	message[len] = '\0';

	return len;
}