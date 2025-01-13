#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createList() {
    return NULL;
}

void addAtHead(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("Đã thêm %d vào đầu danh sách.\n", value);
}

void addAtTail(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Đã thêm %d vào cuối danh sách.\n", value);
}

void deleteAtPosition(Node **head, int position) {
    if (*head == NULL) {
        printf("Danh sách rỗng, không thể xóa!\n");
        return;
    }
    if (position < 0) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }
    Node *temp = *head;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        printf("Đã xóa phần tử tại vị trí 1.\n");
        return;
    }


    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Đã xóa phần tử tại vị trí %d.\n", position + 1);
}


Node *searchElement(Node *head, int value) {
    Node *temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Phần tử %d được tìm thấy tại vị trí %d.\n", value, position + 1);
            return temp;
        }
        temp = temp->next;
        position++;
    }
    printf("Không tìm thấy phần tử %d trong danh sách.\n", value);
    return NULL;
}


void updateElement(Node *head, int position, int newValue) {
    if (position < 0) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }
    Node *temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }
    temp->data = newValue;
    printf("Đã cập nhật giá trị tại vị trí %d thành %d.\n", position + 1, newValue);
}


void printList(Node *head) {
    if (head == NULL) {
        printf("Danh sách rỗng.\n");
        return;
    }
    printf("Các phần tử trong danh sách: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *list = createList();
    int choice, value, position;

    do {
        printf("\nChọn thao tác:\n");
        printf("1. Thêm phần tử vào đầu\n");
        printf("2. Thêm phần tử vào cuối\n");
        printf("3. Xóa phần tử tại vị trí\n");
        printf("4. Tìm kiếm phần tử\n");
        printf("5. Cập nhật phần tử\n");
        printf("6. In danh sách\n");
        printf("7. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập giá trị cần thêm vào đầu: ");
                scanf("%d", &value);
                addAtHead(&list, value);
                break;

            case 2:
                printf("Nhập giá trị cần thêm vào cuối: ");
                scanf("%d", &value);
                addAtTail(&list, value);
                break;

            case 3:
                printf("Nhập vị trí cần xóa (bắt đầu từ 1): ");
                scanf("%d", &position);
                deleteAtPosition(&list, position - 1);
                break;

            case 4:
                printf("Nhập giá trị cần tìm: ");
                scanf("%d", &value);
                searchElement(list, value);
                break;

            case 5:
                printf("Nhập vị trí cần cập nhật (bắt đầu từ 1): ");
                scanf("%d", &position);
                printf("Nhập giá trị mới: ");
                scanf("%d", &value);
                updateElement(list, position - 1, value);
                break;

            case 6:
                printList(list);
                break;

            case 7:
                printf("Thoát chương trình.\n");
                break;

            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 7);

    return 0;
}
