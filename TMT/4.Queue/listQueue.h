#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 100
typedef int ElementType;
typedef struct
{
    ElementType elements[MaxSize];
    int front, rear;
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
    Q->front = 0;
    Q->rear = 0;
}

// Check rỗng
ElementType isEmpty(Queue Q)
{
    return Q.front == Q.rear;
}

// check đầy
ElementType isFull(Queue Q)
{
    return (Q.rear - Q.front == MaxSize);
}

// đếm phần tử
ElementType sizeQueue(Queue Q)
{
    return Q.rear - Q.front;
}


// dịch về bên trái
void shiftLeft(int n, Queue *Q){
    int i;
    for (i = 0; i < MaxSize; i++){
        Q->elements[i-n] = Q->elements[i];
    }
    Q->front = 0;
    Q->rear = i - n;
}

  
// thêm phần tử
void enQueue(ElementType x, Queue *Q){
    if (isFull(*Q)){
        printf("Queue is full!!");
        return;
    }
    else{
        if (Q->front != 0 && Q->rear == MaxSize){
            shiftLeft(Q->front, Q);
        }
        Q->elements[Q->rear++] = x;
    }
}

// xóa phần tử
ElementType deQueue(Queue *Q){
    if (isEmpty(*Q)){
        printf("Queue is empty!!\n");
        return -1;
    }
    else{
        ElementType x = Q->elements[Q->front]; // lấy ptu đầu tiên trong queue
        if (Q->front == Q->rear - 1){
            makeNull(Q);
        }
        else{
            Q->front++;
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
            printf("%d ", Q.elements[Q.front+i]);
        }
        printf("\n");
    }

}
        
