#include "alistlib.h"
#include <stdio.h>

//list
// bubbleSort
void bubbleSort(List *L) {
    Position i, j;
    int n = end(*L);  // end(*L) trả về số phần tử trong danh sách

    for (i = 0; i < n - 1; i++) {
        // Vòng lặp thứ hai chạy từ đầu đến phần tử chưa được sắp xếp cuối cùng
        for (j = 0; j < n - i - 1; j++) {
            // So sánh hai phần tử liên tiếp và hoán đổi nếu thứ tự sai
            if (L->Elements[j] > L->Elements[j + 1]) {
                ElementType temp = L->Elements[j];
                L->Elements[j] = L->Elements[j + 1];
                L->Elements[j + 1] = temp;
            }
        }
    }
}