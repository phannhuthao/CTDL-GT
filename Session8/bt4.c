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
    char direction;
    printf("Chèn %d vào bên trái (L) hay bên phải (R) của %d? ", data, root->data);
    scanf(" %c", &direction);
    if (direction == 'L' || direction == 'l') {
        root->left = insert(root->left, data);
    } else if (direction == 'R' || direction == 'r') {
        root->right = insert(root->right, data);
    } else {
        printf("Hướng không hợp lệ. Giá trị không được chèn.\n");
    }
    return root;
}

int calculateHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
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

    printf("Nhập số lượng nút trong cây: ");
    scanf("%d", &n);

    printf("Nhập giá trị các nút (bắt đầu từ gốc):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (i == 0) {
            root = createNode(value);
        } else {
            root = insert(root, value);
        }
    }

    printf("\nCấu trúc cây (duyệt Inorder):\n");
    inorderTraversal(root);
    printf("\n");


    int height = calculateHeight(root);
    printf("Chiều cao của cây: %d\n", height);

    return 0;
}
