#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.9f", (double)a/(double)b);
}