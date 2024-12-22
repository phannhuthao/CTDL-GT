#include <stdio.h>
#include <string.h>

int daoNguocChuoi(char str[], int start, int end) {
    if (start >= end)  {
        return 0;
    }


    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    daoNguocChuoi(str, start + 1, end - 1);
}

int main() {
    char str[100];

    printf("Nhap mot chuoi vao: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    daoNguocChuoi(str, 0, strlen(str) - 1);

    printf("Chuoi dao nguoc: %s\n", str);

    return 0;
}
