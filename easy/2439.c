#include <stdio.h>
 
int main(void)
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = n; j > i; j--)
            printf(" ");
        for (j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}