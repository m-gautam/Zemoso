#include<stdio.h>
#include<math.h>

// it sums all the digits of a number which becomes 
// two digit when multiplied by 2
int numsum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(void)
{
    // Variables definition
    long number, temp, temp1 ;
    scanf("%ld",&number);
    temp = number;
    temp1 = number;
    
    int s1 = 0, s2 =0;
    
    // Loop to iterate on input no.
    while (number > 0)
    {
        long m = number%100;
        s1 += m%10;
        m /= 10;
        s2 += numsum(m*2);

        number /= 100;
        
    }
    
    // Checks whether follow Luhn's Algorithm
    if ((s1+s2)%10 == 0)
    {
        int size = 0;
        while (temp > 0)
        {
            temp /= 10;
            size++;
        }
        
        // Checks condition for AMEX cards
        if (size == 15)
        {   
            
            int p = temp1 / pow(10,13);
            
            if ( p == 34 || p == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
            
        }
        
        // Checks condition for VISA cards
        else if (size == 13)
        {
            int p = temp1 / pow(10,12);
            if (p == 4)
            {    
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        
        // Checks condition for VISA and MASTERCARD cards
        else if (size == 16)
        {
            int p = temp1 / pow(10,14);
            if ( p == 51 || p == 52 || p == 53 || p == 54 || p == 55)
            {
                printf("MASTECARD\n");
            }
            else if (p/10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID");
            }
        }
        else
        {
            printf("INVALID\n");
        }  
    }
    else
    {
        printf("INVALID\n");
    }    
    return 0;
}
