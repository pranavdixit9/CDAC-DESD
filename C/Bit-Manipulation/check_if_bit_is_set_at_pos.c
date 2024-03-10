#include <stdio.h>

int main()
{
    int num, pos;
    
    printf("Enter num: ");
    scanf("%d", &num);
    
    printf("Enter pos: ");
    scanf("%d", &pos);
    
    int check = 1 << (pos - 1);
    
    if((num & check) != 0)
    {
        printf("Bit is Set!\n");
    }
    else
    {
        printf("Bit is not Set!\n");
    }
    return 0;
}