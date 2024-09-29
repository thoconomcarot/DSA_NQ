#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef Node* Stack;

void makeNull(Stack *st);

int isEmpty(Stack st);

void push(ElementType x, Stack *st); //đẩy x lên trên cùng

ElementType pop(Stack *st); //trả về ptu trên cùng (top) loại bỏ nó

void print(Stack st);

void convertBinary(int n);  //nhị phân

int Fibonacci(int n);  //tính fibonacci

int C(int k, int n);  //tính tổ hợp


int main (){
    int x; 
    printf("Enter the number: ");
    scanf("%d", &x);

    printf("\tBinary number of %d is: ", x);
    convertBinary(x);

    printf ("\tFibonacci number %d: %d\n", x, Fibonacci(x));

    printf("Enter k and n: ");
    int k, n; scanf ("%d %d", &k, &n);

    printf("\tThe combination of %d of %d is: %d\n", k, n, C(k, n));
    return 0;
}


void makeNull(Stack *st){
    Node* top = (Node*)malloc(sizeof(top));
    top->next = NULL;
    (*st) = top;
}

int isEmpty(Stack st){
    return st->next == NULL;
}

void push(ElementType x, Stack *st){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = (*st)->next;
    (*st)->next = temp;
}

ElementType pop(Stack *st){
    if(isEmpty(*st)){
        printf ("Stack is empty!\n");
        return -1; //không có ptu nào để lấy ra
    }
    Node *temp = (*st)->next; //con trỏ trỏ tới ptu trên cùng (top)
    ElementType val = temp->data; //lưu gtri của top
    (*st)->next = temp->next; //cập nhật con trỏ trỏ tới ptu kế tiếp, đã xóa ptu trên cùng(top)
    free(temp); //giải phóng bộ nhớ của các ptu đã xóa, tránh rò rỉ bộ nhớ
    return val;
}


void print(Stack st){
    printf ("Stack: ");
    while(st->next != NULL){
        printf ("%d ", st->next->data);
        st = st->next;
    }
    printf ("\n");
}



void convertBinary(int n){
    Stack st;
    makeNull(&st);
    if(n == 0){
        push(0, &st);
    }
    else{
        while( n != 0){
            push(n % 2, &st);
            n /= 2;
        }
    }

    while(!isEmpty(st)){ //lặp đến khi stack rỗng
        printf ("%d", pop(&st));
    }
    printf ("\n");

}


int Fibonacci (int n){  //Số fibo là số tiếp theo bằng tổng của hai số liền trước
    // Stack st;
    // makeNull(&st);
    // push(n, &st); //đẩy gt (số fibo cần tính) vào ngăn xếp
    if (n == 1 || n == 2){
        return 1;
        }
    else{
        return Fibonacci(n-1) + Fibonacci(n-2);
        }
}


int C(int k, int n){
    if(k == 0 || k == n){
        return 1;
    }
    if(k == 1){
        return n;
    }
    return C(k-1, n-1) + C(k, n-1);
}