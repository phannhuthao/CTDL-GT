#include <stdio.h>

int main() {
    int n, m;

    printf("Nhap so phan tu cua mang 1 (0 < n <= 1000): ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("Gia tri n khong hop le.\n");
        return 1;
    }

    printf("Nhap so phan tu cua mang 2 (0 < m <= 1000): ");
    scanf("%d", &m);

    if (m < 0 || m > 1000) {
        printf("Gia tri m khong hop le.\n");
        return 1;
    }

    int arr1[n], arr2[m], result[n + m];

    printf("Nhap cac phan tu cua mang 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Nhap cac phan tu cua mang 2:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < n; i++) {
        result[i] = arr1[i];
    }

    for (int i = 0; i < m; i++) {
        result[n + i] = arr2[i];
    }

    printf("Mang ket qua sau khi gop:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
