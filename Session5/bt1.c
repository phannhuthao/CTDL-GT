#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
};

struct Node* add(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->previous = temp;

    return head;
}

void show(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void showReverse(struct Node* head) {
    if (head == NULL) {
        printf("Danh sách rỗng.\n");
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->previous;
    }
    printf("NULL\n");
}

int main() {
    int n, value;
    struct Node* head = NULL;

    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    printf("Nhập các phần tử:\n");
    for (int i = 0; i < n; i++) {
        printf("Phần tử %d: ", i + 1);
        scanf("%d", &value);
        head = add(head, value);
    }

    printf("Danh sách phần tử đã nhập: ");
    show(head);

    printf("Danh sách từ cuối về đầu: ");
    showReverse(head);

    return 0;
}
