#include "linkedlist.h"
#include <stdio.h>

void bubbleSort(List *L){
    if((*L) == NULL || (*L)->next == NULL){
        return; //kiểm tra nếu ds rỗng thì thoát
    }

    int swapp;
    PNode a; //con trỏ dùng duyệt qua các ptu của ds lien kết
    PNode b = NULL; //con trỏ đánh dấu phần cuối của ds đã được sx trong mỗi lần lặp

    do{
        swapp = 0; //để ktra có ptu nào bị hoán đổi trong lần duyệt
        a = *L; //gán a trỏ tới đầu ds

        while(a->next != b){
            if(a->data >a->next->data){ //kiểm tra có đúng thứ tự
                ElementType temp = a->data;
                a->data = a->next->data;
                a->next->data = temp;

                swapp = 1; //sau khi hoán đổi để báo rằng có sự thay đổi 
            }
        }

        b = a; //vị trí sai, di chuyển ra khỏi vòng lặp while
    }while(swapp);
}