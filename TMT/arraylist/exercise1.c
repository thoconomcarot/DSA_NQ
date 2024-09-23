#include "alistlib.h"
#include <stdio.h>

int main (){
    List L;
    makeNull(&L); 

    int n,x;
    printf ("Enter the number of elements in list: ");
    scanf ("%d", &n);

    printf ("Enter elements: \n");
    for (int i = 1; i <= n; i++){
        printf ("\t Element %d: ", i);
        scanf ("%d", &x);
        append(x, &L);
    }
    printf ("\n");

    printf ("Print out the list: ");
    print(L);
    printf ("\n");

    //sap xep ds
    sort(&L);

    printf ("Print out the list after sort: ");
    print(L);
    printf ("\n");
    
    return 0;
}

