#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef int Position;

typedef struct NodeTag
{
    ElementType data;
    struct NodeTag *next;
} Node;

typedef Node *List;
typedef Node *PNode;

void makeNull(List *L);                                   
                        
int len(List L);

int empty(List L);      

int fullList(List L);

ElementType getAt(Position P, List L);    //trả về ptu ở vị trí p        

void print(List L);

PNode getPosition(Position P, List L);       //trả về con trỏ trỏ đến ptu i

PNode first(List L);

PNode end(List L);                                        

void setAt(Position P, ElementType x, List *L);  //thay đổi ptu ở vị trí p bằng 1 gtri mới

void insertAt(Position P, ElementType x, List *L);        
                        
ElementType popAt(Position P, List *L);

void insertFirst(ElementType x, List *L);                 
                        
ElementType popFirst(List *L);

void append(ElementType x, List *L);                      

ElementType popLast(List *L);   

Position locate(ElementType x, List L);          //trả về vị trí xuất hiện đầu tiên của x         

PNode next(Position P, List L);                       

PNode previous(Position P, List L);

// 1. khởi tạo ds rỗng
void makeNull(List *L)
{
    Node *header = (Node *)malloc(sizeof(Node));
    header->next = NULL;
    (*L) = header;
}


// 2. tính độ dài của danh sách
int len(List L)
{
    List header = L;
    int count = 0;
    while (header != NULL)
    {
        count++;
        header = header->next;
    }
    return count;
}


// 3. check danh sách rỗng
int empty(List L)
{
    return L->next == NULL;
}

// 4. check danh sách đầy
int fullList(List L){
// trả về phần tử ở vị trí p
//  int retrieve(Position header, List L){
//      if(header->next != NULL){
//          return header->next->data;
//      }
}


// 5. Trả về giá trị ở vị trí p
int getAt(Position P, List L)
{
    int n = len(L);
    if(P < 1 || P > n){
        printf ("Invalid position!\n");
        return -1;
    }

    List temp = L;
    for (int i = 1; i < P; i++)
    {
        temp = temp->next;
        }
    return temp->data;
}


// 6. in ra danh sách
void print(List L)
{
    List header = L;
    while (header->next != NULL)
    {
        printf("%d", header->next->data);
        header = header->next;
    }
    printf("\n");
}


// 7. Trả về con trỏ trỏ đến vị trí p trong ds
PNode getPosition(Position P, List L)
{
    int n = len(L);
    if(P < 1 || P > n){
        printf ("Invalid position!\n");
        return NULL;
    }

    PNode header = L;
    for(int i = 1; i < P; i++){
        header = header->next;
    }
    return header;
}

// 8. trả về vị trí đầu tiên
PNode first(List L)
{
    List header = L;
    return header;
}


// 9. trả về vị trí cuối cùng
PNode end(List L)
{
    PNode header = L;
    while (header->next != NULL)
    {
        header = header->next;
    }
    return header;
}


// 10. Thay đổi phần tử ở vị trí p bằng 1 giá trị x mới
void setAt(Position P, ElementType x, List *L)
{
    PNode change = getPosition(P, *L);
    if (change != NULL)
    {
        change->data = x;
    }
}


// 11. Thêm vào vị trí bất kỳ
void insertAt(Position P, ElementType x, List *L)
{
    List header = (Node *)malloc(sizeof(Node));
    header->data = x;
    List temp = *L;
    for (int i = 1; i < P; i++)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        header->next = temp->next;
        temp->next = header;
    }
}


// 12. Xóa vị trí bất kỳ
ElementType popAt(Position P, List *L)
{
    if (*L == NULL || P <= 0)
    {
        printf ("Invalid position!\n");
        return -1; // Vị trí không hợp lệ
    }
    List temp = *L; // khai báo biến tạm lưu cả ds
    for (int i = 1; i < P - 1; i++)
    {                      // cho P = 3
        temp = temp->next; // nếu i = 1 < 2 thì temp dịch sang phần tử tiếp theo
    }
    if (temp->next == NULL)
    {
        return -1; // Vị trí không tồn tại
    }

    List del = temp->next;
    ElementType data = del->data;
    temp->next = del->next;
    free(del); // xóa
    return data;
}


// 13. Thêm vào vị trí đầu tiên
void insertFirst(ElementType x, List *L)
{
    List header = (Node *)malloc(sizeof(Node));
    header->data = x;          // gán gtri cho node mới
    header->next = (*L)->next; // cho node mới trỏ đến node đầu của ds
    (*L)->next = header;       // cập nhật lại ds sau khi đã thêm node mới
}


// 14. Xóa vị trí đầu tiên
ElementType popFirst(List *L)
{
    if (*L == NULL)
    {
        return -1; // Danh sách rỗng
    }
    List temp = (*L);  //ds hiện tại
    ElementType data = (*L)->next->data;
    (*L) = (*L)->next; //cập nhật ds để bỏ qua phần tử đầu tiên
    free(temp);
    return data;
}



// 15. Thêm 1 phần tử mới vào cuối danh sách
void append(ElementType x, List *L)
{
    insertAt(len(*L), x, L);
}



// 16. Xóa vị trí cuối cùng
ElementType popLast(List *L)
{
    if (*L == NULL || (*L)->next == NULL)
    {
        return -1; // Danh sách rỗng
    }
    ElementType value;
    PNode temp = *L;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    value = temp->next->data;
    popAt(len(*L), L);
}


// 17. trả về vị trí xuất hiện đầu tiên của x
Position locate(ElementType x, List L)
{
    List temp = L->next;
    int count = 1;
    while (temp != NULL)
    {
        if (x == temp->data)
        {
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}


// 18. trả về con trỏ trỏ đến vị trí kế tiếp của i trong ds
PNode next(Position P, List L)
{
    if (P < 1 || P > len(L))
    {
        printf("Invalid position!\n");
        return NULL;
    }
    PNode temp = getPosition(P,L);
    if(temp != NULL){
        return temp->next;
    }
    return NULL;
}



// 19. Trả về con trỏ tham chiếu đến vị trí trước đó của p trong L
PNode previous(Position P, List L)
{
    List temp = L;
    for (int i = 1; i < P - 1; i++)
    {
        temp = temp->next;
    }
    return temp;
}

// int main()
// {
//     int n;
//     List L;
//     makeNull(&L); // Khởi tạo danh sách rỗng

//     printf("Nhập giá trị cần thêm: ");
//     scanf("%d", &n);

//     insertFirst(n, &L);
//     print(L);

//     return 0;
// }
