#include <stdio.h>
 
int main(void)
{
    int a, b, n[100], i=0;
    do
    {
        scanf("%d %d", &a, &b);
        n[i++] = a + b;
    } while (a != 0 && b != 0);
    for (int j =0 ;j < i-1; j++)
    {
        printf("%d\n", n[j]);
    }
    return 0;
}