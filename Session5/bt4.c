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

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
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

    int count = countNodes(head);
    printf("S? lu?ng ph?n t? trong danh sách: %d\n", count);


    return 0;
}
