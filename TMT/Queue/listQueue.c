#include <stdio.h>
#include "listQueue.h"

int main (){
    Queue Q;
    int n, x;
    makeNull(&Q);

    
   //Nhập số phần tử của hàng đợi
    printf ("Enter the number of elements to queue: ");
    scanf ("%d", &n);

    //Nhập từng phần tử
    printf ("Enter elements to queue: ");
    for (int i =0; i < n; i++){
        scanf ("%d", &x);
        enQueue(x, &Q);
    }
    
    // enQueue(1, &Q);
    // enQueue(2, &Q);
    // enQueue(3, &Q);
    // enQueue(4, &Q);
    // enQueue(5, &Q);


    printf ("Queue is: ");
    printQueue(Q);
    printf ("\n");
   
    return 0;
}