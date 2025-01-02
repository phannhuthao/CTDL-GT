#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) {
        return 1;
    }

    if (root->data <= min || root->data >= max) {
        return 0;
    }

    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
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


void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value;


    printf("Nhập số lượng phần tử trong cây: ");
    scanf("%d", &n);


    if (n == 0) {
        printf("Cây rỗng là cây nhị phân tìm kiếm (BST).\n");
        return 0;
    }


    printf("Nhập các giá trị cho cây:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }


    printf("Duyệt cây theo thứ tự inorder: ");
    inorderTraversal(root);
    printf("\n");


    if (isBST(root)) {
        printf("Cây là cây nhị phân tìm kiếm (BST).\n");
    } else {
        printf("Cây không phải là cây nhị phân tìm kiếm (BST).\n");
    }

    return 0;
}
