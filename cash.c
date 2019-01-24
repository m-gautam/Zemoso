#include<stdio.h> 

 
 // Calculating the minimum no. of coins required.
int min_coins(int coins[], int s, int n) 
{ 

	if (n == 0)
	{
		return 0;
	} 
 	
 	// Stores the min. no. of coins
	int min = 1000000; 

	for (int i = 0; i < s; i++) 
	{ 
		if (coins[i] <= n) 
		{ 
			int ans = min_coins(coins, s, n-coins[i]); 

			if (ans != 1000000 && ans + 1 < min) 
			min = ans + 1; 
		} 
	} 
	return min; 
} 

int main(void) 
{ 
	// variable definition n - amount, s - size
	int n,s;
	scanf("%d %d",&n,&s);
	
	// array contain value of coins
	int coins[s];
	for (int i = 0; i < s; i++)
	{
		scanf("%d",&coins[i]);
	}

	// Calling the function
	int res = min_coins(coins, s, n);
	printf("%d",res);

	return 0; 
} 
