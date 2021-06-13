#include <stdio.h>
 
void check(int a, int b)
{
    if (a % b == 0)
        printf("multiple\n");
    else if(b % a == 0)
        printf("factor\n");
    else
        printf("neither\n");
}

int main(void)
{
    int a, b, i;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            break;
        check(a, b);
    }
    return 0;
}