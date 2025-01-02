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
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}


int search(struct Node* root, int x) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == x) {
        return 1;
    }
    if (x < root->data) {
        return search(root->left, x);
    } else {
        return search(root->right, x);
    }
}


void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, searchValue;

    printf("Nhập số lượng nút trong cây: ");
    scanf("%d", &n);

    printf("Nhập giá trị các nút:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }


    printf("\nCấu trúc cây (duyệt Inorder):\n");
    inorderTraversal(root);
    printf("\n");

    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &searchValue);
    if (search(root, searchValue)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
