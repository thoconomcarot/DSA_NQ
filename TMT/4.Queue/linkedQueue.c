#include <stdio.h>
#include "linkedQueue.h"

int main (){
    int n,x;
    Queue Q;

    makeNull(&Q);
    printf ("Enter the number of elements to queue: ");
    scanf ("%d", &n);

    //Nhập từng phần tử
    printf ("Enter elements to queue: ");
    for (int i =0; i < n; i++){
        scanf ("%d", &x);
        enQueue(x, &Q);
    }
    printf ("Queue is: ");
    printQueue(Q);
    printf ("\n");


    //lấy ra 1 phần tử 
    deQueue(&Q);
    printf ("Queue after dequeue is: ");
    printQueue(Q);
    printf ("\n");

    return 0;
}