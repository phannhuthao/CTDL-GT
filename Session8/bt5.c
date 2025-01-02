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

int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0; // Không tìm thấy
    }
    if (root->data == key) {
        return 1; // Tìm thấy
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Hàm duyệt cây theo thứ tự inorder
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, key;


    printf("Nhập số lượng phần tử cần chèn vào cây: ");
    scanf("%d", &n);

    printf("Nhập các giá trị để chèn vào cây BST:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }


    printf("Duyệt cây theo thứ tự inorder: ");
    inorderTraversal(root);
    printf("\n");

    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &key);
    if (search(root, key)) {
        printf("Giá trị %d được tìm thấy trong cây.\n", key);
    } else {
        printf("Giá trị %d không tồn tại trong cây.\n", key);
    }

    return 0;
}
