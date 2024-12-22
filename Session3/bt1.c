#include <stdio.h>

int functionA (int n) {
    if (n == 0) {
        return 1;
    }
    return n * functionA (n -1);
}

int main() {
    int n;

    printf("Nhap so N nguyen duong: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("So nhap vao khong hop le. Hay nhap so nguyen duong!\n");
    } else {
        printf("Giai thua cua %d la: %d\n", n, functionA(n));
    }
    return 0;
}
