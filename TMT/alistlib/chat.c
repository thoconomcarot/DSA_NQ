#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef int Position;
typedef int ElementTypes;

typedef struct {
    ElementTypes elements[MAXSIZE];
    int size;
} List;

// Trả về vị trí đầu tiên của danh sách
int first(List L) {
    return 1;
}

// Trả về vị trí cuối cùng của danh sách
int end(List L) {
    return L.size + 1;
}

// Khai báo hàm rỗng
void makeNull(List *L) {
    L->size = 0;
}

// Hàm tính độ dài các phần tử
int len(List L) {
    return L.size;
}

// Hàm kiểm tra rỗng
int empty(List L) {
    return L.size == 0;
}

// Kiểm tra danh sách có đầy
int fullList(List L) {
    return L.size == MAXSIZE;
}

// Duyệt qua các danh sách để in ra tất cả phần tử
void print(List L) {
    if (empty(L)) {
        printf("List is empty!!!!\n");
    }
    if (fullList(L)) {
        printf("List is full!!!\n");
    }
    for (int i = first(L); i < end(L); i++) {
        printf("%d ", L.elements[i-1]);
    }
    printf("\n");
}

// Trả về phần tử của vị trí thứ p
int getAt(Position p, List L) {
    return L.elements[p-1];
}

// Thay đổi phần tử ở vị trí p bằng một giá trị mới x
void setAt(Position p, int x, List *L) {
    if (p < 1 || p > len(*L)) {
        printf("Error!!\n");
        return;
    }
    L->elements[p-1] = x;
}

// Thêm x vào vị trí p
void insertAt(Position p, int x, List *L) {
    if (p < 1 || p > len(*L) + 1) {
        printf("Error!!\n");
        return;
    } else if (fullList(*L)) {
        printf("List is full!!\n");
        return;
    }
    for (int i = L->size; i >= p; i--) {
        L->elements[i] = L->elements[i-1];
    }
    L->elements[p-1] = x;
    L->size++;
}

// Xóa và trả về phần tử ở vị trí p
int popAt(Position p, List *L) {
    int removedElement = L->elements[p-1];
    for (int i = p; i < L->size; i++) {
        L->elements[i-1] = L->elements[i];
    }
    L->size--;
    return removedElement;
}

// Thêm x vào vị trí đầu tiên
void insertFirst(int x, List *L) {
    insertAt(first(*L), x, L);
}

// Xóa và trả về phần tử đầu tiên
int popFirst(List *L) {
    return popAt(first(*L), L);
}

// Thêm một phần tử mới vào danh sách
void append(int x, List *L) {
    if (fullList(*L)) {
        printf("List is full!!\n");
    } else {
        L->elements[L->size] = x;
        L->size++;
    }
}

// Xóa và trả về phần tử cuối cùng
int popLast(List *L) {
    return popAt(end(*L) - 1, L);
}

// Trả về vị trí xuất hiện đầu tiên của x trong danh sách
int locate(int x, List L) {
    for (int i = 0; i < L.size; i++) {
        if (L.elements[i] == x) {
            return i + 1;
        }
    }
    return -1;  // Không tìm thấy x
}

// Trả về vị trí tiếp của p trong danh sách
int next(Position p, List L) {
    return p + 1;
}

// Trả về vị trí trước đó của p trong danh sách
int previous(Position p, List L) {
    return p - 1;
}

int main() {
    List L;
    makeNull(&L);

    int n;
    printf("Nhap vao so luong phan tu cua ds: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu: ");
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        insertAt(i, x, &L);
    }

    print(L);

    return 0;
}
