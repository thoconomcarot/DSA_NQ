#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
typedef char ElementType;
typedef int Position;
typedef struct NodeTag{
    ElementType elements;
    struct NodeTag* next;
} Node;

typedef Node *next;
typedef Node *PNode;

void makeNull(List *L){
    List createEmpty = (Node*)malloc(sizeof(Node));
    createEmpty->next = NULL;
    (*L) = createEmpty;
}

int Empty(List L){
    return L->next == NULL;
}

int length(List L){
    int count = 0;
    while(L->next != NULL){
        count++;
        L = L->next;
    }
    return count;
}

void print(List L){
    if(!Empty(L)){
        while(L->next != NULL){
            printf ("%c", L->next->elements);
            L = L->next;
        }
        printf("\n");
    }
    else{
        printf("<!> List is empty");
    }
}

void insertFirst(ElementType x, List *L){
    List newNode = (Node*)malloc(sizeof(Node));
    newNode->elements = x;
    newNode->next = (*L)->next;
    (*L)->next = newNode;
}


List read(){
    List init = (Node*)malloc(sizeof(Node));
    makeNull(&init);
    printf ("Enter string: ");

    char source[MAX_LENGTH;
    fgets(source, MAX_LENGTH, stdin);
    source[strlen(source)-1] = '\0';

    int size = strlen(source);
    for(int i = size-1; i >= 0; i--){
        insertFirst(source[i], &init);
    }
    return init;
}


List reverse(List L){
    PNode cur = L->next;
    PNode next = NULL;
    PNode prev = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    L->next = prev;
    return L;
}


List coder(List source, List key){
    List des = (Node*)malloc(sizeof(Node));
    makeNull(&des);
    PNode posKey = key;
    while(source->next != NULL){
        if(posKey->next == NULL){
            posKey = key;
        }
        ElementType data = source->next->elements = (posKey->next->elements - '0');
        insertFirst(data, &des);
        source = source->next;
        posKey = posKey->next;
    }
    des = reverse(des);
    return des;
}

List deCoder(List source, List key){
    List des = (Node*)malloc(sizeof(Node));
    makeNull(&des);
    PNode poskey = key;
    while(source->next != NULL){
        if(poskey->next == NULL){
            poskey = key;
        }
        ElementType data = source->next->elements - (poskey->next->elements - '0');
        insertFirst(data, &des);
        poskey = poskey->next;
        source = source->next;
    }
    des = reverse(des);
    return des;
}