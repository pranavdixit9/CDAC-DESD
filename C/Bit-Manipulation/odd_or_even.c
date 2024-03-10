#include <stdio.h>

int main()
{
    int num;
    
    printf("Enter the num: ");
    scanf("%d", &num);
    
    if(num & 1 == 1)
    {
        printf("Number is ODD.\n");
    }
    else
    {
        printf("Number is EVEN.\n");
    }
    
    return 0;
}