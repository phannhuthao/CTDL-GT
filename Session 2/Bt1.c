
#include <stdio.h>

int main() {
    int n;

    do {
        printf("Nhập số phần tử của mảng (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    int arr[n];

    printf("Nhập các phần tử của mảng:\n");
    for (int i = 0; i < n; i++) {
        printf("Phần tử [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Phần tử lớn nhất trong mảng là: %d\n", max);

    return 0;
}
