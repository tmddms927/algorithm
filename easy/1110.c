#include <stdio.h>
 
int main(void)
{
    int a, b = 0, n = 1;
    scanf("%d", &a);
    b = (a%10)*10 + ((a / 10) + (a % 10))%10;
    while (b != a)
    {
        b = (b % 10)*10 + ((b / 10) + (b % 10))%10;
        n++;  
    }
    printf("%d\n", n);
    return 0;
}