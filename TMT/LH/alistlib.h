
#include <stdio.h>
#include <stdlib.h>

// the maximum size of list
#define MaxLength 100
// the element type of list
typedef int ElementType;
// the position type of elements
typedef int Position;

typedef struct
{
    ElementType Elements[MaxLength]; // mảng bao gồm các phần tử của danh sách
    Position Last;                   // độ dài của danh sách
} List;

List L;

void makeNull(List *L); // KHỞI TẠO DANH SÁCH RỖNG

int len(List L); // trả về đồ dài ds

int empty(List L); // KIỂM TRA DANH SÁCH RỖNG

int fullList(List L); // KIỂM TRA DANH SÁCH ĐẦY

Position first(List L); // trả về vị trí đầu tiên trong danh sách

Position endList(List L); // trả về vị trí cuối danh sách

Position next(Position P, List L); // trả về vị trí kế tiếp

ElementType getAt(Position P, List L); // Trả về phần tử ở vị trí p

void print(List L); // Duyệt qua danh sách để in ra tất cả các phần tử

void setAt(Position P, ElementType x, List *L); // Thay đổi phần tử ở vị trí p bằng một giá trị mới x

void insertAt(Position P, ElementType X, List *L); // Thêm x vào vị trí p

ElementType popAt(Position P, List *L); // Xóa và trả về phần tử ở vị trí p

int insertFirst(ElementType x, List *L); // Thêm x vào vị trí đầu tiên

void popFirst(List *L); // Xóa và trả về phần tử đầu tiên

void append(ElementType x, List *L); // Thêm một phần tử mới vào cuối ds

void popLast(List *L); // Xóa và trả về phần tử cuối cùng

Position locate(ElementType x, List L); // Trả về vị trí xuất hiện đầu tiên của x trong danh sách

Position previous(Position p, List L); // Trả về vị trí trước đó của p trong danh sách

void swap(ElementType x, ElementType y, List *L); // thay đổi vị trí trong mảng

void sort(List *L);

// KHỞI TẠO DANH SÁCH RỖNG
void makeNull(List *L)
{
    L->Last = 0;
    // (*L).Last=0;
}

// trả về đồ dài ds
int len(List L)
{
    return L.Last;
}

// KIỂM TRA DANH SÁCH RỖNG
int empty(List L)
{
    return L.Last == 0;
}

// KIỂM TRA DANH SÁCH ĐẦY
int fullList(List L)
{
    return L.Last == MaxLength;
}

// trả về vị trí đầu tiên trong danh sách
int first(List L)
{
    return 1;
}

// trả về vị trí cuối danh sách
int endList(List L)
{
    return L.Last + 1;
}

// trả về vị trí kế tiếp
int next(Position P, List L)
{
    return P + 1;
}

// Trả về phần tử ở vị trí p
int getAt(Position P, List L)
{
    return L.Elements[P - 1];
}

// Duyệt qua danh sách để in ra tất cả các phần tử
void print(List L)
{
    if (empty(L))
    {
        printf("List is empty!!!!");
    }
    if (fullList(L))
    {
        printf("List is full!!!");
    }
    for (int i = first(L); i < endList(L); i++)
    {
        printf("%d ", L.Elements[i - 1]);
    }
}

// Thay đổi phần tử ở vị trí p bằng một giá trị mới x
void setAt(Position P, ElementType x, List *L)
{
    if (P < 1 || P > len(*L))
    {
        printf("Error!!!\n");
        return;
    }
    L->Elements[P - 1] = x;
}

// Thêm x vào vị trí p
void insertAt(Position P, ElementType X, List *L)
{
    if (fullList(*L))
    {
        printf("List is full!!");
        return;
    }
    else if ((P < 1) || (P > L->Last + 1))
    {
        printf("Error!!!");
        return;
    }
    else
    {
        for (int i = L->Last; i >= P; i--) // Dời các phtử từ vị trí p đến cuối dsách ra sau 1 vị trí
        {
            L->Elements[i] = L->Elements[i - 1]; // Đưa x vào vị trí p
        }
        L->Elements[P - 1] = X;
        L->Last++; // Tăng độ dài danh sách lên 1
    }
}

// Xóa và trả về phần tử ở vị trí p
int popAt(Position P, List *L)
{
    if (empty(*L))
        printf("List is full!!\n");
    else if ((P < 1) || (P > L->Last))
        printf("Error!!\n");
    else
    {
        int a = L->Elements[P - 1];
        for (int i = first(*L) - 1; i < endList(*L); i++)
        { // first(L)-1 = 0
            L->Elements[i] = L->Elements[i + 1];
            L->Last--;
        }
        return a;
    }
}

// Thêm x vào vị trí đầu tiên
int insertFirst(ElementType x, List *L)
{
    if (fullList(*L))
    {
        printf("List is full!!");
    }
    else
    {
        insertAt(first(*L), x, L); // Chèn phần tử x vào vị trí đầu tiên
    }
}

// Xóa và trả về phần tử đầu tiên
void popFirst(List *L)
{
    popAt(first(*L), L);
}

// Thêm một phần tử mới vào cuối ds
void append(ElementType x, List *L)
{
    if (fullList(*L)) // Kiểm tra danh sách có đầy không
        printf("Danh sách đầy!\n");
    else
    {
        L->Elements[L->Last] = x;
        L->Last++;
    }
}

// Xóa và trả về phần tử cuối cùng
void popLast(List *L)
{
    popAt(L->Last, L); // Xóa phần tử cuối cùng
}

// Trả về vị trí xuất hiện đầu tiên của x trong danh sách
Position Locate(ElementType X, List L)
{
    for (int i = 0; i <= L.Last - 1; i++)
    {
        if (L.Elements[i] == X)
        {
            return i;
        }
    }
}

Position locate(ElementType x, List L)
{
    Position p;
    int found = 0;
    for (p = first(L); p < endList(L) && !found; p++)
        if (L.Elements[p - 1] == x)
            found = 1;
    return p;
}

// Trả về vị trí trước đó của p trong danh sách
Position previous(Position p, List L)
{
    return p - 1;
}

// void swap(Position p, Position q, List *L)
// {
//     ElementType temp;
//     temp = getAt(p, *L);
//     setAt(p, getAt(q, *L), L);
//     setAt(q, temp, L);
// }

// // bubbleSort
// void bubbleSort(List *L)
// {
//     int size = len(*L);
//     for (int i = first(*L); i < size; i++)
//     {
//         for (int j = first(*L); j <= size - i; j++)
//         {
//             if (getAt(j, *L) > getAt(j + 1, *L))
//             {
//                 swap(j, j + 1, L);
//             }
//         }
//     }
// }
