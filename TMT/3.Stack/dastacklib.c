#include <stdio.h>
#include "dastacklib.h"

int main (){
    int x; 
    printf("Enter the number: ");
    scanf("%d", &x);

    printf("\tBinary number of %d is: ", x); //số nhị phân
    convertBinary(x);

    printf ("\tFibonacci number %d: %d\n", x, Fibonacci(x)); // tính fibo = tổng 2 số trước

    printf("Enter k and n: ");
    int k, n; scanf ("%d %d", &k, &n);
    printf("\tThe combination of %d of %d is: %d\n", k, n, C(k, n)); //tính tổ hợp
    
    return 0;
}