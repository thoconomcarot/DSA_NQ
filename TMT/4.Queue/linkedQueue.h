#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Queue;
    

void makeNull(Queue *Q);

ElementType sizeQueue(Queue Q);

void shiftLeft(int n, Queue *Q);

void enQueue(ElementType x, Queue *Q);

ElementType deQueue(Queue *Q);

void printQueue(Queue Q);

//khoi tao hang doi
void makeNull (Queue *Q){
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = NULL;
    Q->front = header;
    Q->rear = header;
}

int emptyQueue (Queue Q){
    return Q.front->next == NULL;
}

int fullQueue (Queue Q){
    return 1;
}

void printQueue (Queue Q){
    Node *temp = Q.front;
    while(temp->next){
        printf ("%d ", temp->next->data);
        temp = temp->next;
    }
    printf ("\n");
}

void enQueue(ElementType x, Queue *Q){
    Node*temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    Q->rear->next = temp;
    Q->rear = temp;
}

ElementType deQueue (Queue *Q){
    if(emptyQueue(*Q)){
        printf ("Queue is empty!!!");
        return -1;
    }
    else{
        Node *temp = Q->front->next;
        ElementType x = temp->data;
        Q->front->next = temp->next;
        free(temp);
        return x;
    }
}


