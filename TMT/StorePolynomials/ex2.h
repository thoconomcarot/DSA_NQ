#include <stdio.h>
#include <math.h>
#define MaxLength 100

typedef struct monomial // don thuc
{
    int factor; // he so
    int exponent; // bac
} monomial;

typedef struct polynomial // da thuc
{
    monomial polynomialType[MaxLength]; // khai báo danh sách đa thức
    int position;
} polynomial;

polynomial read(int a);
void print(polynomial x);
void Insertsionsort(polynomial *x);// sort
polynomial addTwoPoly(polynomial s1, polynomial s2);// cộng 2 đa thức
polynomial derivative(polynomial poly);// đạo hàm



polynomial read(int a)
{
    polynomial x;
    for (int i = 0; i < a; i++)
    {
        printf("nhap he so cua don thuc thu %d: ", i + 1);
        scanf("%d", &x.polynomialType[i].factor);
        printf("nhap bac cua don thuc thu %d: ", i + 1);
        scanf("%d", &x.polynomialType[i].exponent);
    }
    x.position = a; // Số lượng đơn thức trong đa thức
    Insertsionsort(&x); // Truyền địa chỉ của `x` cho hàm Insertsionsort
    return x;
}

void print(polynomial x)
{
    for (int i = 0; i < x.position; i++)
    {
        if (x.polynomialType[i].exponent == 0)
        {
            printf("%.2d ", x.polynomialType[i].factor);
        }
        else
        {
            printf("(%.2d)X^%d ", x.polynomialType[i].factor, x.polynomialType[i].exponent);
        }
        if (i != x.position - 1)
        {
            printf("+ ");
        }
    }
    printf("\n");
}

void Insertsionsort(polynomial *x)
{
    /*Sắp xếp chèn các đơn thức theo thứ tự giảm dần của bậc
    Insertsion sort
    */
    for (int i = 1; i < x->position; i++)
    {
        int factor = x->polynomialType[i].factor;   // Lấy hệ số của đơn thức thứ i
        int exponent = x->polynomialType[i].exponent; // Lấy bậc của đơn thức thứ i
        int pos = i - 1;

        // Dịch chuyển các đơn thức có bậc lớn hơn đơn thức hiện tại
        while (pos >= 0 && x->polynomialType[pos].exponent < exponent)
        {
            x->polynomialType[pos + 1].factor = x->polynomialType[pos].factor;
            x->polynomialType[pos + 1].exponent = x->polynomialType[pos].exponent;
            pos--;
        }

        // Chèn đơn thức tại đúng vị trí
        x->polynomialType[pos + 1].factor = factor;
        x->polynomialType[pos + 1].exponent = exponent;
    }
}


polynomial addTwoPoly(polynomial s1, polynomial s2)
{
    polynomial result;
    result.position = 0; // Đặt vị trí ban đầu của kết quả là 0

    int i = 0, j = 0;
    while (i < s1.position && j < s2.position)
    {
        if (s1.polynomialType[i].exponent == s2.polynomialType[j].exponent)
        {
            // Nếu hai đơn thức có cùng bậc, cộng hệ số lại
            result.polynomialType[result.position].factor = s1.polynomialType[i].factor + s2.polynomialType[j].factor;
            result.polynomialType[result.position].exponent = s1.polynomialType[i].exponent;
            i++;
            j++;
        }
        else if (s1.polynomialType[i].exponent > s2.polynomialType[j].exponent)
        {
            // Nếu bậc của s1 lớn hơn, thêm đơn thức của s1 vào kết quả
            result.polynomialType[result.position] = s1.polynomialType[i];
            i++;
        }
        else
        {
            // Nếu bậc của s2 lớn hơn, thêm đơn thức của s2 vào kết quả
            result.polynomialType[result.position] = s2.polynomialType[j];
            j++;
        }
        result.position++;
    }

    // Thêm các đơn thức còn lại của s1 (nếu có)
    while (i < s1.position)
    {
        result.polynomialType[result.position] = s1.polynomialType[i];
        i++;
        result.position++;
    }

    // Thêm các đơn thức còn lại của s2 (nếu có)
    while (j < s2.position)
    {
        result.polynomialType[result.position] = s2.polynomialType[j];
        j++;
        result.position++;
    }

    return result;
}

polynomial derivative(polynomial poly)
{
    polynomial newPoly;
    newPoly.position = 0; // Khởi tạo đa thức mới với vị trí bằng 0
    
    for (int i = 0; i < poly.position; i++)
    {
        if (poly.polynomialType[i].exponent == 0)
        {
            // Đạo hàm của hằng số là 0, bỏ qua
            continue;
        }
        
        newPoly.polynomialType[newPoly.position].factor = poly.polynomialType[i].factor * poly.polynomialType[i].exponent;
        newPoly.polynomialType[newPoly.position].exponent = poly.polynomialType[i].exponent - 1;
        newPoly.position++;
    }

    return newPoly;
}


// int main()
// {
//     int n;
//     polynomial x, y, sum, derivativePoly;
    
//     // Nhập đa thức 1
//     printf("Nhap so luong don thuc cua da thuc 1: ");
//     scanf("%d", &n);
//     x = read(n); // Gán kết quả trả về cho x
//     printf("Da thuc 1 sau khi sap xep: ");
//     print(x);
    
//     // Nhập đa thức 2
//     printf("Nhap so luong don thuc cua da thuc 2: ");
//     scanf("%d", &n);
//     y = read(n); // Gán kết quả trả về cho y
//     printf("Da thuc 2 sau khi sap xep: ");
//     print(y);

//     // Cộng hai đa thức
//     sum = addTwoPoly(x, y);
//     printf("Tong cua hai da thuc: ");
//     print(sum);

//     // Tính đạo hàm của đa thức 1
//     derivativePoly = derivative(x);
//     printf("Dao ham cua da thuc 1: ");
//     print(derivativePoly);

//     return 0;
// }