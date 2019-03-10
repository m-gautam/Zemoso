#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



char *unit_place[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *two_digits[] = { "ten", "eleven", "tweleve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char  *tenth_place[] = { "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *tenth_power[] = { "hundred", "thousand", "million", "billion", "trillion"};

// Helper functions
void convert_to_words(long long int, int);
void one_digit(int);
void two_digit(int);
void ten_power(long long int);
int length(int);


int main(int argc, char *argv[])
{
	if (argc != 2)
    {
        printf("Usage: output_file no. \n");
        return 1;
    }

    if (!isdigit(argv[1][0]))
    {
    	printf("Enter valid number \n");
    	return 2;
    }

    int no_len = strlen(argv[1]);
    long long int n;
    sscanf(argv[1], "%lld", &n); 

    printf("%lld\n", n);

   convert_to_words(n, no_len);
    return 0;
}



void convert_to_words(long long int n, int len)
{
	if (len == 1)
	{
		one_digit(n);
	}


	else if (len == 2)
	{
		two_digit(n);
	}

	else if (len >= 3)
	{
		printf("%d\n",len);
		ten_power(n);

	}
}



void one_digit(int n)
{
	printf("%s ",unit_place[n-1]);
	return;
}




void two_digit(int n)
{
	int div, mod;

	if (n < 20)
	{
		mod = n%10;
		printf("%s ", two_digits[mod]);
		
		return;
	}

	else
	{
		div = n/10;
		mod = n%10;
		printf("%s ", tenth_place[div - 2]);

		if (mod != 0)
		{
			printf("%s ", unit_place[mod-1]);
		}
	}
}




void ten_power(long long int n)
{	
	printf("kjckK\n");
	long long int div, mod;
	long long int len = length(n);
	if (len == 3)
	{
		div = n/100;
		mod = n%100;
		//printf("%d\n", len);
		one_digit(div);
		printf("%s ", tenth_power[0]);

		if (mod == 0)
		{
			return;
		}

		printf("and ");

		if (length(mod) == 1)
		{
			one_digit(mod);
		}

		else if (length(mod) == 2)
		{
			two_digit(mod);	
		}

		return;
	}

	else if (len <= 6)
	{
		div = n/1000;
		mod = n%1000;

		if (length(div) == 1)
		{
			one_digit(div);

			printf("%s ", tenth_power[1]);
		}

		else if (length(div) == 2)
		{
			two_digit(div);

			printf("%s ", tenth_power[1]);
		}


		else if (length(div) == 3)
		{

			ten_power(div);
			printf("%s ", tenth_power[1]);
			
		}


		if (mod == 0)
		{
			return;
		}

		printf("and ");
		if (length(mod) == 1)
		{
			one_digit(mod);
		}

		else if (length(mod) == 2)
		{
			two_digit(mod);
		}

		else
		{
			ten_power(mod);

		}

	}

	else if (len > 6 && len < 10)
	{
		div = n/1000000;
		mod = n%1000000;

		if (length(div) == 1)
		{
			one_digit(div);

			printf("%s ", tenth_power[2]);
		}

		else if (length(div) == 2)
		{
			two_digit(div);

			printf("%s ", tenth_power[2]);
		}


		else if (length(div) == 3)
		{

			ten_power(div);
			printf("%s ", tenth_power[2]);
			
		}


		if (mod == 0)
		{
			return;
		}

		if (length(mod) == 1)
		{
			one_digit(mod);
		}

		else if (length(mod) == 2)
		{
			two_digit(mod);
		}

		else
		{
			ten_power(mod);

		}


	}

	else if (len >= 10)
	{
		printf("CSadeac\n");
		long long int f = 1000000000;
		div = n/f;
		mod = n%f;
		printf("%lld\n", div);
		if (length(div) == 1)
		{
			one_digit(div);

			printf("%s ", tenth_power[3]);
		}

		else if (length(div) == 2)
		{
			two_digit(div);

			printf("%s ", tenth_power[3]);
		}


		else if (length(div) == 3)
		{

			ten_power(div);
			printf("%s ", tenth_power[3]);
			
		}


		if (mod == 0)
		{
			return;
		}

		if (length(mod) == 1)
		{
			one_digit(mod);
		}

		else if (length(mod) == 2)
		{
			two_digit(mod);
		}

		else
		{
			ten_power(mod);

		}

	}

}

int length(int n)
{
	int len = 0;
	while(n != 0)
	{
		n /= 10;
		len++;
	}

	return len;
}