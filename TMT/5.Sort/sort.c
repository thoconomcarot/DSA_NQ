//#include "alistlib.h"
#include "plistlib.h"

void readList (int a[], int n, List *L){
    while(n > 0){
        insertFirst(a[n-1], L);
        n--;
    }
}

void printList(List L){
    if (empty(L)){
        printf("List is empty!\n");
        return;
    }

    printf ("\tList of elements: ");
    for (int i = 1; i <= len(L); i++){
        printf("%d ", getAt(i, L));
    }
    printf ("\n");
}


void bubbleSort (List *L){
    int n = len(*L);
    for (int i = 1; i < n-1; i++){
        for (int j = 1; j <= n-i; j++){
            if(getAt(j, *L) > getAt(j+1,(*L))){
                int temp = getAt(j+1,(*L));
                setAt(j+1, getAt(j, (*L)), L);
                setAt(j, temp, L);
            }
        }
    }
}

void insertionSort (List *L){
    int n = len(*L);
    for (int i = 1; i <= n; i++){
        int temp = getAt(i, (*L));
        int j = i;
        while(j > 1 && getAt(j-1, (*L)) > temp){
            setAt(j, getAt(j-1, (*L)), L);
            j--;
        }
        setAt(j, temp, L);
    }
}

void selectionSort(List *L){
    int n = len(*L);
    for (int i =1; i < n; i++){
        int min = i;
        for (int j = i +1; j <= n; j++){
            if (getAt(min,(*L)) > getAt(j,(*L))){
                min = j;
            }
        }
        int temp = getAt(i, (*L));
        setAt(i, getAt(min, (*L)), L);
        setAt(min, temp, L);
    }
}

void shellSort(List *L){
    int length = len(*L);
    for(int gap = length / 2; gap >= 1; gap /= 2){
        for(int i = gap; i <= length; i++){
            for(int j = i-gap ; j >= 0; j -= gap){
                if(getAt(j, *L) > getAt(j + gap, *L)){
                    int temp = getAt(j+gap, (*L));
                    setAt(j+gap, getAt(j, (*L)), L);
                    setAt(j, temp, L);

                } else {
                    break;
                }
            }
        }
    }
}


int main (){
    List L;
    makeNull(&L);

    int a[] = {4,7,2,1,3,8,9,0,6,5}; //0 1 2 3 4 5 6 7 8 9
    int b[] = {7,4,2,1,5};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    // readList(a,n, &L);
    // readList(b,m, &L);
    // printf ("List: ");
    // printList(L);

    printf("~~~~~~~~~~~~~~~~\n");
    makeNull(&L);
    printf("Test a\n");
    readList(a, n, &L);
    printList(L);
    printf ("After sorting\n");
    //bubbleSort(&L);
    //insertionSort(&L);
    //selectionSort(&L);
    shellSort(&L);
    printList(L);
    
    
    printf("~~~~~~~~~~~~~~~~\n");
    makeNull(&L);
    printf("Test b\n");
    readList(b, m, &L);
    printList(L);
    printf ("After sorting\n");
    //bubbleSort(&L);
    //insertionSort(&L);
    //selectionSort(&L);
    shellSort(&L);
    printList(L);
    
   
    return 0;
}