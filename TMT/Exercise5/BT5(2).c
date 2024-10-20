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
        enQueue(x, &Q);
    }
    printf ("Queue before reversed: ");
    printQueue(Q);

//Đảo ngược ngăn xếp sd hàng đợi
    while(!isEmptyQueue(*Q)){
       push(deQueue(Q), &S);
    }
   

//Chuyển ptu trong Queue vào Stack
    while(!isEmptyStack(S)){
        enQueue(pop(&S), Q);
    }


//In ra
    printf ("Queue after reversed: ");
    printQueue(Q);

return 0;
}
