#include <stdio.h>
#include <string.h>

// Hàm mã hóa
void encode(char* source, int* key, int key_length, char* dest) {
    int source_length = strlen(source);
    for (int i = 0; i < source_length; i++) {
        // Tính chỉ số khóa theo chu kỳ
        int key_value = key[i % key_length];
        
        // Mã hóa ký tự bằng cách cộng với giá trị khóa
        dest[i] = source[i] + key_value;
    }
    dest[source_length] = '\0'; // Kết thúc chuỗi kết quả
}

int main() {
    // Chuỗi nguồn cần mã hóa
    char source[] = "Data";
    
    // Khóa mã hóa
    int key[] = {2, 3, 4, 9};
    int key_length = sizeof(key) / sizeof(key[0]);
    
    // Chuỗi đích sau khi mã hóa
    char dest[100]; // Đảm bảo đủ bộ nhớ cho chuỗi mã hóa
    
    // Gọi hàm mã hóa
    encode(source, key, key_length, dest);
    
    // In kết quả
    printf("Source: %s\n", source);
    printf("Encoded: %s\n", dest);
    
    return 0;
}
