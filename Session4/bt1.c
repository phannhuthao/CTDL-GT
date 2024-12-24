#include <stdio.h>
#include <stdlib.h>

struct Node {
    int n;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->n = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

int show(struct Node* node) {
    while(node != NULL) {
        printf("%d ", node -> n);
        node = node -> next;
    }

    printf(" NULL\n");
}

int freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}


int main() {
    int n;
    struct Node* head = NULL;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Danh sach lien ket: ");
    show(head);

    freeList(head);


    return 0;
}
