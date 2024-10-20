#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000

typedef int Position;
typedef int ElementType;

typedef struct
{
    ElementType Elements[MaxSize];
    Position size;
} List;

void makeNull(List *L); // khởi tạo ds rỗng
int len(List L);
int empty(List L);                     // ktra nó có rỗng
int fullList(List L);                  // ktra nó có bị đầy
void print(List L);                    // in ra
ElementType getAt(Position p, List L); // trả về phần tử của vị trí thứ p
Position first(List L);
Position endList(List L);                          // vị trí cuối cùng, sau last của danh sách
void setAt(Position p, ElementType x, List *L);    // Thay đổi phần tử ở vị trí p bằng một giá trị mới x
void insertAt(Position p, ElementType x, List *L); // Thêm x vào vị trí p
ElementType popAt(Position p, List *L);            // Xóa và trả về phần tử ở vị trí p
void insertFirst(ElementType x, List *L);          // Thêm x vào vị trí đầu tiên
ElementType popFirst(List *L);                     // Xóa và trả về phần tử đầu tiên
void append(ElementType x, List *L);               // Thêm một ptu mới vào cuối ds
ElementType popLast(List *L);                      // Xóa và trả về phần tử cuối cùng
Position locate(ElementType x, List L);            // Trả về vị trí xuất hiện đầu tiên của x trong danh sách
Position next(Position p, List L);                 // Trả về vị trí tiếp của p trong danh sách
Position previous(Position p, List L);             // Trả về vị trí trước đó của p trong danh sách

// khai báo hàm rỗng //  a1,a2,a3... an => nếu n =0 thì danh sách rỗng
void makeNull(List *L)
{
    L->size = 0;
}

// Hàm tính độ dài các phần tử
int len(List L)
{
    return L.size;
}

// Hàm kiểm tra rỗng
int empty(List L)
{
    return L.size == 0;
}

// check danh sách có đầy
int fullList(List L)
{
    return L.size == MaxSize;
}

// Duyệt qua các danh sách để in ra tất cả phần tử
void print(List L)
{
    int fs = first(L);
    int end = endList(L);
    if (empty(L))
    {
        return;
    }
    if (fullList(L))
    {
        return;
    }
    for (int i = fs; i < end; i++)
    {
        printf("%d ", L.Elements[i - 1]);
    }
    printf("\n");
}

// trả về phần tử của vị trí thứ p
ElementType getAt(Position p, List L)
{
    return L.Elements[p - 1];
    // vị trí của ptu trong ds bắt đầu từ 0, theo thứ tự là từ 1 nên phải trừ ra
}

// trả về vị trí đầu tiên của ds
Position first(List L)
{
    return 1;
}

// trả về vị trí cuối cùng của ds
Position endList(List L)
{
    return L.size + 1;
}

// Thay đổi phần tử ở vị trí p bằng một giá trị mới x
void setAt(Position p, ElementType x, List *L)
{
    if (p < 1 || p > len(*L))
    {
        return;
    }
    L->Elements[p - 1] = x;
}

// Thêm x vào vị trí p
void insertAt(Position p, ElementType x, List *L)
{
    if (p < 1 || p > L->size + 1)
    {
        return;
    }
    else if (fullList(*L))
    {
        return;
    }
    for (int i = L->size; i >= p; i--)
    {
        L->Elements[i] = L->Elements[i - 1];
    }
    L->Elements[p - 1] = x;
    L->size++;
}

// Xóa và trả về phần tử ở vị trí p
ElementType popAt(Position p, List *L)
{
    if (empty(*L))
    {
        return -1; // trả về gt không hợp lệ
    }
    if (p < 1 || p > L->size)
    {
        return -1;
    }
    ElementType a = L->Elements[p - 1];
    for (int i = p - 1; i < L->size - 1; i++)
    { // first(L)-1 = 0
        L->Elements[i] = L->Elements[i + 1];
        L->size--;
    }
    return a;
}

// Thêm x vào vị trí đầu tiên
void insertFirst(ElementType x, List *L)
{
    if (fullList(*L))
    {
        return;
    }
    else
    {
        insertAt(first(*L), x, L);
        return;
    }
}

// Xóa và trả về phần tử đầu tiên
ElementType popFirst(List *L)
{
    int res = popAt(first(*L), L);
    return res;
    
}

// Thêm một ptu mới vào ds
void append(ElementType x, List *L)
{
    if (fullList(*L))
    {
        return;
    }
    else
    {
        L->Elements[L->size] = x;
        L->size++;
    }
}

// Xóa và trả về phần tử cuối cùng
ElementType popLast(List *L)
{
    int res = popAt(L->size, L);
    return res;
}

// Trả về vị trí xuất hiện đầu tiên của x trong danh sách
Position locate(ElementType x, List L)
{
    for (Position p = first(L); p < endList(L); p++)
    {
        if (L.Elements[p - 1] == x)
        {
            return p;
        }
    }
    return -1;
}

// Trả về vị trí tiếp của p trong danh sách
Position next(Position p, List L)
{
    return p + 1;
}

// Trả về vị trí trước đó của p trong danh sách
Position previous(Position p, List L)
{
    return p - 1;
}
