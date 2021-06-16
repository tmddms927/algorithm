// #include <stdio.h>
 
// int factorial(int a, int n)
// {
//     int result = 1;
//     for (int i = a; i <= n; i++)
//     {
//         result = result * i;
//     }
//     return result;
// }
 
// int main(void)
// {
//     int n;
//     scanf("%d", &n);
 
//     printf("%d", factorial(1, n));
//     return 0;
// }

#include <stdio.h>
 
int factorial(int a, int n)
{
    if (n == a)
        return a;
    return n * factorial(a, n-1);
}
 
int main(void)
{
    int n;
    scanf("%d", &n);
 
    printf("%d", factorial(1, n));
    return 0;
}