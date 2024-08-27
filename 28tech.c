#include <stdio.h>
#include <string.h>
#include <ctype.h>
void reverse(int a, int b){
    int l =0, r = n-1;
    int tmp;
    while(l < r){
        tmp = a[l];
        a[r]= a[l];
        a[l] = tmp;
        ++l; --r;
    }
}
// a >b
void subtract(char a[], char b[]){
    int n1 = strlen(a), n2 = strlen(b), n=0;
    int x[n1], y[n1], z[n1];
    for (int i =0; i <n1; i++){
        x[i] = a[i] - '0'; 
    }
    for (int i =0; i < n2; i++){
        y[i] = b[i] - '0';
    }
    reverse(x, n1); reverse(y,n2);
    for (int i = n2, i < n1; i++){
        y[i] = 0;
    }
    int nho =0;
    for (int i =0; i < n1; i++){
        int tmp = a[i] - b[i] - nho;
        
    }

}