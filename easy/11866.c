#include <stdio.h>
#include <stdlib.h>
 
//큐 구조체
typedef char element;
typedef struct {
    element queue[1000];
    int front, rear, num;
}QueueType;
 
void deQueue(QueueType * q, int n)
{
    if (q->queue[q->front - 1] == 0)
    {
        q->front = (q->front + 3) % n;
    }
    else
    {
        printf("%d", q->queue[q->front - 1])
        q->num++;
        q->queue[q->front - 1] = 0;
        q->front = (q->front + 3) % n;
        if (q->num != n - 1)
            printf(", ");
    }
}
 
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