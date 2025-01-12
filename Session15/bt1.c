#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Node* adjList[MAX_VERTICES];
bool visited[MAX_VERTICES];

typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1)
        printf("Hang doi day\n");
    else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Lấy phần tử khỏi hàng đợi
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Hàm BFS
void bfs(int startVertex) {
    Queue* q = createQueue();

    visited[startVertex] = true;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node* temp = adjList[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int V, E;
    printf("So dinh: ");
    scanf("%d", &V);
    printf("So canh: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = false;
    }

    printf("Danh sach canh (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    int start;
    printf("Dinh bat dau: ");
    scanf("%d", &start);

    printf("Thu tu duyet BFS: ");
    bfs(start);

    return 0;
}
