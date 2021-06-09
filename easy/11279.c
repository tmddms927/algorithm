// #include <stdio.h>
// #include <stdlib.h>
 
// int sort(const void *a, const void *b)
// {
//     if (*(int *)b < *(int *)a) return -1;
//     if (*(int *)a == *(int *)b) return 0;
//     return 1;
// }
 
// int main(void)
// {
//     int n, i, *a, temp, *b, num = 0;
//     scanf("%d", &n);
//     a = (int *)malloc(sizeof(int)*n);
//     b = (int *)malloc(sizeof(int)*n);
//     for (i = 0; i < n; i++)
//     {
//         a[i] = 0;
//         scanf("%d", &temp);
//         if (temp == 0)
//         {
//             qsort((void *)a, n, sizeof(int), sort);
//             b[num] = a[0];
//             a[0] = 0;
//             num++;
//         }
//         else
//             a[i] = temp;
//     }
//     for (i = 0; i < num; i++)
//     {
//             printf("%d\n", b[i]);
//     }
//     return 0;
// }
#include <stdio.h>
#define TRUE    1
#define FALSE    0
 
//Heap의 정의
#define HEAP_LEN    100000
 
typedef int HData;
typedef int PriorityComp(HData d1, HData d2);
 
typedef struct _heap
{
    PriorityComp * comp;
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;
 
// Heap 관련 연산들
void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);
 
void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);
 
void HeapInit(Heap * ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}
 
int HIsEmpty(Heap * ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}
 
int GetParentIDX(int idx)
{
    return idx / 2;
}
 
int GetLChildIDX(int idx)
{
    return idx * 2;
}
 
int GetRChildIDX(int idx)
{
    return GetLChildIDX(idx) + 1;
}
 
int GetHiPriChildIDX(Heap * ph, int idx)
{
    if (GetLChildIDX(idx) > ph->numOfData)
        return 0;
 
    else if (GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
 
    else
    {
 
        if (ph->comp(ph->heapArr[GetLChildIDX(idx)],
            ph->heapArr[GetRChildIDX(idx)]) < 0)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}
 
void HInsert(Heap * ph, HData data)
{
    int idx = ph->numOfData + 1;
 
    while (idx != 1)
    {
        if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
        {
            break;
        }
    }
 
    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}
 
HData HDelete(Heap * ph)
{
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];
 
    int parentIdx = 1;
    int childIdx;
 
    while (childIdx = GetHiPriChildIDX(ph, parentIdx))
    {
        //    if(lastElem.pr <= ph->heapArr[childIdx].pr)
        if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;
 
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
 
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}
 
int DataPriorityComp(HData ch1, HData ch2){
       return ch1-ch2;
}
int main(void)
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);
        if (input == 0) {
            if (!HIsEmpty(&heap))
                printf("%d\n", HDelete(&heap));
            else
                printf("0\n");
        }
        else if (input > 0)
            HInsert(&heap, input);
    }
    return 0;
}