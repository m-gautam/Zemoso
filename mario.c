#include <stdio.h>

int main(void)
{
    int h;
    
    // Loop for input, ask for input until get right input.
    do
    {
        scanf("%d",&h);
        printf("Height: %d\n",h);       
    }
    while(h<1 || h>8);
    
    int count = 1;

    // Loop for draw required pattern
    while(h>0)
    {
        for(int i = h-1;i>0;i--)
        {
            printf(" ");
        }
        for(int j = 0; j < count; j++)
        {
            printf("#");
        }
        
        printf("  ");
        for(int j = 0;j < count; j++)
        {
            printf("#");
        }
        h--;
        count++;
        printf("\n");
    }
    
    return 0;
}
