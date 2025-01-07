#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count[MAX_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (count[arr[i]] > 1) {
            printf("Phan tu %d xuat hien %d lan.\n", arr[i], count[arr[i]]);
            count[arr[i]] = 0;
            found = 1;
        }
    }

    if (!found) {
        printf("Khong co phan tu lap lai.\n");
    }

    return 0;
}
