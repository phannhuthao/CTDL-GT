#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode {
    int vertex;
    struct AdjListNode* next;
} AdjListNode;


typedef struct {
    int vertices;
    int** adjMatrix;
    AdjListNode** adjList;
    int isDirected;
} Graph;


Graph* createGraph(int vertices, int isDirected) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->isDirected = isDirected;

    // Khởi tạo ma trận kề
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }


    graph->adjList = (AdjListNode**)malloc(vertices * sizeof(AdjListNode*));
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}


AdjListNode* createAdjListNode(int vertex) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}


void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    if (!graph->isDirected) {
        graph->adjMatrix[dest][src] = 1;
    }

    AdjListNode* newNode = createAdjListNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    if (!graph->isDirected) {
        newNode = createAdjListNode(src);
        newNode->next = graph->adjList[dest];
        graph->adjList[dest] = newNode;
    }
}

void printAdjMatrix(Graph* graph) {
    printf("Ma trận kề:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printAdjList(Graph* graph) {
    printf("Danh sách kề:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d:", i);
        AdjListNode* temp = graph->adjList[i];
        while (temp) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Giải phóng bộ nhớ cho đồ thị
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);

        AdjListNode* temp = graph->adjList[i];
        while (temp) {
            AdjListNode* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjMatrix);
    free(graph->adjList);
    free(graph);
}

int main() {
    int vertices, edges, isDirected;
    printf("Nhập số lượng đỉnh: ");
    scanf("%d", &vertices);
    printf("Đồ thị có hướng? (1: Có, 0: Không): ");
    scanf("%d", &isDirected);

    // Tạo đồ thị
    Graph* graph = createGraph(vertices, isDirected);

    printf("Nhập số lượng cạnh: ");
    scanf("%d", &edges);
    printf("Nhập các cạnh (dạng src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printAdjMatrix(graph);
    printAdjList(graph);

    freeGraph(graph);

    return 0;
}
