#include <stdio.h>
 
int main(void)
{
    int n, b, *a, i;
    scanf("%d %d", &n, &b);
    a = (int *)malloc(sizeof(int)*n);
    for (i =0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        if(a[i] < b)
            printf("%d ", a[i]);
    }
    return 0;
}