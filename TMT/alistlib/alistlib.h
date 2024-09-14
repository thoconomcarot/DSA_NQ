#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
    
    typedef int Position;
    typedef int ElementTypes;
    
    typedef struct{
    ElementTypes elements[MAXSIZE];
    int size;
} List;

// List L;

void makeNull(List *L); //khởi tạo ds rỗng
int empty(List L); //ktra nó có rỗng
int fullList(List L); //ktra nó có bị đầy
void insertAt(Position p, int x, List *L); //Thêm x vào vị trí p
int popAt(Position p, List *L); //Xóa và trả về phần tử ở vị trí p
int insertFirst(int x, List *L); //Thêm x vào vị trí đầu tiên
int popFirst(Position p, List *L); //Xóa và trả về phần tử đầu tiên
int append(int x, List *L); //Thêm một ptu mới vào cuối ds
int popLast(List *L); //Xóa và trả về phần tử cuối cùng
int len(List L);
int first(List L);
int end(List L); //vị trí cuối cùng, sau last của danh sách
void setAt(Position p, int x, List *L); //Thay đổi phần tử ở vị trí p bằng một giá trị mới x
int getAt(Position p, List L); //trả về phần tử của vị trí thứ p
int locate(int x, List L); //Trả về vị trí xuất hiện đầu tiên của x trong danh sách
int next(Position p, List L); //Trả về vị trí tiếp của p trong danh sách
int previous(Position p, List L); //Trả về vị trí trước đó của p trong danh sách
void print(List L); //in ra
void sort(List *L); //Sắp xếp tăng dần

// trả về vị trí đầu tiên của ds
int first(List L){
    return 1;}


// trả về vị trí cuối cùng của ds
int end(List L){
    return L.size + 1;}


// Hàm tính độ dài các phần tử
int len(List L){
    return L.size;}    


// khai báo hàm rỗng //  a1,a2,a3... an => nếu n =0 thì danh sách rỗng
void makeNull(List *L){
    L->size = 0;}


// Hàm kiểm tra rỗng
int empty(List L){
    return L.size == 0;}


// check danh sách có đầy
int fullList(List L){
    return L.size == MAXSIZE; }


// Duyệt qua các danh sách để in ra tất cả phần tử
void print(List L){
    if (empty(L)){
        printf("List is empty!!!!");
    }
    if (fullList(L)){
        printf("List is full!!!");
    }
    for (int i = first(L); i < end(L); i++){
        printf("%d ", L.elements[i - 1]);
    }
}


// Thêm x vào vị trí đầu tiên
int insertFirst(ElementTypes x, List *L){
    if (fullList(*L)){
        printf("List is full!!");
    }
    else{
        insertAt(first(*L), x, L);
    }
}


// Xóa và trả về phần tử đầu tiên
int popFirst(Position p, List *L){
    popAt(first(*L), L);
    return getAt(first(*L), *L);
}


// trả về phần tử của vị trí thứ p
int getAt(Position p, List L){
    return L.elements[p - 1]; 
    // vị trí của ptu trong ds bắt đầu từ 0, theo thứ tự là từ 1 nên phải trừ ra
}


// Thay đổi phần tử ở vị trí p bằng một giá trị mới x
void setAt(Position p, ElementTypes x, List *L){
    if (p < 1 || p > len(*L)){
        printf("Error!!");
        return;
    }
    L->elements[p - 1] = x;
}


// Thêm x vào vị trí p
void insertAt(Position p, ElementTypes x, List *L){
    if (p < 1 || p > len(*L) + 1){
        printf("Error!!");
        return;
    }
    else if (fullList(*L)){
        printf("List is full!!\n");
        return;
    }
    for (int i = L->size; i >= p; i--){
        L->elements[i] = L->elements[i - 1];
    }
    L->elements[p - 1] = x;
    L->size++;
}


// Xóa và trả về phần tử ở vị trí p
int popAt(Position p, List *L){
    int a = L->elements[p - 1];
    for (int i = first(*L) - 1; i < end(*L); i++){ // first(L)-1 = 0
        L->elements[i] = L->elements[i + 1];
        L->size--;
    }
    return a;
}


// Thêm một ptu mới vào ds
int append(ElementTypes x, List *L){
    if (fullList(*L)){
        printf("Error!!");
    }
    else{
        L->elements[L->size] = x;
        L->size++;
    }
}


// Xóa và trả về phần tử cuối cùng
int popLast(List *L){
    popAt(end(*L), L);
    return getAt(end(*L), *L);
}


// Trả về vị trí xuất hiện đầu tiên của x trong danh sách
int locate(ElementTypes x, List L){
    for (int i = 0; i <= L.size - 1; i++){
        if (L.elements[i] == x) {
            return i;
        }
    }
}


// Trả về vị trí tiếp của p trong danh sách
int next(Position p, List L){
    return p + 1;
}


// Trả về vị trí trước đó của p trong danh sách
int previous(Position p, List L){
    return p - 1;
}

void swap (ElementTypes *x, ElementTypes *y){
		ElementTypes temp = *x;
        *x = *y;
        *y = temp;
}


//Viet ham sap xep tang dan
void sort(List *L){
	Position p = first(*L), e = end(*L), q;
	while(p != e){
		q = next(p, *L);
		while(q != e){
			if(getAt(p,*L) > getAt(q,*L))
				swap (&L->elements[p-1], &L->elements[q-1]);
			q = next(q, *L);
		}
		p = next(p, *L);
	}
}

// int main (){
//     List L;
//     makeNull(&L);

//     int n;
//     printf ("Nhap vao so luong phan tu cua ds: ");
//     scanf ("%d", &n);

//     printf ("Nhap cac phan tu: ");
//     for (int i = 1; i <=n ;i++){
//         int x; scanf("%d", &x);
//         insertAt(i, x, &L);
//     }

//     print(L);
//     printf ("\n");
//     sort(&L);
//     print(L);
//     return 0;

// }

