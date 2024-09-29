#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
typedef char ElementType;

typedef struct list{
    ElementType elements[MAX_LENGTH];
    int size;
} List;

void makeNull (List *L){
    L->size = 0;
}

int length(List L){
    return L.size;
}

int isEmpty(List L){
    return L.size == 0;
}

int isFull(List L){
    return L.size == MAX_LENGTH;
}

void print(List L){
    if(!isEmpty(L)){
        int size = L.size;
        for (int i = 0; i < size; i++){
            printf ("%c", L.elements[i]);
        }
        printf ("\n");
    }
    else{
        printf("<!> List is empty");
    }
}


void append(ElementType x, List L){

}


List read(){
    List init;
    printf("Enter string: ");
    fgets(init.elements, MAX_LENGTH, stdin);
    init.elements[strlen(init.elements) - 1] = '\0';
    init.size = strlen(init.elements);
    return init;
}


List coder(List source, List key){
    List des;
    makeNull(&des);
    des.size = source.size;
    int size = des.size;
    int sizeKey = key.size;
    for(int i =0; i < size; i++){
        des.elements[i] = source.elements[i] + (key.elements[i % sizeKey] - '0');
    }
    return des;
}


List deCoder(List source, List key){
    List des;
    makeNull(&des);
    des.size = source.size;
    int size = des.size;
    int sizeKey = key.size;
    for(int i = 0; i < size; i++){
        des.elements[i] = source.elements[i] - (key.elements[i % sizeKey] - '0');
    }
    return des;
}

int main() {
    List source = read();
    List key = read();
    
    printf("\nSource string: ");
    print(source);

    printf("\nKey string: ");
    print(key);

    List encoded = coder(source, key);
    printf("\nEncoded string: ");
    print(encoded);

    List decoded = deCoder(encoded, key);
    printf("\nDecoded string: ");
    print(decoded);

    return 0;
}