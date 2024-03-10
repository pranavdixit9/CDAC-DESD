#include <stdio.h>

int main()
{
    int pos, num;
    
    printf("Enter the num: ");
    scanf("%d", &num);
    
    printf("Enter the Pos: ");
    scanf("%d", &pos);
    
    int n = ~(1 << (pos - 1));
    
    int ans = (num & n);
    
    printf("Ans: %d", ans);
    return 0;
}