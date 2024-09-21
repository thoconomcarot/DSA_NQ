#include "addPoly.h"
#include <stdio.h>

int main()
{
    int n;
    polynomial x, y, sum, derivativePoly;
    
    // Nhập đa thức 1
    printf("Enter the number of monomial 1: ");
    scanf("%d", &n);
    x = read(n); // Gán kết quả trả về cho x
    printf("Da thuc 1 sau khi sap xep: ");
    print(x);
    
    // Nhập đa thức 2
    printf("Enter the number of monomial 2: ");
    scanf("%d", &n);
    y = read(n); // Gán kết quả trả về cho y
    printf("Da thuc 2 sau khi sap xep: ");
    print(y);

    // Cộng hai đa thức
    sum = addTwoPoly(x, y);
    printf("Sum of two polynomial: ");
    print(sum);

    // Tính đạo hàm của đa thức 1
    derivativePoly = derivative(sum);
    printf("Derivative of sum: ");
    print(derivativePoly);

    return 0;
