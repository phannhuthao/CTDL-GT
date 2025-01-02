#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (root->left == NULL) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void findLevel2Nodes(struct Node* root) {
    if (root == NULL) {
        printf("Cây rỗng, không có đỉnh lớp 2.\n");
        return;
    }

    if (root->left != NULL) {
        if (root->left->left != NULL) printf("%d ", root->left->left->data);
        if (root->left->right != NULL) printf("%d ", root->left->right->data);
    }

    if (root->right != NULL) {
        if (root->right->left != NULL) printf("%d ", root->right->left->data);
        if (root->right->right != NULL) printf("%d ", root->right->right->data);
    }
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value;


    printf("Nhập số lượng nút trong cây: ");
    scanf("%d", &n);


    printf("Nhập giá trị các nút:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nCấu trúc cây (duyệt Tiền Thứ Tự):\n");
    preOrder(root);
    printf("\n");

    printf("Các đỉnh lớp 2:\n");
    findLevel2Nodes(root);
    printf("\n");

    return 0;
}
