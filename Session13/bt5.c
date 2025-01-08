#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int swapped;
    int iteration = 0;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        iteration++;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;

                printf("Sau khi hoan doi %d và %d: ", arr[j + 1], arr[j]);
                for (int k = 0; k < n; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }

        if (swapped == 0) {
            break;
        }
    }

    printf("Sap xep hoan thanh sau %d lan lap.\n", iteration);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);
    printf("Mang da sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
