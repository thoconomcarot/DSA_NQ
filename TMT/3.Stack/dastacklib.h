#include <stdio.h>
#include <stdlib.h>
#define Max_length 100

typedef int ElementType;
typedef struct{
    ElementType elements[Max_length];
    int top;
}Stack;

void makeNull(Stack *st);

int isEmpty(Stack st);

int isFull(Stack st);

void push(ElementType x, Stack *st);

ElementType pop(Stack *st);

void print(Stack st);

void convertBinary(int n);

int Fibonacci(int n);

int C(int k, int n);


void makeNull(Stack *st){
    st->top = -1;
}

int isEmpty(Stack st){
    return st.top == -1;
}

int isFull(Stack st){
    return st.top == Max_length-1;
}

void push(ElementType x, Stack *st){
    if(isFull(*st)){
        printf ("Stack is full!\n");
        return -1;
    }
    else{
        st->top++;
        st->elements[st->top] = x;
    }
}

ElementType pop(Stack *st){
    int x;
    if(isEmpty(*st)){
        printf ("Stack is empty!\n");
        return -1;
    }
    else{
        st->elements[st->top--];
    }
}

// void print(Stack st){
//     if(isEmpty(st)){
//         printf ("Stack is empty!\n");
//     }
//     else{
//         printf("Stack: ");
//         for (int i = 0; i <= st.top; i++){
//             printf ("%d ", st.elements[i]);
//         }
//         printf ("\n");
//     }
// }

void convertBinary(int n){
    Stack st;
    makeNull(&st);
    if(n == 0){
        push(0, &st);
    }
    else{
        while( n != 0){
            push(n % 2, &st);
            n /= 2;
        }
    }
    while(!isEmpty(st)){ //lặp đến khi stack rỗng
        printf ("%d", pop(&st));
    }
    printf ("\n");

}


int Fibonacci (int n){  //Số fibo là số tiếp theo bằng tổng của hai số liền trước
    // Stack st;
    // makeNull(&st);
    // push(n, &st); //đẩy gt (số fibo cần tính) vào ngăn xếp
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

