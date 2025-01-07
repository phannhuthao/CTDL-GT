#include <stdio.h>

int main() {
    int n;

    printf("Nhap so luong phan tu N trong mang: ");
    scanf("%d", &n);

    if(n <= 0) {
        return 0;
    }

    int arr[n];

    printf("Nhap %d phan tu cua mang: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int foundSymmetry = 0;

    for(int i = 0; i < n / 2; i++) {
        if(arr[i] == arr[n - i - 1]) {
            printf("Cap doi xung: (%d, %d)\n", arr[i], arr[n - i - 1]);
            foundSymmetry = 1;
        }
    }

    if (!foundSymmetry) {
        printf("Khong co phan tu doi xung trong mang\n");
    }

    return 0;
}
