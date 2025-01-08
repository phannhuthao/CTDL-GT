#include <stdio.h>

void sortNumber(int arr[], int n) {
    for(int i=0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            // Hiển thị quá trình hoán đổi
            for (int k = 0; k < n; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }
}

int main() {

    int n;

    printf("Nhap so luong phan tu mang: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhap %d trong mang: ", n);
    for(int i = 0; i < n ; i++) {
        scanf("%d", &arr[n]);
    }

    printf("Truoc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sortNumber(arr, n);

    printf("Sau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}