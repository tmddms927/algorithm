#include <stdio.h>
 
int main(void)
{
    int n = 0, pp[50][2], cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &pp[i][0], &pp[i][1]);
    }
    for (int i = 0; i < n; i++)
    {
        cnt = 1;
        for (int j = 0; j < n; j++)
        {
            if (pp[i][0] < pp[j][0] && pp[i][1] < pp[j][1])
                cnt++;
        }
        printf("%d ", cnt);
    }
    return 0;
}