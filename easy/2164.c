#include <stdio.h>
 
//큐 구조체
typedef char element;
typedef struct {
    element queue[10000];
    int front, rear, num;
}QueueType;
 
void deQueue(QueueType *q, int n)
{
    int bool = 0;
    while (bool != 2)
    {
        q->rear--;
        if (q->rear < 0)
            q->rear += n;
        if (q->queue[q->rear] != 0)
            bool++;
    }
}
 
void card(QueueType *q, int n)
{
    q->queue[q->rear] = 0;
    deQueue(q, n);
    q->num++;
}
 
int main(void)
{
    int n;
    scanf("%d", &n);
    QueueType *q;
    q = (QueueType *)malloc(sizeof(QueueType));
    q->front = -1;
    q->rear = -1;
    q->num = 0;
    
    while (q->rear++ < n-1)
    {
        q->queue[q->rear] = n - q->rear;
    }
    q->rear--;
    while (q->num < n-1)
    {
        card(q, n);
    }
    printf("%d", q->queue[q->rear]);
    return 0;
}