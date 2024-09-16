#include "ex2.h"
#include <stdio.h>

int main()
{
    int n;
    polynomial x, y, sum, derivativePoly;
    
    // Nhập đa thức 1
    printf("\n\nNhap so luong don thuc cua da thuc 1: ");
    scanf("%d", &n);
    x = read(n); // Gán kết quả trả về cho x
    printf("\nDa thuc 1 sau khi sap xep: ");
    print(x);
    
    // Nhập đa thức 2
    printf("\nNhap so luong don thuc cua da thuc 2: ");
    scanf("%d", &n);
    y = read(n); // Gán kết quả trả về cho y
    printf("\nDa thuc 2 sau khi sap xep: ");
    print(y);

    // Cộng hai đa thức
    sum = addTwoPoly(x, y);
    printf("\nTong cua hai da thuc: ");
    print(sum);

    // Tính đạo hàm của đa thức 1
    derivativePoly = derivative(x);
    printf("\nDao ham cua da thuc 1: ");
    print(derivativePoly);

    return 0;
}