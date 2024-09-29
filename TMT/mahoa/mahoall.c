#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data;
    struct Node* next;
} CharNode;

typedef struct IntNode{
    int data;
    struct IntNode* next
} IntNode;


//tạo nút cho dslk chứa ký tự
CharNode* createCharNode(char data){
    CharNode* newNode = (CharNode*)malloc(sizeof(CharNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//tạo nút cho dslk chứa số nguyên
IntNode* createIntNode(int data){
    IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//thêm ptu vào dslk số nguyên
void appendIntNode(IntNode *head, int data){
    IntNode* newNode = createIntNode(data);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        IntNode* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//mã hóa
void encode(CharNode* source, IntNode* key, CharNode* dest){
    CharNode* sourceTemp = source;
    IntNode* keyTemp = key;
    int keyCount = 0;

    while(sourceTemp != NULL){
        if (keyTemp == NULL){
            keyTemp = keyl
        }

        //ma hoa ky tu
        char encodedChar = sourceTemp->data + keyTemp->data;
        appendCharNode(dest, encodedChar);

        sourceTemp = sourceTemp->next;
        keyTemp = keyTemp->next;
    }
}

//Nhap chuoi bat ky thanh linked list
void inputString(CharNode** head){
    char temp[100];
    printf("Enter the string to encoding: ");
    fgets(temp, 100, stdin);
    temp[strcspn(temp, "\n")] = '\0'; // bỏ xuống dòng
    for(int i =0; i < strlen(temp); i++){
        appendCharNode(head, temp[i]);
    }
}

//nhập khóa thành linked list
void inputKey(IntNode** head){
    int length;
    printf("Enter number of elements of key: ");
    scanf ("%d", &length);
    printf("Enter value of key: ");
    for (int i =0; i < length; i++){
        int value;
        scanf("%d", value);
        appendIntNode(head, value);
    }
}

//in dslk ký tự
void printCharList(CharNode* head){
    CharNode* temp = head;
    while(temp != NULL){
        printf ("%c", temp->data);
        temp = temp->next;
    }
    printf ("\n");
}

//in dslk số nguyên
void printIntList(IntNode* head){
    IntNode* temp = head;
}

