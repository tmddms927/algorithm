#include <stdio.h>
#include <stdlib.h>
 
int sort(const void *a, const void *b)
{
    if (*(int *)b < *(int *)a) return -1;
    if (*(int *)a == *(int *)b) return 0;
    return 1;
}
 
int main(void)
{
    int n, i, *a, temp, *b, num = 0;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int)*n);
    b = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
    {
        a[i] = 0;
        scanf("%d", &temp);
        if (temp == 0)
        {
            qsort((void *)a, n, sizeof(int), sort);
            b[num] = a[0];
            a[0] = 0;
            num++;
        }
        else
            a[i] = temp;
    }
    for (i = 0; i < num; i++)
    {
            printf("%d\n", b[i]);
    }
    return 0;
}