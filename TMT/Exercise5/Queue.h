#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 100
typedef int ElementType;
typedef struct
{
    ElementType elements[MaxSize];
    int Front, Rear;
} Queue;

void makeNullQueue(Queue *Q);

int isEmptyQueue(Queue Q);

ElementType isFullQueue(Queue Q);

ElementType sizeQueue(Queue Q);

void shiftLeft(int n, Queue *Q);

void enQueue(ElementType x, Queue *Q);

ElementType deQueue(Queue *Q);

void printQueue(Queue Q);


// khởi tạo hàng đợi
void makeNullQueue(Queue *Q)
{
    Q->Front = 0;
    Q->Rear = 0;
}

// Check rỗng
int isEmptyQueue(Queue Q)
{
    return Q.Front == Q.Rear;
}

// check đầy
ElementType isFullQueue(Queue Q)
{
    return (Q.Rear - Q.Front == MaxSize);
}

// đếm phần tử
ElementType sizeQueue(Queue Q)
{
    return Q.Rear - Q.Front;
}


// dịch về bên trái
void shiftLeft(int n, Queue *Q){
    if (n <= 0){
        return;
    }
    int i;
    for (i = Q->Front; i < Q->Rear; i++){
        Q->elements[i-n] = Q->elements[i];
    }
    Q->Rear = i - n;
    Q->Front = 0;
}

  
// thêm phần tử
void enQueue(ElementType x, Queue *Q){
    if (isFullQueue(*Q)){
        printf("Queue is full!!");
        return;
    }
    else{
        if (Q->Front != 0 && Q->Rear == MaxSize){
            shiftLeft(Q->Front, Q);
        }
        Q->elements[Q->Rear++] = x;
    }
}

// xóa phần tử
ElementType deQueue(Queue *Q){
    if (isEmptyQueue(*Q)){
        printf("Queue is empty!!\n");
        return -1;
    }
    else{
        ElementType x = Q->elements[Q->Front]; // lấy ptu đầu tiên trong queue
        if (Q->Front == Q->Rear){
            makeNullQueue(Q);
        }
        else{
            Q->Front++;
        }
        return x;
    }
}

// in ra hàng đợi
void printQueue(Queue Q){
    if (isEmptyQueue(Q)){
        printf("Queue is empty!\n");
        return;
    }
    else{
        //int size = sizeQueue(Q);
        for (int i = Q.Front; i < Q.Rear; i++){
            printf("%d ", Q.elements[i]);
        }
        printf("\n");
    }

}
        
