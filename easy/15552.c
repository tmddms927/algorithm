#include <stdio.h>

 
int main(void)
{
    int num, i, a, b;
    scanf("%d", &num);
    int *n;
    n = (int*)malloc(sizeof(int)*(num));
    for (i = 0; i < num; i++)
    {
        scanf("%d %d", &a, &b);
        n[i] = a + b;
    }
    for (i = 0; i < num; i++)
    {
        printf("%d\n", n[i]);
    }
    return 0;
}
