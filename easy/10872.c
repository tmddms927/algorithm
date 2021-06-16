#include <stdio.h>
 
int factorial(int a, int n)
{
    int result = 1;
    for (int i = a; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}
 
int main(void)
{
    int n;
    scanf("%d", &n);
 
    printf("%d", factorial(1, n));
    return 0;
}