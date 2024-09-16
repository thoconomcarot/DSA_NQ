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



polynomial read(int a){
    polynomial x;
    for (int i = 0; i < a; i++){
        printf("Enter the coefficient %d: ", i + 1);
        scanf("%d", &x.polynomialType[i].factor);
        printf("Enter the exponent %d: ", i + 1);
        scanf("%d", &x.polynomialType[i].exponent);
    }
    x.position = a; 
    Insertsionsort(&x); 
    return x;
}

void print(polynomial x){
    for (int i = 0; i < x.position; i++){
        if (x.polynomialType[i].exponent == 0){
            printf("%.2d ", x.polynomialType[i].factor);
        }
        else{
            printf("(%.2d)X^%d ", x.polynomialType[i].factor, x.polynomialType[i].exponent);
        }
        if (i != x.position - 1){
            printf("+ ");
        }
    }
    printf("\n");
}

void Insertsionsort(polynomial *x){
    for (int i = 1; i < x->position; i++){
        int factor = x->polynomialType[i].factor;   
        int exponent = x->polynomialType[i].exponent; 
        int pos = i - 1;
        
        while (pos >= 0 && x->polynomialType[pos].exponent < exponent){
            x->polynomialType[pos + 1].factor = x->polynomialType[pos].factor;
            x->polynomialType[pos + 1].exponent = x->polynomialType[pos].exponent;
            pos--;
        }
        x->polynomialType[pos + 1].factor = factor;
        x->polynomialType[pos + 1].exponent = exponent;
    }
}


polynomial addTwoPoly(polynomial s1, polynomial s2)
{
    polynomial result;
    result.position = 0; 

    int i = 0, j = 0;
    while (i < s1.position && j < s2.position)
    {
        if (s1.polynomialType[i].exponent == s2.polynomialType[j].exponent)
        {
            
            result.polynomialType[result.position].factor = s1.polynomialType[i].factor + s2.polynomialType[j].factor;
            result.polynomialType[result.position].exponent = s1.polynomialType[i].exponent;
            i++;
            j++;
        }
        else if (s1.polynomialType[i].exponent > s2.polynomialType[j].exponent)
        {
     
            result.polynomialType[result.position] = s1.polynomialType[i];
            i++;
        }
        else
        {
            
            result.polynomialType[result.position] = s2.polynomialType[j];
            j++;
        }
        result.position++;
    }
    while (i < s1.position){
        result.polynomialType[result.position] = s1.polynomialType[i];
        i++;
        result.position++;
    }
    while (j < s2.position){
        result.polynomialType[result.position] = s2.polynomialType[j];
        j++;
        result.position++;
    }

    return result;
}

polynomial derivative(polynomial poly){
    polynomial newPoly;
    newPoly.position = 0; // Khởi tạo đa thức mới với vị trí bằng 0
    
    for (int i = 0; i < poly.position; i++)
    {
        if (poly.polynomialType[i].exponent == 0){
            continue;
        }
        
        newPoly.polynomialType[newPoly.position].factor = poly.polynomialType[i].factor * poly.polynomialType[i].exponent;
        newPoly.polynomialType[newPoly.position].exponent = poly.polynomialType[i].exponent - 1;
        newPoly.position++;
    }
    return newPoly;
}