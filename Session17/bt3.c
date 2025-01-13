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

// Hàm chèn giá trị vào cây nhị phân tìm kiếm
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

void convertTreeToGraph(Node* root, int adjacencyList[][100], int* size) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL) {
        adjacencyList[root->data][root->left->data] = 1;
        adjacencyList[root->left->data][root->data] = 1;
        convertTreeToGraph(root->left, adjacencyList, size);
    }

    if (root->right != NULL) {
        adjacencyList[root->data][root->right->data] = 1;
        adjacencyList[root->right->data][root->data] = 1;
        convertTreeToGraph(root->right, adjacencyList, size);
    }
}

void DFS(int start, int visited[], int adjacencyList[][100], int size) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < size; i++) {
        if (adjacencyList[start][i] == 1 && !visited[i]) {
            DFS(i, visited, adjacencyList, size);
        }
    }
}

void BFS(int start, int visited[], int adjacencyList[][100], int size) {
    int queue[100], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < size; i++) {
            if (adjacencyList[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
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


    int adjacencyList[100][100] = {0};
    convertTreeToGraph(root, adjacencyList, &n);

    int visited[100] = {0};

    printf("\nDuyệt đồ thị bằng DFS: ");
    DFS(root->data, visited, adjacencyList, 100);

    for (int i = 0; i < 100; i++) visited[i] = 0;

    printf("\nDuyệt đồ thị bằng BFS: ");
    BFS(root->data, visited, adjacencyList, 100);

    return 0;
}
