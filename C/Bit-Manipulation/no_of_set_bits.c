#include <stdio.h>

int main()
{
    int num;
    
    printf("Enter the number: ");
    scanf("%d", &num);
    int count = 0;
    while(num)
    {
        if(num & 1 == 1)
        {
            count++;
        }
        num = num >> 1;
    }
    
    printf("No. of Set Bits: %d", count);
    return 0;
}