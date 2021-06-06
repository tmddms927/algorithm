#include <stdio.h>
 
int main(void)
{
    int a;
    scanf("%d", &a);
    if (a % 4 == 0)
    {
        if (a % 100 != 0)
            printf("1\n");
        else if (a % 400 == 0)
            printf("1\n");
        else
            printf("0\n");
    }
    else
        printf("0\n");
    return 0;
}