//#include "alistlib.h"
#include "plistlib.h"


void readList(int a[], int sizeArray, List *L);

void swap(Position a, Position b, List* L);

void bubbleSort(List* L);

void selectionSort(List * L);

void insertionSort(List *L);


void readList(int a[], int sizeArray, List *L) {
    while (sizeArray > 0) { 
        insertFirst(a[sizeArray - 1], L); // Thêm phần tử từ mảng vào danh sách
        sizeArray--;
    }
}


void swap(Position a, Position b, List* L) {
    ElementType temp = getAt(a, *L);
    setAt(a, getAt(b, *L), L);
    setAt(b, temp, L);
}

void bubbleSort(List* L) {
    int length = len(*L);
    for(int i = 1; i <= length; i++){
        for(int j = 1; j <= length-1; j++){
            if(getAt(j,*L) > getAt(j+1,*L)){
                swap(j,j+1,L);
            }
        }
    }
}

void selectionSort(List * L){
    int length = len(*L);
    for(int i = 1; i < length; i ++){
        int minPos = i;
        for(int j = i + 1; j < length + 1; j++){
            if(getAt(minPos, (*L)) > getAt(j, (*L))){
                minPos = j; 
            }
        }
        swap(i, minPos, L);
    }
}

void insertionSort(List *L){
    int lenght = len(*L);
    for(int i = 1; i <= lenght; i++){
        int temp = getAt(i,(*L));
        int pos = i;
        // so sánh vị trí a[i] với a[i+1]
        while(pos > 1 && getAt(pos - 1, *L) > temp){
            setAt(pos, getAt(pos - 1, *L),L);
            pos--;
        }
        setAt(pos,temp, L);
    }
}

int main() {
    List L;
    makeNull(&L);

    int a[] = {3, 7, 8, 5, 4, 2, 6, 1};
    int b[] = {100, 3, 2, 5, 44, 12, 9, 8, 10, 6, 10, 11};
    int c[] = {110};
    int d[] = {0};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int o = sizeof(c) / sizeof(c[0]);
    int p = sizeof(d) / sizeof(d[0]);

    printf("--------------------------------------------------------------------\n");
    
    // Test 1
    printf("Test 1:\n");
    readList(a, n, &L);
    print(L);
    printf("Length of list: %d\n", len(L));
    insertionSort(&L); // Hoặc bất kỳ hàm sắp xếp nào khác
    print(L);

    printf("\n--------------------------------------------------------------------\n");
    makeNull(&L);
    
    // Test 2
    printf("Test 2:\n");
    readList(b, m, &L);
    print(L);
    printf("Length of list: %d\n", len(L));
    insertionSort(&L);
    print(L);

    printf("\n--------------------------------------------------------------------\n");
    makeNull(&L);
    
    // Test 3
    printf("Test 3:\n");
    readList(c, o, &L);
    print(L);
    printf("Length of list: %d\n", len(L));
    insertionSort(&L);
    print(L);

    printf("\n--------------------------------------------------------------------\n");
    makeNull(&L);
    
    // Test 4
    printf("Test 4:\n");
    readList(d, p, &L);
    print(L);
    printf("Length of list: %d\n", len(L));
    insertionSort(&L);
    print(L);

    return 0;
}