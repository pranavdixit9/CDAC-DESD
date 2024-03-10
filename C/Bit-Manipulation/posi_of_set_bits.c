#include <stdio.h>

int main()
{
    int num;
    
    printf("Enter the number: ");
    scanf("%d", &num);
    int count = 0;
    
    printf("Set Bits at pos: ");
    
    for(int i = 0; i < sizeof(int)*8; i++)
    {
        if(num & (1<<i))
        {
            printf("%d", i + 1);
            count++;
        }
    }
    printf("\n");
    
    printf("No. of Set Bits: %d", count);
    return 0;
}