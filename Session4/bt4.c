#include <stdio.h>
#include <stdlib.h>

struct Node {
    int n;
    struct Node* next;
};

struct Node * addN(struct Node * head, int value) {
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> n= value;
    newNode -> next= head;
    return 	newNode;
}

int search(struct Node* head, int value) {
    int index = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->n == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}


int show(struct Node* node) {
    while(node != NULL) {
        printf("%d ", node -> n);
        node = node -> next;
    }

    printf(" NULL\n");
}


int main() {
    int n;
    struct Node* head = NULL;

    printf("Nhap vào n (0<=n<=1000) phan tu danh sach lien ket ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("Gia tri nhap khong hop le\n");
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

    int s;

    printf("Nhap gia tri tim kiem: ");
    scanf("%d", &s);

    int result = search(head, s);

    if (result != -1) {
        printf("Gia tri %d xuat hien o vi tri: %d\n", s, result);
    } else {
        printf("Gia tri %d khong ton tai trong danh sach\n", s);
    }



    return 0;
}
