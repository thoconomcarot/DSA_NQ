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
    printf ("Enter the number of elements: ");
    scanf ("%d", &n);
    printf ("Enter elements: ");
    for (int i = 1; i <= n; i++){
        scanf ("%d", &x);
        push(x, &S);
    }
    printf ("Stack before reversed: ");
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
    printf ("Stack after reversed: ");
    printStack(S);

return 0;
}
