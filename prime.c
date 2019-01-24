#include<stdio.h>

void prime(int n)
{	
	// Array defined then all values is initialized by 1
	// 1 denotes primary no. and 0 denotes not a prime no.
	int isprime[n+1];

	for(int i =0; i <= n;i++)
	{
		isprime[i] = 1;		
	}

	// Loop starts from 2 till i*i <= n 

	for(int i= 2; i*i <= n; i++)
	{

		// Checks whether prime or not, then initializes the
		// of isprime array having indexes multiple of i. 

		if(isprime[i])
		{
			for(int j = i*i; j <= n; j += i)
				isprime[j] = 0;
		}
	}

	for(int i = 2; i <= n; i++)
	{
		// Outputs the prime no.
		if(isprime[i])
			printf("%d ",i);

	}


}

int main(void)
{
	int n;
	scanf("%d",&n);

	prime(n);

	return 0;
}