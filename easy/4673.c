#include <stdio.h>
 
int result(int i)
{
    int res = i;
    while (i != 0)
    {
        res += i % 10;
        i = i / 10;
    }
    return res;
}
 
int main(void)
{
    int a[10000] = {0}, i = 0, x;
    for (i = 0; i < 10000; i++)
    {
        x = result(i);
        if (x < 10000)
            a[x] = 1;
    }
    for (i = 0; i < 10000; i++)
    {
        if (a[i] == 0)
            printf("%d\n", i);
    }
    return 0;
}
