#include <stdio.h>

int main() {
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ko co gia tri lon nhat \n");
        return 0;
    }

    int arr[n];

    printf("Nhap %d phan tu cua mang: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Gia tri lon nhat trong mang la: %d\n", max);

    return 0;
}
