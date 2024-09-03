#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *digits; // Pointer to store digits
    int length;   // Length of the number
} BigInteger;


void read(BigInteger *number, char x){
    char c[1000];
    printf("Enter number %c: ", x);
    fgets(c,1005,stdin);
	c[strlen(c)-1]='\0';
    number->digits = (char *)malloc(strlen(c)+1); //cấp phát động một vùng nhớ 
    strcpy(number->digits, c);//copy từ xâu c sang number
    number->length = strlen(number->digits);//lưu độ dài của xâu
}


void display(BigInteger num){
    printf("%s",num.digits);
}


void reverse(BigInteger *num) {
    int l = 0, r = num->length - 1; // Chỉ số phải là r = num->length - 1
    while (l < r) {
        char tmp = num->digits[l];
        num->digits[l] = num->digits[r];
        num->digits[r] = tmp; // Hoán đổi vị trí l và r
        l++;
        r--;
    }
}


// int checkLength(BigInteger a, BigInteger b){
//     int x;
//     if(a.length>b.length){
//         return x = a.length;
//     }
//     else{
//         return x = b.length;
//     }
// }
int checkLength(BigInteger a, BigInteger b) {
    return (a.length > b.length) ? a.length : b.length;
}


void sum(BigInteger a, BigInteger b){
    // Đảo ngược số trước khi cộng
    reverse(&a);
    reverse(&b);
    int count= checkLength(a,b);
    int n1 = a.length, n2 = b.length, n = 0;
    int x[count], y[count], z[count+1];
    // Sao chép các chữ số từ chuỗi vào mảng x và y
    for(int i=0; i<a.length; i++){
        x[i]= a.digits[i] - '0';
    }
    for(int i=0; i<a.length; i++){
        y[i]= b.digits[i] - '0';
    }
    // Điền các giá trị 0 vào phần thừa của mảng ngắn hơn
    if (n1 > n2) {
        for (int i = n2; i < count; i++) {
            y[i] = 0;
        }
    } else {
        for (int i = n1; i < count; i++) {
            x[i] = 0;
        }
    }
    // Tính tổng từng cặp chữ số và lưu kết quả vào mảng z   
    int memory=0;
    for(int i =0 ;i < count; i++){
        int tmp = x[i] + y[i] + memory;
        z[n++] = tmp % 10;
        memory = tmp/10;
    }
    if(memory){
        z[n++] = memory;
    }

    
    // In kết quả
    printf("Sum: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", z[i]);
    }
    printf("\n");
}




int main() {
    BigInteger a, b;
    read(&a, 'a');
    read(&b, 'b');

    sum(a, b);

    return 0;
} 
int checkNegativeIntegers(BigInteger *a, BigInteger *b){
    if(a->digits[0] == '-'){

    }
}