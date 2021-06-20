#include <stdio.h>

 

int sum(int n)

{

    int total;

    if (n < 2)

        total = n;

    else

        total = sum(n-1) + sum(n-2);

    return total;

}

 

int main(void)

{

    int n = 0, total = 0;

    scanf("%d", &n);

 

    printf("%d\n", sum(n));

    return 0;

}