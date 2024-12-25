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
        printf("Danh sach rong.\n");
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

struct Node* reverseList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->previous;
        current->previous = current->next;
        current->next = temp;
        current = current->previous;
    }

    if (temp != NULL) {
        head = temp->previous;
    }

    return head;
}


struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("Danh sach rong, không the xoa.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->previous->next = NULL;
    free(temp);

    return head;
}

int main() {
    int n, value;
    struct Node* head = NULL;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &value);
        head = add(head, value);
    }

    printf("Danh sach phan tu da nhap: ");
    show(head);

    printf("Danh sach tu cuoi va dau: ");
    showReverse(head);

    printf("Danh sách phan tu sau khi dã xóa phan ta cuoi: ");
    head = deleteLast(head);
    show(head);

    head = reverseList(head);

    printf("Danh sach sau khi dao nguoc: ");
    show(head);


    return 0;
}

