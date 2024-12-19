
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, count;

    printf("Nhap so phan tu cua mang vao (0 < n <= 100) ");
    scanf("%d",&n);

    if(n <= 0 || n > 100) {
        printf("Gia tri n khong hop le");
        return 0;
    }

    int arr[n];

    printf("Nhap cac phan tu cua mang: \n");
    for(int i =0; i<n; i++) {
        scanf("%d",&arr[i]);
    }

    printf("Nhap gia tri x can dem");
    scanf("%d", &x);

    for (int i = 0; i< n; i++) {
        if(arr[i] == x) {
            count ++;
        }
    }
    printf("Gia tri %d xuat hien %d lan trong mang \n", x, count);
    return 0;
}




