#include <stdio.h>
 
void irreducible(int a, int b)
{
    for (int i = a; i > 1; i--)
    {
        if (a%i == 0 && b%i == 0)
        {
            a = a / i;
            b = b / i;
        }
    }
    printf("%d/%d\n", a, b);
}

int main(void)
{
    int *a, n, i

    char cha[300], *token
    scanf("%d", &n);

    a = (int *)malloc(sizeof(int)*n)
    token = strtok(cha, " ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        irreducible(a[0], a[i]);
    }
    return 0;
}