#include <stdio.h>
 
int main(void)
{
    int n, m, k, i, j, v, temp = 0;
    int **a, **b;
 
    //첫번째 행렬 받기
    scanf("%d %d", &n, &m);
    a = (int**)malloc(sizeof(int*)*n);
    for (i = 0; i < n; i++)
    {
        *(a + i) = (int *)malloc(sizeof(int)*m);
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
 
    //두번째 행렬 받기
    scanf("%d %d", &m, &k);
    b = (int**)malloc(sizeof(int*)*m);
    for (i = 0; i < m; i++)
    {
        *(b + i) = (int *)malloc(sizeof(int)*k);
        for (j = 0; j < k; j++)
            scanf("%d", &b[i][j]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            for (v = 0; v < m; v++)
            {
                temp = temp + a[i][v] * b[v][j];
            }
            printf("%d ", temp);
            temp = 0;
        }
        printf("\n");
    }
    return 0;
}