#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxLength 10
typedef int ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;

void makeNull(Queue *Q); // khởi tạo hàng đợi

ElementType isEmpty(Queue Q); // kiểm tra rỗng

ElementType fullQueue(Queue Q); // kiểm tra đầy

ElementType sizeQueue(Queue Q); // kiểm tra kích thước

void shiftLeft(int n, Queue *Q); // dịch về bên trái

void enQueue(ElementType x, Queue *Q); // thêm phần tử

ElementType deQueue(Queue *Q); // xóa phần tử

void printQueue(Queue Q); // in ra

void makeNull(Queue *Q)
{
    Q->Front = 0;
    Q->Rear = 0;
}

ElementType isEmpty(Queue Q)
{
    return Q.Front == Q.Rear;
}

ElementType fullQueue(Queue Q)
{
    return (Q.Rear - Q.Front == MaxLength);
}

ElementType sizeQueue(Queue Q)
{
    return Q.Rear - Q.Front;
}

void shiftLeft(int n, Queue *Q)
{
    for (int i = 0; i < Q->Rear - Q->Front; i++)
        Q->Elements[i] = Q->Elements[n + i];
    Q->Front = 0;
    Q->Rear -= n;
}

void enQueue(ElementType x, Queue *Q)
{
    if (!fullQueue(*Q))
    {
        if (Q->Front != 0 && Q->Rear == MaxLength)
            shiftLeft(Q->Front, Q);
        Q->Elements[Q->Rear++] = x;
    }
    else

        printf("hang day!!!");
}

ElementType deQueue(Queue *Q)
{
    if (!isEmpty(*Q))
    {
        ElementType rs = Q->Elements[Q->Front];
        if (Q->Front == Q->Rear - 1)
            makeNull(Q);
        else
            Q->Front++;
        return rs;
    }
    else
        printf("Queue rong !!!");
    exit(EXIT_FAILURE);
}

void printQueue(Queue Q)
{
    if (!isEmpty(Q))
    {
        int size = sizeQueue(Q);
        for (int i = 0; i < size; i++)
            printf("%d", Q.Elements[Q.Front + i]);
        printf("\n");
    }
}
