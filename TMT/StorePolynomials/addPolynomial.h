#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 100

typedef int Position;
typedef struct{
    float coefficient; 
    int exponent;
}Monomial; //đơn thức: 3x^2, 2x, x

typedef struct{
    Monomial mono[MAXSIZE]; //mảng chứa các đơn thức
    int size; //lưu vị trí phần tử cuối cùng danh sách(số đơn thức trong ds)
} ListPolynomial; //đa thức: x + 2x^3 + 4x^2


//khởi tạo ds rỗng r thẩy đa thức tổng vào đây
void makeNull(ListPolynomial *L){
    L->size = 0;
}

int fullList(ListPolynomial L){
    return L.size == MAXSIZE;
}

Position first(ListPolynomial L){
    return 1;
}

Position endList(ListPolynomial L){
    return L.size+1;
}

//sắp xếp
void sortPolynomial(ListPolynomial *L) {
    for (int i = 0; i < L->size - 1; i++) {
        for (int j = 0; j < L->size - 1 - i; j++) {
            if (L->mono[j].exponent < L->mono[j + 1].exponent) {
                // Hoán đổi hai đơn thức nếu đơn thức phía sau có số mũ lớn hơn
                Monomial temp = L->mono[j];
                L->mono[j] = L->mono[j + 1];
                L->mono[j + 1] = temp;
            }
        }
    }
}



//thêm đơn thức vào đa thức
void insertPolynomial(float coefficient, int exponent, ListPolynomial *L){
    for (int i =0; i < L->size; i++){
        if (L->mono[i].exponent == exponent){
            L->mono[i].coefficient +=coefficient;
            return;
        }
    }
    //thêm hệ số và số ẩn vào vị trí cuối cùng của ds
    L->mono[L->size].coefficient = coefficient; 
    L->mono[L->size].exponent = exponent;
    L->size++;
}


//đọc đa thức
void readList(ListPolynomial *L){
    makeNull(L);
    int n;
    float coef; int expo;
    printf ("Enter the number of monomial: ");
    scanf ("%d", &n);

    for (int i =0; i < n; i++){
        printf ("\tEnter coefficient and exponent %d: ", i+1);
        scanf ("%f %d", &coef, &expo);
        insertPolynomial(coef, expo, L);
        
    }
}


//in đa thức
void printList(ListPolynomial L){
    for (int i =0; i < L.size; i++){
        if(L.mono[i].coefficient > 0 && i >0){
            printf (" + ");
        }
        printf ("%.1fx^%d ", L.mono[i].coefficient, L.mono[i].exponent);
    }
    printf ("\n");
}



//cộng 2 đa thức
ListPolynomial addPolynomial(ListPolynomial a1, ListPolynomial a2){
    ListPolynomial L;
    makeNull(&L);
    int p = 0, q = 0;
    while (p < a1.size && q < a2.size) {
        if (a1.mono[p].exponent == a2.mono[q].exponent) {
            insertPolynomial(a1.mono[p].coefficient + a2.mono[q].coefficient, a1.mono[p].exponent, &L);
            p++; q++;
        } else if (a1.mono[p].exponent > a2.mono[q].exponent) {
            insertPolynomial(a1.mono[p].coefficient, a1.mono[p].exponent, &L);
            p++;
        } else {
            insertPolynomial(a2.mono[q].coefficient, a2.mono[q].exponent, &L);
            q++;
        }
    }
    while (p < a1.size) {
        insertPolynomial(a1.mono[p].coefficient, a1.mono[p].exponent, &L);
        p++;
    }
    while (q < a2.size) {
        insertPolynomial(a2.mono[q].coefficient, a2.mono[q].exponent, &L);
        q++;
    }
     sortPolynomial(&L);
    return L;
}



//tính đạo hàm của tổng 2 đa thức
void derivative (ListPolynomial *L){
    for (int i =0; i < L->size; i++){
        if(L->mono[i].exponent == 0){
            L->mono[i].coefficient = 0;
        }
        else{
            L->mono[i].coefficient *= L->mono[i].exponent;
            L->mono[i].exponent--;
        }
    }
    printList(*L);
}
