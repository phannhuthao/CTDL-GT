#include <stdio.h>
#include <stdlib.h>

struct Node {
    int n;
    struct Node* next;
};

struct Node* addN(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->n = value;
    newNode->next = head;
    return newNode;
}

void show(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->n);
        node = node->next;
    }
    printf("NULL\n");
}

struct Node* insertAt(struct Node* head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->n = value;

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    int index = 0;

    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL) {
        printf("Vi tri nam ngoai pham vi danh sach\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

int main() {
    struct Node* head = NULL;

    head = addN(head, 30);
    head = addN(head, 20);
    head = addN(head, 10);

    printf("Danh sach ban dau: ");
    show(head);

    int value = 25;
    int position = 2;

    head = insertAt(head, value, position);

    printf("Danh sach sau khi chen: ");
    show(head);

    return 0;
}
