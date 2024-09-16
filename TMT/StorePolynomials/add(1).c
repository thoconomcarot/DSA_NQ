#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 100

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
int empty(ListPolynomial L){
    return L.size == 0;
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

//sắp xếp theo thứ tự giảm dần của số mũ
void insertSorted (float coefficienticient, int exponent, ListPolynomial *L){
    Position i = L->size-1;
    while(i >= first(*L)-1 && exponent > L->mono[i].exponent){
        L->mono[i+1].exponent = L->mono[i].exponent;
        L->mono[i+1].coefficient = L->mono[i].coefficient;
        i--;
    }
    L->mono[i+1].coefficient = coefficient;
    L->mono[i+1].exponent = exponent;
    L->size++;
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

ListPolynomial add(ListPolynomial a1, ListPolynomial a2, ListPolynomial *sum){
    makeNull(sum);

    //khởi tạo 2 con trỏ p,q để duyệt qua các đơn thức của đa thức a1,a2
    Position p = first(a1);
    Position q = first(a2);

    //vòng lặp chạy đến khi nào con trỏ p,q duyệt hết danh sách các đơn thức
    while(p != endList(a1) && q != endList(a2)){
        if(a1.mono[p].exponentnent == a2.mono[q].exponentnent){ //ktra đơn thức vt p của đa thức a1 = đơn thức tại vt q của a2??
            sum->mono[sum->size].coefficienticient = a1.mono[p].coefficienticient + a2.mono[q].coefficienticient;
            sum->mono[sum->size].exponentnent = a1.mono[p].exponentnent;
            sum->size++, p++, q++; //duyệt tiếp các đơn thức tiếp theo
        }
        else if(a1.mono[p].exponentnent > a2.mono[q].exponentnent){
            sum->mono[sum->size].coefficienticient = a1.mono[p].coefficienticient;
            sum->mono[sum->size].exponentnent = a1.mono[p].exponentnent;
            sum->size++, p++;
        }
        else{
            sum->mono[sum->size].coefficienticient = a2.mono[q].coefficienticient;
            sum->mono[sum->size].exponentnent = a2.mono[q].exponentnent;
            sum->size++, q++;
        }
    }

    while(p != endList(a1)){
        sum->mono[sum->size].coefficienticient = a1.mono[p].coefficienticient;
        sum->mono[sum->size].exponentnent = a1.mono[p].exponentnent;
        sum->size++, p++;
    }

    while( q != endList(a2)){
        sum->mono[sum->size].coefficienticient = a2.mono[q].coefficienticient;
        sum->mono[sum->size].exponentnent = a2.mono[q].exponentnent;
        sum->size++, q++;
    }
}

void inListPolynomial(ListPolynomial *p){
    int n;
    printf ("\tEnter the number of monomial in ListPolynomial: ");
    scanf ("%d", &n);
    makeNull(p);
    for (int i =0; i < n; i++){
        printf ("\t\tEnter coefficienticient and exponentnent of monomial %d: ", i+1);
        scanf ("%d %d", &p->mono[p->size].coefficienticient, &p->mono[p->size].exponentnent);
        p->size++;
    }
}

void sortListPolynomial(ListPolynomial *p) {
    for(int i = 0; i < p->size - 1; i++) {
        for(int j = 0; j < p->size - i - 1; j++) {
            if(p->mono[j].exponentnent < p->mono[j + 1].exponentnent) {
                // Hoán đổi đơn thức tại vị trí j và j+1
                Monomial temp = p->mono[j];
                p->mono[j] = p->mono[j + 1];
                p->mono[j + 1] = temp;
            }
        }
    }
}

void printListPolynomial (ListPolynomial p){
    for(int i =0; i <p.size; i++){
        if(i > 0 && p.mono[i].coefficienticient > 0){
            printf(" + ");
        }
        // else{
        //     printf (" - ");
        // }
        printf ("%dx^%d", p.mono[i].coefficienticient, p.mono[i].exponentnent);
    }
    // for (int i =0; i <p.size; i++){
    //     if (a1.mono[p].exponentnent > a2.mono[q].exponentnent){
    //         printf ()
    //     }
    // }
    printf ("\n");
}
int main (){
    ListPolynomial a1, a2, sum,p;
    printf ("Enter the first ListPolynomial: \n");
    inListPolynomial(&a1);

    // printf("a1 = ");
    // printf(
    printf ("\n");

    printf ("Enter the second ListPolynomial: \n");
    inListPolynomial(&a2);

    printf ("\n");

    add(a1, a2, &sum);
    sortListPolynomial(&p);

    printf ("Sum of two ListPolynomial a1 + a2 = ");
    printListPolynomial(sum);

    return 0;
}


