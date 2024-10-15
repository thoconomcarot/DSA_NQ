#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 100
typedef int Position;
typedef int ElementType;

typedef struct {
    ElementType elements[MaxSize];
    Position size;
}List;

void makeNull(List *L){
    L->size = 0;
}

int len (List L){
    return L.size;
}

int empty (List L){
    return L.size == 0;
}

int full(List L){
    return L.size == MaxSize;
}

Position first(List L){
    return 1;
}

Position end(List L){
    return L.size+1;
}

Position next(Position p, List L){
    return p + 1;
}

Position previous(Position p, List L){
    return p - 1;
}

ElementType getAt (Position p, List L){
    return L.elements[p - 1];
}

//thay đổi phần tử tại p thành x
void setAt(Position p, int x, List *L){
    if(p < 1 || p > MaxSize){
        printf ("###Invalid_position###");
        return -1;
    }
    L->elements[p-1] = x;
}

//Thêm x vào vị trí p
void insertAt(Position p, int x, List *L){
    if (p < 1 || p > L->size+1){
        printf ("###Invalid_position###");
        return -1;
    }
    else if(full(*L)){
        printf ("List is full!\n");
        return -1;
    }
    else{
        for (int i = L->size; i >= p; i--){
            L->elements[i] = L->elements[i-1];
        }
        L->elements[p-1] = x;
        L->size++;
    }
}

ElementType popAt (Position p, List *L){
    if (p < 1 || p > L->size+1){
        printf ("###Invalid_position###");
        return -1;
    }
    else if(empty(*L)){
        printf ("List is empty!\n");
        return -1;
    }
    ElementType a = L->elements[p-1];
    else{
        for (int i = p - 1; i < L->size-1; i++){
            L->element[i] = L->element[i+1];
            L->size--;
        }
    }
    return a;
}

int insertFirst (int x, List *L){
    if (full(*L)){
        printf ("List is full!\n");
        return -1;
    }
    else{
        insertAt(first(*L), x, L);
        return 1;
    }
}

void popFirst (List *L){
    popAt(First(*L), L);
}


