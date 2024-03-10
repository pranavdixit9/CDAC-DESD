#include <stdio.h>

int main()
{
    int pos, num;
    
    printf("Enter the num: ");    // 4 in binary -> 0100
    scanf("%d", &num);
    
    printf("Enter the Pos: ");    // 2nd position
    scanf("%d", &pos);
    
    int n = 1 << (pos - 1);    // 1 << (2-1)  ->  1 << 1  ->  0010
    
    int ans = n | num;        // 0100 | 0010  ->  0110
    
    printf("Ans: %d", ans);    // 0110 in decimal -> 6

    return 0;
}
