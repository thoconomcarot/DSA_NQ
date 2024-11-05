#include <stdio.h>
#include <stdlib.h>
#define Max_length 100

typedef int ElementType;
typedef struct{
    ElementType elements[Max_length];
    int top;
}Stack;

void makeNullStack(Stack *S);

int isEmptyStack(Stack S);

int isFullStack(Stack S);

void push(ElementType x, Stack *S);

ElementType pop(Stack *S);

void print(Stack S);

void convertBinary(int n);

int Fibonacci(int n);

int C(int k, int n);


void makeNullStack(Stack *S){
    S->top = -1;
}

int isEmptyStack(Stack S){
    return S.top == -1;
}

int isFullStack(Stack S){
    return S.top == Max_length-1;
}

void push(ElementType x, Stack *S){
    if(isFullStack(*S)){
        printf ("Stack is full!\n");
        return;
    }
    else{
        S->top++;
        S->elements[S->top] = x;
    }
}

ElementType pop(Stack *S){
    int x;
    if(isEmptyStack(*S)){
        printf ("Stack is empty!\n");
        return -1;
    }
    else{
        return S->elements[S->top--];
    }
}

void printStack(Stack S){
    if(isEmptyStack(S)){
        printf ("Stack is empty!\n");
    }
    else{
        for (int i = 0; i <= S.top; i++){
            printf ("%d ", S.elements[i]);
        }
        printf ("\n");
    }
}

void convertBinary(int n){
    Stack S;
    makeNullStack(&S);
    if(n == 0){
        push(0, &S);
    }
    else{
        while( n != 0){
            push(n % 2, &S);
            n /= 2;
        }
    }
    while(!isEmptyStack(S)){ //lặp đến khi stack rỗng
        printf ("%d", pop(&S));
    }
    printf ("\n");

}


int Fibonacci (int n){  //Số fibo là số tiếp theo bằng tổng của hai số liền trước
    // Sack S;
    // makeNull(&S);
    // push(n, &S); //đẩy gt (số fibo cần tính) vào ngăn xếp
        if (n == 1 || n == 2){
            return 1;
        }
        else{
            return Fibonacci(n-1) + Fibonacci(n-2);
        }
}


int C(int k, int n){
    if(k == 0 || k == n){
        return 1;
    }
    if(k == 1){
        return n;
    }
    return C(k-1, n-1) + C(k, n-1);
}

