#include <stdio.h>

int power_of_two(int num)
{
    int check = num - 1;
    
    if((num & check) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    
    printf("Enter num: ");
    scanf("%d", &n);
    
    int ans = power_of_two(n);
    
    if(ans == 1)
    {
        printf("No. is power of two!\n");
    }
    else
    {
        printf("No. is not a power of two!\n");
    }
    
    return 0;
}