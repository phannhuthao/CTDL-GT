#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main() {
    int n;

    printf("Nhap so n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n phai la so nguyen duong.\n");
        return 1;
    }

    printf("Chuoi Fibonacci: ");
    for (int i = 0; i < n; i++) {
        printf("%d", fibonacci(i));
        if (i < n - 1) {
            printf(" ");
        }
    }
    return 0;
}

