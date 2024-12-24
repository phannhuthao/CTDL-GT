#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;

    printf("Nhap so phan tu cua mang (0 < n <= 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Gia tri n khong hop le.\n");
        return 1;
    }

    int arr[n];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri k de xoa: ");
    scanf("%d", &k);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            found = 1;
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
            i--;
        }
    }

    if (!found) {
        printf("Thong bao: Khong co phan tu day trong mang.\n");
    } else {
        printf("Mang sau khi xoa:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
