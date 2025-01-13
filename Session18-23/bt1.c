#include <stdio.h>

#define MAX_SIZE 100


void initializeArray(int arr[], int *size) {
    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", size);
    printf("Nhập các phần tử của mảng:\n");
    for (int i = 0; i < *size; i++) {
        printf("Phần tử %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void addElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Mảng đã đầy, không thể thêm phần tử!\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    printf("Đã thêm phần tử %d tại vị trí %d.\n", element, position + 1);
]

void removeElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Đã xóa phần tử tại vị trí %d.\n", position + 1);
}

int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void updateElement(int arr[], int size, int position, int newValue) {
    if (position < 0 || position >= size) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }
    arr[position] = newValue;
    printf("Đã cập nhật phần tử tại vị trí %d thành %d.\n", position + 1, newValue);
}

// Hàm in các phần tử của mảng
void printArray(int arr[], int size) {
    printf("Các phần tử của mảng: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    initializeArray(arr, &size);
    printArray(arr, size);

    int choice, element, position;

    do {
        printf("\nChọn thao tác:\n");
        printf("1. Thêm phần tử\n");
        printf("2. Xóa phần tử\n");
        printf("3. Tìm kiếm phần tử\n");
        printf("4. Cập nhật phần tử\n");
        printf("5. In mảng\n");
        printf("6. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập phần tử cần thêm: ");
                scanf("%d", &element);
                printf("Nhập vị trí cần thêm (bắt đầu từ 1): ");
                scanf("%d", &position);
                addElement(arr, &size, element, position - 1);
                break;

            case 2:
                printf("Nhập vị trí cần xóa (bắt đầu từ 1): ");
                scanf("%d", &position);
                removeElement(arr, &size, position - 1);
                break;

            case 3:
                printf("Nhập phần tử cần tìm: ");
                scanf("%d", &element);
                position = searchElement(arr, size, element);
                if (position != -1) {
                    printf("Phần tử %d được tìm thấy tại vị trí %d.\n", element, position + 1);
                } else {
                    printf("Không tìm thấy phần tử %d trong mảng.\n", element);
                }
                break;

            case 4:
                printf("Nhập vị trí cần cập nhật (bắt đầu từ 1): ");
                scanf("%d", &position);
                printf("Nhập giá trị mới: ");
                scanf("%d", &element);
                updateElement(arr, size, position - 1, element);
                break;

            case 5:
                printArray(arr, size);
                break;

            case 6:
                printf("Thoát chương trình.\n");
                break;

            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 6);

    return 0;
}
