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
    if (node == NULL) {
        printf("Danh sach trong\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->n);
        node = node->next;
    }
    printf("NULL\n");
}

struct Node* deleteHead(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Nhap vao so luong phan tu: (0 <= n <= 1000): ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("Gia tri nhap khong hop le\n");
        return 0;
    }

    if (n == 0) {
        printf("Danh sach trong\n");
        return 0;
    }

    printf("Nhap %d phan tu cua danh sach: ", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        head = addN(head, value);
    }

    printf("Danh sach hien tai: ");
    show(head);

    head = deleteHead(head);

    printf("Danh sach sau khi xoa phan tu dau: ");
    show(head);

    return 0;
}
