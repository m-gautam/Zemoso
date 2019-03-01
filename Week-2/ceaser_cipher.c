// Outputs the encrypted string
// Implemented ceaser cipher

// Author : Gautam Meena
// 29 January 2019
// Week : 2, Problem : 1



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// limit for the input string size
#define MAX_INPUT_LENGTH 50


// Helper Functions
int convert_key(char key[]);
int get_input(char message[]);

int main(int argc, char* argv[])
{
	if (argc!= 2)
	{
		return 1;
	}


	int key, s;
	key = convert_key(argv[1]);

	// If key is invalid
	if(key == -1)
	{
		return 1;
	}

	
	char message[MAX_INPUT_LENGTH];

	printf("plaintext: ");

	s = get_input(message);
	
	// If length of input is exceeded
	if(s == -1)
	{
		return 1; 
	}

	
	//printf("%s \n", message);
	// Encrypting the input	
	for (int i = 0; i < s; i++)
	{
		// If character is capital case
		if (message[i] >= 'A' && message[i] <= 'Z')
		{
			message[i] = 'A' + ((message[i]- 'A' + key)%26);
		}
		// If character is small case
		else if (message[i] >= 'a' && message[i] <= 'z')
		{
			message[i] = 'a' + ((message[i]- 'a' + key)%26);
		}
	}
	
	// Prints the cipher text
	printf("ciphertext: %s\n", message);

}


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

// Converting the argument into integer
int convert_key(char key[]){

	int k = 0;
	for (int i = 0; i < strlen(key); i++)
	{
		if(key[i] >= 48 && key[i] <= 57)
		{
			k =  k*10 + (key[i] - 48);
		}

		else
		{
			return -1;
		}
	}

	return k;
}