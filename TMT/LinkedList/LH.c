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

void makeNull(List *L); // KHỞI TẠO DANH SÁCH RỖNG

int len(List L); // trả về đồ dài ds

int empty(List L); // KIỂM TRA DANH SÁCH RỖNG

int fullList(List L); // KIỂM TRA DANH SÁCH ĐẦY

ElementType getAt(Position P, List L); // Trả về phần tử ở vị trí p

void print(List L); // Duyệt qua danh sách để in ra tất cả các phần tử

PNode getPosition(Position p, List L); // Trả về con trỏ trỏ đến phần tử thứ i

PNode first(List L); // trả về vị trí đầu tiên trong danh sách

PNode end(List L); // trả về vị trí cuối danh sách

void setAt(Position p, ElementType x, List *L); // Cập nhật phần tử ở vị trí p bằng một giá trị mới

void insertAt(Position p, ElementType x, List *L); // Thêm vào vị trí bất kỳ

ElementType popAt(Position p, List *L); // Xóa và trả về phần tử ở vị trí p

void insertFirst(ElementType x, List *L); // Chèn x vào vị trí đầu tiên

ElementType popFirst(List *L); // Xóa và trả về phần tử đầu tiên

void append(ElementType x, List *L); // Thêm một phần tử mới vào danh sách

ElementType popLast(List *L); // Xóa và trả về phần tử cuối cùng

Position locate(ElementType x, List L); // Trả về vị trí xuất hiện đầu tiên của x trong danh sách

PNode next(Position p, List L); // Trả về vị trí xuất hiện đầu tiên của x trong danh sách

PNode previous(Position p, List L); // Trả về con trỏ trỏ đến vị trí trước đó của p trong L

/*
Initialize an empty list
*/
void makeNull(List *L)
{
  Node *header = (Node *)malloc(sizeof(Node)); // cấp phát động cho phần tử mới
  header->next = NULL;                         // cho phần tử mới next = NULL
  (*L) = header;
}

/*
return Number of elements
*/
int len(List L)
{
  int count = 0;
  List P = L;
  while (P != NULL)
  {
    count++;
    P = P->next;
  }
  return count;
}

/*
Check whether the list is empty?
*/
int empty(List L)
{
  return L->next == NULL; // Kiểm tra danh sách có rỗng không
}

/*
Check whether the list is full?
*/
int fullList(List L)
{ // bỏ trống
}

/*
Traverse the list to print out all elements
*/
// void print(List L) {
//     List header = L->next; // Bắt đầu từ phần tử đầu tiên
//     while (header != NULL) {
//         printf("%d ", header->data);
//         header = header->next;
//     }
//     printf("\n");
// }

void print(List L)
{
  List header = L->next; // Bắt đầu từ phần tử đầu tiên
  while (header != NULL)
  {
    printf("%d ", header->data);
    header = header->next;
  }
  printf("\n");
}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L)
{
  int n = len(L); // Khai báo và tính độ dài của danh sách
  if (p < 1 || p > n)
  {
    printf("Vị trí không hợp lệ\n");
    return -1;
  }

  List temp = L;
  for (int i = 1; i < p; i++)
  {
    temp = temp->next;
  }
  return temp->data;
}

/*
Return the pointer referring to the ith element
*/
PNode getPosition(Position p, List L)
{
  int n = len(L); // Khai báo và tính độ dài danh sách
  if (p < 1 || p > n)
  {
    printf("Vị trí không hợp lệ\n");
    return NULL;
  }

  PNode newHead = L;
  for (int i = 1; i < p; i++)
  {
    newHead = newHead->next;
  }
  return newHead;
}

/*
Return the pointer referring to the first element of L
*/
PNode first(List L)
{
  List header = L;
  return header;
}

/*
Return the pointer referring to the last element of L
*/
PNode end(List L)
{
  PNode P = L;
  while (P->next != NULL)
  {
    P = P->next;
  }
  return P;
}

/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x, List *L)
{
  PNode posi = getPosition(p, *L);
  if (posi != NULL)
  {
    posi->data = x;
  }
}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L)
{
  List newNode = (Node *)malloc(sizeof(Node));
  newNode->data = x;
  List temp = *L;
  for (int i = 1; i < p; i++) // p-1
  {
    temp = temp->next;
  }
  if (temp != NULL)
  {
    newNode->next = temp->next;
    temp->next = newNode;
  }
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L)
{
  if (*L == NULL || p <= 0)
  {
    printf("vi tri khong hop le");
    return -1; // Vị trí không hợp lệ
  }
  List temp = *L; // khai báo biến tạm lưu cả ds
  for (int i = 1; i < p - 1; i++)
  {                    // cho p = 3
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

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L)
{
  List newNode = (Node *)malloc(sizeof(Node));
  newNode->data = x;          // gán gtri cho node mới
  newNode->next = (*L)->next; // cho node mới trỏ đến node đầu của ds
  (*L)->next = newNode;       // cập nhật lại ds sau khi đã thêm node mới
}

/*
Remove and return the first element
*/
ElementType popFirst(List *L)
{
  if (*L == NULL)
  {
    return -1;
  }

  List temp = *L; // Danh sách hiện tại
  ElementType data = (*L)->next->data;
  *L = (*L)->next; // Cập nhật danh sách để bỏ qua phần tử đầu tiên
  free(temp);
  return data;
}

/*
Append a new element to the list
*/

void append(ElementType x, List *L)
{
  insertAt(len(*L), x, L);
}

/*
Remove and return the last element
*/
ElementType popLast(List *L)
{
  ElementType value;
  PNode posLast = *L;
  while (posLast->next->next != NULL)
  {
    posLast = posLast->next;
  }
  value = posLast->next->data;
  popAt(len(*L), L);
}

/*
Return the position of the first appearance of x in the list
*/
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

/*
Return the pointer referring to the next position of i in L
*/
PNode next(Position p, List L)
{
  // Kiểm tra nếu vị trí p không hợp lệ
  if (p < 1 || p > len(L))
  {
    printf("Vị trí không hợp lệ\n");
    return NULL;
  }

  PNode temp = getPosition(p, L); // Lấy con trỏ đến vị trí p
  if (temp != NULL)
  {
    return temp->next; // Trả về phần tử kế tiếp
  }

  return NULL; // Trả về NULL nếu không có phần tử tiếp theo
}

/*
Return the pointer referring to the previous position of p in L
*/
PNode previous(Position p, List L)
{
  List temp = L;
  for (int i = 1; i < p - 1; i++)
  {
    temp = temp->next;
  }
  return temp;
}


// void bubbleSort(List *L) {
//     if (*L == NULL || (*L)->next == NULL) {
//         return; // Danh sách rỗng hoặc chỉ có một phần tử, không cần sắp xếp
//     }
    
//     int swapped;
//     PNode ptr1;
//     PNode lptr = NULL; // Dùng để đánh dấu phần tử đã được sắp xếp

//     do {
//         swapped = 0;
//         ptr1 = *L;

//         while (ptr1->next != lptr) {
//             if (ptr1->data > ptr1->next->data) {
//                 // Hoán đổi dữ liệu giữa hai phần tử
//                 ElementType temp = ptr1->data;
//                 ptr1->data = ptr1->next->data;
//                 ptr1->next->data = temp;
                
//                 swapped = 1; // Đánh dấu đã có sự hoán đổi
//             }
//             ptr1 = ptr1->next;
//         }
//         lptr = ptr1;
//          /* Giảm bớt phạm vi của danh sách sau mỗi lần lặp,
//           cập nhận next của lptr sau mỗi lần lặp là đia chỉ của phẩn tử đã đã được sắp xếp
//           (để bỏ qua phần tử cuối đã đc sắp xếp-> tối ưu hiệu suất)
//                             */

//     } while (swapped);
// }

int main()
{
    int n;
    List L;
    makeNull(&L); // Khởi tạo danh sách rỗng

    printf("Nhập giá trị cần thêm: ");
    scanf("%d", &n);

    insertFirst(n, &L);
    print(L);

    return 0;
}
