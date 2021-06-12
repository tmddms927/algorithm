#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int n

    //큐 생성
    QueueType *q
    q = (QueueType *)malloc(sizeof(QueueType));
    q->front = -1;
    q->rear = -1;
    q->num = 0;
 
    scanf("%d %d", &n, &q->front);
 
    while (q->rear++ < n-1)
    {
        q->queue[q->rear] = q->rear + 1;
    }
    printf("<");
    while (q->num != n-1)
    {
        deQueue(q, n);
    }
    printf(">\n");
    return 0;
}