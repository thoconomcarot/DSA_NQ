#include <stdio.h>
#include "addPolynomial.h"

int main(){
    ListPolynomial a,b;

    readList(&a);
    printf("\tFirst polynomial: ");
    printList(a);

    readList(&b);
    printf("\tSecond polynomial: ");
    printList(b);

    printf ("......................\n");
    ListPolynomial sum = addPolynomial(a,b);
    printf("Sum of two polynomial: ");
    printList(sum);

    printf ("Derivative of sum: ");
    derivative(&sum);
    printf ("......................\n");

    return 0;
}