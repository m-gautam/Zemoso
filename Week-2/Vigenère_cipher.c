// Outputs the encrypted string
// Implemented ceaser cipher

// Author : Gautam Meena
// 29 January 2019
// Week : 2, Problem : 1



#include <stdio.h>
#include <string.h>

// limit for the input string size
#define MAX_INPUT_LENGTH 50

int main(void)
{
	int key;

	char message[MAX_INPUT_LENGTH];
	printf("message: ");
	scanf("%s",message);

	// Encrypting the input
	
	for (int i = 0, s = strlen(message); i < s; i++)
	{
		// If character is capital case
		if (message[i] >= 'A' && message[i] <= 'Z')
		{
			key = message[i] - 'A';
			message[i] = 'A' + ((message[i]- 'A' + key)%26);
		}
		// If character is small case
		else if (message[i] >= 'a' && message[i] <= 'z')
		{
			key = message[i] - 'a';
			message[i] = 'a' + ((message[i]- 'a' + key)%26);
		}
	}
	
	printf("%s\n", message);

}