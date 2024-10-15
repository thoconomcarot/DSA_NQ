#include"plistlib.h"
#include<stdio.h>

//linkedlist
void bubbleSort(List *L) {
    if (*L == NULL || (*L)->next == NULL) {
        return; // Danh sách rỗng hoặc chỉ có một phần tử, không cần sắp xếp
    }
    
    int swapped;
    PNode a;
    PNode b = NULL; // Dùng để đánh dấu phần tử đã được sắp xếp

    do {
        swapped = 0;
        a = *L;

        while (a->next != lptr) {
            if (a->data > a->next->data) {
                // Hoán đổi dữ liệu giữa hai phần tử
                ElementType temp = a->data;
                a->data = a->next->data;
                a->next->data = temp;
                
                swapped = 1; // Đánh dấu đã có sự hoán đổi
            }
            a = a->next;
        }
        b = a;

    } while (swapped);
}