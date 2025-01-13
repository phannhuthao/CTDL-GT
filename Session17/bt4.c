#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

Node* createBinaryTree(int n) {
    Node* root = NULL;
    for (int i = 1; i <= n; i++) {
        insert(&root, i);
    }
    return root;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

#define MAX 1000

void createGraph(int n, int edges[][2], int edgeCount, int adjacencyList[][MAX]) {
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjacencyList[u][v] = 1;
        adjacencyList[v][u] = 1;
    }
}

void DFS(int start, int visited[], int adjacencyList[][MAX], int size) {
    visited[start] = 1;
    for (int i = 0; i < size; i++) {
        if (adjacencyList[start][i] == 1 && !visited[i]) {
            DFS(i, visited, adjacencyList, size);
        }
    }
}

void BFS(int start, int visited[], int adjacencyList[][MAX], int size) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < size; i++) {
            if (adjacencyList[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void measureTime(Node* root, int adjacencyList[][MAX], int size) {
    clock_t start, end;
    double timeTaken;

    printf("\nDuyệt cây:\n");
    start = clock();
    preOrder(root);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nThời gian pre-order: %.6f giây\n", timeTaken);

    start = clock();
    inOrder(root);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Thời gian in-order: %.6f giây\n", timeTaken);

    start = clock();
    postOrder(root);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Thời gian post-order: %.6f giây\n", timeTaken);

    printf("\nDuyệt đồ thị:\n");
    int visited[MAX] = {0};

    start = clock();
    DFS(0, visited, adjacencyList, size);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nThời gian DFS: %.6f giây\n", timeTaken);

    for (int i = 0; i < MAX; i++) visited[i] = 0;

    start = clock();
    BFS(0, visited, adjacencyList, size);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Thời gian BFS: %.6f giây\n", timeTaken);
}

int main() {
    int n, edgeCount;
    printf("Nhập số lượng nút: ");
    scanf("%d", &n);

    printf("Nhập số lượng cạnh: ");
    scanf("%d", &edgeCount);

    Node* root = createBinaryTree(n);

    int edges[MAX][2];
    printf("Nhập các cạnh (dạng u v):\n");
    for (int i = 0; i < edgeCount; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int adjacencyList[MAX][MAX] = {0};
    createGraph(n, edges, edgeCount, adjacencyList);

    measureTime(root, adjacencyList, n);

    return 0;
}
