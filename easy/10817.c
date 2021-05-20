#include <stdio.h>
 
int main(void)
{
    int a, b, c, mid;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
    {
        if (a > c)
            if (b > c)
                mid = b;
            else
                mid = c;
        else
            mid = a;
    
    else
    {
        if (b > c)
            if (a > c)
                mid = a;
            else
                mid = c;
        else
            mid = b;
    }
    printf("%d", mid);
    return 0;
}