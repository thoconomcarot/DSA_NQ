#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE_LIST 100
#define MAXSIZE_EXPONENT 10

typedef int Position;
typedef struct{
    float coefficient; 
    int exponent;
} Monomial; //đơn thức: 3x^2, 2x, x

typedef struct{
    Polynomial mono[MAXSIZE]; //mảng chứa các đơn thức
    Position size; //số lượng đơn thức 
} Polynomial; //đa thức: x + 2x^3 + 4x^2

//khởi tạo ds rỗng r thẩy đa thức tổng vào đây
 void makeNull(Polynomial *L){
    L->size = 0;
}

Position first(Polynomial L){
    return 0;
}

Position endList(Polynomial L){
    return L.size;
}

Polynomial add(Polynomial a1, Polynomial a2, Polynomial *sum){
    makeNull(sum);
    //khởi tạo 2 con trỏ p,q để duyệt qua các đơn thức của đa thức a1,a2
    Position p = first(a1);
    Position q = first(a2);

    //vòng lặp chạy đến khi nào con trỏ p,q duyệt hết danh sách các đơn thức
    while(p != endList(a1) && q != endList(a2)){
        if(a1.mono[p].exponent == a2.mono[q].exponent){ //ktra đơn thức vt p của đa thức a1 = đơn thức tại vt q của a2??
            int sumCoeff = a1.mono[p].coefficient + a2.mono[q].coefficient;
            if(sumCoeff != 0){ // Bỏ qua nếu tổng hệ số là 0
                sum->mono[sum->size].coefficient = sumCoeff;
                sum->mono[sum->size].exponent = a1.mono[p].exponent;
                sum->size++; 
            }
            p++, q++; //duyệt tiếp các đơn thức tiếp theo
        }
        else if(a1.mono[p].exponent > a2.mono[q].exponent){
            sum->mono[sum->size].coefficient = a1.mono[p].coefficient;
            sum->mono[sum->size].exponent = a1.mono[p].exponent;
            sum->size++, p++;
        }
        else{
            sum->mono[sum->size].coefficient = a2.mono[q].coefficient;
            sum->mono[sum->size].exponent = a2.mono[q].exponent;
            sum->size++, q++;
        }
    }

    while(p != endList(a1)){
        sum->mono[sum->size].coefficient = a1.mono[p].coefficient;
        sum->mono[sum->size].exponent = a1.mono[p].exponent;
        sum->size++, p++;
    }

    while(q != endList(a2)){
        sum->mono[sum->size].coefficient = a2.mono[q].coefficient;
        sum->mono[sum->size].exponent = a2.mono[q].exponent;
        sum->size++, q++;
    }
}

void readPolynomial(Polynomial *p){
    int n;
    printf ("\tEnter the number of monomial in Polynomial: ");
    scanf ("%d", &n);
    makeNull(p);
    for (int i = 0; i < n; i++){
        printf ("\t\tEnter coefficient and exponent of monomial %d: ", i+1);
        scanf ("%d %d", &p->mono[p->size].coefficient, &p->mono[p->size].exponent);
        p->size++;
    }
}

void sortPolynomial(Polynomial *p) {
    for(int i = 0; i < p->size - 1; i++) {
        for(int j = 0; j < p->size - i - 1; j++) {
            if(p->mono[j].exponent < p->mono[j + 1].exponent) {
                // Hoán đổi đơn thức tại vị trí j và j+1
                Monomial temp = p->mono[j];
                p->mono[j] = p->mono[j + 1];
                p->mono[j + 1] = temp;
            }
        }
    }
}

void printPolynomial(Polynomial p){
    for(int i = 0; i < p.size; i++){
        if(i > 0 && p.mono[i].coefficient > 0){
            printf(" + ");
        }
        printf ("%dx^%d", p.mono[i].coefficient, p.mono[i].exponent);
    }
    printf ("\n");
}

int main (){
    Polynomial a1, a2, sum;
    printf ("Enter the first polynomial: \n");
    inPolynomial(&a1);
    printf ("\n");

    printf ("Enter the second polynomial: \n");
    inPolynomial(&a2);
    printf ("\n");

    add(a1, a2, &sum);
    sortPolynomial(&sum); // Sort the result

    printf ("Sum of two polynomial a1 + a2 = ");
    printPolynomial(sum);

    return 0;
}