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

void makeNull(Queue *Q);

ElementType isEmpty(Queue Q);

ElementType isFull(Queue Q);

ElementType sizeQueue(Queue Q);

void shiftLeft(int n, Queue *Q);

void enQueue(ElementType x, Queue *Q);

ElementType deQueue(Queue *Q);

void printQueue(Queue Q);


// khởi tạo hàng đợi
void makeNull(Queue *Q)
{
    Q->Front = 0;
    Q->Rear = 0;
}

// Check rỗng
ElementType isEmpty(Queue Q)
{
    return Q.Front == Q.Rear;
}

// check đầy
ElementType isFull(Queue Q)
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
    int i;
    for (i = 0; i < MaxSize; i++){
        Q->elements[i-n] = Q->elements[i];
    }
    Q->Front = 0;
    Q->Rear = i - n;
}

  
// thêm phần tử
void enQueue(ElementType x, Queue *Q){
    if (isFull(*Q)){
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
    if (isEmpty(*Q)){
        printf("Queue is empty!!\n");
        return -1;
    }
    else{
        ElementType x = Q->elements[Q->Front]; // lấy ptu đầu tiên trong queue
        if (Q->Front == Q->Rear - 1){
            makeNull(Q);
        }
        else{
            Q->Front++;
        }
        return x;
    }
}

// in ra hàng đợi
void printQueue(Queue Q){
    if (isEmpty(Q)){
        printf("###ERROR###");
        return;
    }
    else{
        int size = sizeQueue(Q);
        for (int i = 0; i < size; i++){
            printf("%d ", Q.elements[Q.Front+i]);
        }
        printf("\n");
    }

}
        
