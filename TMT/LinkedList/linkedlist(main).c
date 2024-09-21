#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef int Position;
typedef struct NodeTag{
    ElementType data;
    struct NodeTag *next;
}Node;

typedef Node *List;
typedef Node* PNode;

//khởi tạo ds rỗng
void makeNull (List *L){
    struct Node*header;
    header = (struct Node*)malloc(sizeof(struct Node));
    header->next = NULL;
    (*L) = header;
}

//trả về vị trí đầu tiên
PNode first (List L){
    List header = L;
    return header;
}


//trả về vị trí cuối cùng
PNode endList(List L){
    List header = L;
    while(header->next != NULL){
        header = header->next;
    }
    return header;
}


//trả về vị trí kế tiếp
PNode next(List L){
    List header = L;
    return header->next;
}


//tính độ dài của danh sách
int len(List L){
    List header = L;
    int count = 0;
    while(header->next != NULL){
        count++;
        header = header->next;
    }
    return count;
}


//check danh sách rỗng
int empty(List L){
    return L->next == NULL;
}


//check danh sách đầy
//int fullList(List L){}



//trả về phần tử ở vị trí p
// int retrieve(Position header, List L){
//     if(header->next != NULL){
//         return header->next->data;
//     }
// }


//in ra danh sách
void print(List L){
    List header = L;
    while(header->next != NULL){
        printf("%d", header->next->data);
        header= header->next;
    }
    printf ("\n");
}


//Trả về con trỏ trỏ đến vị trí p trong ds
PNode getPosition (int posi, List L){
    List header = L;
    int count = 0;
    while(header->next != NULL){
        count++;
        if(count == posi){
            return header;
        }
        else{
            return header = header->next;
        }
    }
    return header;
}


//Trả về giá trị ở vị trí p
int getAt(int posi, List L){
    int n = len(L);  
    List temp = L;
    for(int i = 1; i < n; i++){
        if(temp->next == NULL){
            return -1;
        }
        temp = temp->next;
    }
    return temp->data;
}


//Thay đổi phần tử ở vị trí p bằng 1 giá trị x mới
void setAt(ElementType x, int posi, List *L){
    PNode p = getPosition(posi, L);
    if (p != NULL){
        p->data = x;
    }
}



//Thêm vào vị trí đầu tiên
void insertFirst (ElementType x, List *L){
    List newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;  //gán gtri cho node mới
    newNode->next = (*L)->next;  //cho node mới trỏ đến node đầu của ds
    (*L)->next = newNode;        //cập nhật lại ds sau khi đã thêm node mới
}

//Xóa vị trí đầu tiên
ElementType popFirst(List *L){
    if (*L == NULL || (*L)->next == NULL) {
        return -1; // Danh sách rỗng
    }
    Node temp = *L;
    ElementType data = temp->data;
    *L = temp->next;
    free(temp);
    return data;
}


//Thêm vào vị trí bất kỳ
void insertAt(Position posi, ElementType x, List *L){
    List newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    List temp = *L;
    for(int i = 1; i < posi-1; i++){
        temp = temp->next;
    }
    if(temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


//Xóa vị trí bất kỳ
ElementType popAt(Position posi, List *L){
    List header = L; //khai báo biến tạm lưu cả ds
    for(int i = 1; i <posi - 1; i++){  //cho posi = 3
        header = header ->next; //nếu i = 1 < 2 thì temp dịch sang phần tử tiếp theo
    }
    List del = header->next; 
    header = del->next;
    free(del); //xóa
}


//Xóa vị trí cuối cùng
ElementType popLast(List *L){
    if (*L == NULL || (*L)->next == NULL) {
        return -1; // Danh sách rỗng
    }
    List temp = *L;
    while(temp->next->next != NULL){
        temp= temp->next;
    }
    List last = temp->next;
    ElementType data = last->data;
    last->next = NULL;
    free(last);
    return data;
}


//Thêm 1 phần tử mới vào cuối danh sách
void append(int x, List *L){
    List newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    List temp = *L;
    while(temp->next != NULL){
        temp = temp->next;
    }
        temp->next = newNode;
}


//trả về vị trí xuất hiện đầu tiên của x
Position locate(ElementType x, List L){
    List temp = L;
    int count = 0;
    while(temp->next != NULL){
        count++;
        if(x == temp->data){
            break;
        }
        else{
            temp = temp->next;
        }
    }
    return count;
}


//Trả về con trỏ tham chiếu đến vị trí trước đó của p trong L
PNode previous(Position p, List L){
    List temp = L;
    for(int i = 1; i < p-1; i++){
        temp = temp->next;
    }
    return temp;
}


int main() {
    int n;
    List L;
    makeNull(&L); // Khởi tạo danh sách rỗng

    printf("Nhập giá trị cần thêm: ");
    scanf("%d", &n);

    insertFirst(n, &L);
    print(L);

    return 0;
}




