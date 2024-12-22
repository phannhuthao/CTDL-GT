#include <stdio.h>

int tinhTongCacSoTrongMang(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n-1] + tinhTongCacSoTrongMang(arr, n-1);
}


int main() {
    int n;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhap cac phan tu cua mang: ");
    for(int i = 0; i <n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = tinhTongCacSoTrongMang(arr, n);
    printf("Tong cac so trong mang la: %d\n", sum);

    return 0;
}
