#include <stdio.h>

int check(int n)
{
    int result = 0, temp = 0, a = 0, i;
    for (i = 1; i < n; i++)
    {
        temp = result = i;
        while (temp > 0)
        {
            result += temp % 10;
            temp /= 10;
        }
        if (result == n)
        {
            a = 1;
            break;
        }
    }
    a == 1 ? printf("%d", i) : printf("0");
}
 
int main(void)
{
    int n;
    scanf("%d", &n);
    check(n);
}
