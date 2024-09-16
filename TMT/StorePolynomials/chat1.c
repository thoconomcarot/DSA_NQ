#include<stdio.h>
#include<math.h>

#define MaxLength 100

// Định nghĩa một đơn thức
typedef struct {
    float Coefficient;
    int Exponent;
} ElementType;

// Định nghĩa một danh sách đa thức
typedef struct {
    ElementType Elements[MaxLength];
    int Last;  // Lưu vị trí phần tử cuối
} List;

// Khởi tạo đa thức rỗng
void makenullList(List *pL) {
    pL->Last = 0;
}


// Thêm đơn thức vào đa thức
void insertTerm(float Coefficient, int Exponent, List *pL) {
    int i;
    // Tìm xem có đơn thức nào có cùng số mũ hay không
    for (i = 0; i < pL->Last; i++) {
        if (pL->Elements[i].Exponent == Exponent) {
            // Cộng hệ số nếu tìm thấy đơn thức có cùng số mũ
            pL->Elements[i].Coefficient += Coefficient;
            return;
        }
    }
    // Nếu không tìm thấy, thêm đơn thức mới
    pL->Elements[pL->Last].Coefficient = Coefficient;
    pL->Elements[pL->Last].Exponent = Exponent;
    pL->Last++;
}



// Đọc đa thức từ người dùng
void readList(List *pL) {
    makenullList(pL);
    int n, i;
    float coef;
    int exp;

    printf("Nhập số đơn thức: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Nhập hệ số và số mũ của đơn thức %d: ", i + 1);
        scanf("%f%d", &coef, &exp);
        insertTerm(coef, exp, pL);
    }
}

// In đa thức
void printList(List L) {
    for (int i = 0; i < L.Last; i++) {
        if (L.Elements[i].Coefficient > 0 && i > 0)
            printf("+");
        printf("%.1fx^%d ", L.Elements[i].Coefficient, L.Elements[i].Exponent);
    }
    printf("\n");
}

// Cộng hai đa thức
List addPolynomials(List L1, List L2) {
    List L;
    makenullList(&L);
    int i = 0, j = 0;

    // Cộng các đơn thức
    while (i < L1.Last && j < L2.Last) {
        if (L1.Elements[i].Exponent == L2.Elements[j].Exponent) {
            insertTerm(L1.Elements[i].Coefficient + L2.Elements[j].Coefficient, L1.Elements[i].Exponent, &L);
            i++; j++;
        } else if (L1.Elements[i].Exponent > L2.Elements[j].Exponent) {
            insertTerm(L1.Elements[i].Coefficient, L1.Elements[i].Exponent, &L);
            i++;
        } else {
            insertTerm(L2.Elements[j].Coefficient, L2.Elements[j].Exponent, &L);
            j++;
        }
    }

    // Thêm các đơn thức còn lại
    while (i < L1.Last) {
        insertTerm(L1.Elements[i].Coefficient, L1.Elements[i].Exponent, &L);
        i++;
    }
    while (j < L2.Last) {
        insertTerm(L2.Elements[j].Coefficient, L2.Elements[j].Exponent, &L);
        j++;
    }

    return L;
}

// Tính đạo hàm của đa thức
void derivative(List *pL) {
    for (int i = 0; i < pL->Last; i++) {
        if (pL->Elements[i].Exponent == 0) {
            pL->Elements[i].Coefficient = 0;  // Đơn thức có số mũ 0 thì đạo hàm bằng 0
        } else {
            pL->Elements[i].Coefficient *= pL->Elements[i].Exponent;
            pL->Elements[i].Exponent--;
        }
    }
    printf("Đạo hàm của đa thức là: ");
    printList(*pL);
}

int main() {
    List a, b;
    
    // Nhập và in đa thức thứ nhất
    readList(&a);
    printf("Đa thức thứ nhất: ");
    printList(a);
    
    // Nhập và in đa thức thứ hai
    readList(&b);
    printf("Đa thức thứ hai: ");
    printList(b);
    
    // Cộng hai đa thức và in kết quả
    List result = addPolynomials(a, b);
    printf("Tổng hai đa thức: ");
    printList(result);
    
    // Tính đạo hàm của đa thức kết quả và in ra
    derivative(&result);
    
    return 0;
}