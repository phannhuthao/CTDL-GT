#include <stdio.h>

int tinhTongHaiSoMvaN (int n , int m) {
    int sum  = 0;
    for (int i = 0; i <= m; i++) {
        sum += 1;
    }
    return sum;
}

int main() {
    int n , m;

    printf("Nhap m: ");
    scanf("%d", &m);

    printf("Nhap n: ");
    scanf("%d", &n);


    if (n > m) {
        printf("n phai nho hon hoac bang m\n");
        return 0;
    }


    int tong = tinhTongHaiSoMvaN(n, m);
    printf("Tong tu %d den %d la: %d\n", n, m, tong);

    return 0;
}

