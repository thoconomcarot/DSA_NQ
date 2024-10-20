#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

int main (){
    Stack S;
    Queue Q;
    makeNullQueue(&Q);
    makeNullStack(&S);
    int n, x, res;

//Nhập phần tử vào stack
    printf ("Nhap sl phan tu: ");
    scanf ("%d", &n);
    printf ("Nhap cac phan tu: %d");
    for (int i = 1; i <= n; i++){
        scanf ("%d", &x);
        push(x, &S);
    }
    printf ("Ngăn xếp chưa sắp: ");
    printStack(S);

//Đảo ngược ngăn xếp sd hàng đợi
    while(!isEmptyStack(S)){
         res = pop(&S);
        enQueue (res, &Q);
    }
   

//Chuyển ptu trong Queue vào Stack
    while(!isEmptyQueue(Q)){
        res = deQueue(&Q);
        push(res, &S);
    }


//In ra
    printf ("Ngăn xếp sau khi đảo: ");
    printStack(S);

return 0;
}
