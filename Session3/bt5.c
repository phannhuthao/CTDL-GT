#include <stdio.h>
#include <string.h>

int palindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1; // Chuỗi đối xứng
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return palindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];

    // Nhập chuỗi từ người dùng
    printf("Nhap 1 chuoi vao: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    if (palindrome(str, 0, strlen(str) - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }

    return 0;
}

