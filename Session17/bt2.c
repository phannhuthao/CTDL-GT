#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }

    if (value < (*root)->data) {
        insert(&(*root)->left, value);
    } else {
        insert(&(*root)->right, value);
    }
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n, value;
    Node* root = NULL;

    printf("Nhập số lượng nút trong cây: ");
    scanf("%d", &n);

    printf("Nhập các giá trị cần chèn vào cây:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&root, value);
    }

    printf("\nDuyệt cây theo thứ tự pre-order: ");
    preOrder(root);

    printf("\nDuyệt cây theo thứ tự in-order: ");
    inOrder(root);

    printf("\nDuyệt cây theo thứ tự post-order: ");
    postOrder(root);

    freeTree(root);
    return 0;
}
