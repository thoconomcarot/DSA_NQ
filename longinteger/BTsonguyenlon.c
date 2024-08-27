#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct LongInt {
    char *digits;
    int length;
    int isNegative;  //kiểm tra dấu số nguyên
};
typedef struct LongInt LongInt;

void read(LongInt *num, char x){
    char c[1001];
    printf ("Enter number %c: ", x);
    fgets(c, 1001, stdin);
    c[strlen(c)-1] = '\0'; //xoa bo ky tu xuong dong

    //kiểm tra dấu âm
    if(c[0] == '-'){
        num->isNegative = 1;
        num->digits = (char*)malloc(strlen(c)); //cap phat dong vung nho
        strcpy(num->digits, c+1);
    }
    else{
        num->isNegative = 0;
        num->digits = (char*)malloc(strlen(c)+1); //cap phat dong vung nho
        strcpy(num->digits,c);
    }

    num->length = strlen(num ->digits); // lưu độ dài
}


void display(LongInt num ){
    if(num.isNegative){
        printf("-"); //neu do dai cua so lon la am thi in ra
    }
    printf ("%s", num.digits);
}

//Lật ngược xâu VD: 1234 -> 4,3,2,1
void reverse(char *num, int length){
    int l=0, r= length - 1; // vì ở đây sử dụng con trỏ 
    while(l <r){
        //hoán đổi vị trí trái và phải để lật lại
        char temp = num[l];
        num[l] = num[r];
        num[r] = temp; 
        l++; r--;
    }
}


//khai bao int vì trả về đúng hoặc sai
int compareDigits(char *a, char *b, int lenA, int lenB){
    if(lenA != lenB){
        return lenA-lenB; //so sánh độ dài chuỗi, chuỗi nào dài hơn, dài hơn thì lúc nào cũng lớn hơn
    }
    return strcmp(a,b); // so sánh trực tiếp cái nào lớn hơn nếu chuỗi bằng nhau
}


LongInt Subtract (LongInt a, LongInt b){
    LongInt result;
    int maxLength = (a.length > b.length) ? a.length : b.length;
    result.digits = (char*)malloc(maxLength+1);
    result.length = 0;
    //đảo ngược 2 số a và b
    reverse(a.digits, a.length); reverse(b.digits, b.length);
    int bor = 0;
    for (int i =0; i < maxLength; i++){
        //cho i chạy tới độ dài lớn nhất, nếu i < độ dài cua a thì sẽ bằng phần tử thứ i trong mảng - 48 = 1;
        //nếu i lớn hơn độ dài của a thì cho các phần tử phía sau thành 0 hết;
        int digitA = (i < a.length) ? a.digits[i] - '0' : 0;
        int digitB = (i < b.length) ? b.digits[i] - '0' : 0;
        int differ = digitA - digitB - bor;
        if(differ < 0){
            differ += 10;
            bor = 1;
        }
        else{
            bor =0;
        }
        //trường hợp số có 2 cs - số 1 cs in ra kq thì sẽ in thêm số 0 phía sau kq để tránh nhảy hàng chục và hàng đvị
        //VD: 12 - 09 -> 21 - 90 = 3'0'
        result.digits[result.length++] = differ + '0';
    }
    //bỏ các sô 0 thừa khi mà xâu trước có chỉ số lớn hơn xâu sau
    while(result.length > 1 && result.digits[result.length - 1] == '0'){
        result.length--;
    }
    result.digits[result.length] = '\0';
    reverse(result.digits, result.length);
    return result;
}


LongInt Add(LongInt a, LongInt b){
    LongInt result;
    int maxLength = (a.length > b.length) ? a.length : b.length;
    result.digits = (char*)malloc(maxLength + 2); // +1 ký tự nhớ và +1 ký tự kết thúc
    result.length = 0;
    reverse(a.digits, a.length); reverse(b.digits, b.length);
    int mem = 0;
    for (int i =0; i < maxLength; i++){
        int digitA = (i < a.length) ? a.digits[i] - '0' : 0;
        int digitB = (i < b.length) ? b.digits[i] - '0' : 0;
        int sum = digitA + digitB + mem;
        result.digits[result.length++] = (sum%10) + '0';
        mem = sum/10;
    }
    if(mem){
        result.digits[result.length++] = mem + '0';
    }
    //ket thuc xau
    result.digits[result.length] = '\0';
    reverse(result.digits, result.length);
    return result;
}


LongInt Sum(LongInt a, LongInt b){
    LongInt result;
    if( a.isNegative == b.isNegative){
        result = Add(a,b);
        result.isNegative = a.isNegative;
    }
    else{
        if(compareDigits(a.digits, b.digits, a.length, b.length) >= 0){
            result = Subtract(a,b);
            result.isNegative = a.isNegative; //lấy kq theo dấu của số lớn hơn
        }
        else{
            result = Subtract(b,a);
            result.isNegative = b.isNegative; //lấy kq theo dấu của số lớn hơn
        }
    }
    return result;
}


LongInt Sub(LongInt a, LongInt b){
    LongInt result;
    reverse(a.digits, a.length);
    reverse(b.digits, b.length);
    if(a.isNegative == 0 && b.isNegative == 0){
    //a và b đều dương
        if(compareDigits(a.digits, b.digits, a.length, b.length) >= 0){
            result = Subtract(a,b);
            result.isNegative = 0;
        }
        else{
            result = Subtract(b,a);
            result.isNegative = 1;
        }
    }
    // a và b khác dâu
    else if (a.isNegative != b.isNegative){
        // a âm và b dương
        if(a.isNegative == 1 && b.isNegative == 0){
            b.isNegative = 1;
            result = Sum(a,b);
            result.isNegative = 1;
        }
        // a dương và b âm
        else if(a.isNegative == 0 && b.isNegative == 1){
            a.isNegative = 1;
            result = Sum(a,b);
            result.isNegative = 0;
        }
    }
    //a và b âm
    else{
        if(compareDigits(a.digits, b.digits, a.length, b.length) >= 0){
            result = Subtract(a,b);
            result.isNegative = 1;
        }
        else{
            result = Subtract(b,a);
            result.isNegative = 0;
        }
    }
    reverse(a.digits, a.length); reverse(b.digits, b.length);
    return result;
}


int main (){
    LongInt a, b, result;
    read(&a, 'a');
    read(&b, 'b');

    printf("Result of two operations: \n");
    printf ("   Sum: a + b = ");
    result = Sum(a,b);
    display(result);
    printf ("\n");

    printf ("   Sub: a - b = ");
    result = Sub(a,b);
    display(result);
    printf("\n");

    free(a.digits);
    free(b.digits);
    free(result.digits);
    free(result.digits);
    return 0;
}