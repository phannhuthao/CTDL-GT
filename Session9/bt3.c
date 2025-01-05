#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, bool isDirected) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if (!isDirected) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

bool dfsCycle(struct Graph* graph, int v, int parent, bool isDirected) {
    graph->visited[v] = true;

    struct Node* adj = graph->adjLists[v];
    while (adj != NULL) {
        int adjVertex = adj->vertex;

        if (!graph->visited[adjVertex]) {
            if (dfsCycle(graph, adjVertex, v, isDirected)) {
                return true;
            }
        } else if ((adjVertex != parent && !isDirected) || isDirected) {
            return true;
        }

        adj = adj->next;
    }

    return false;
}

bool hasCycle(struct Graph* graph, bool isDirected) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = false;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (dfsCycle(graph, i, -1, isDirected)) {
                return true;
            }
        }
    }
    return false;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("\nAdjacency list of vertex %d\n", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    printf("Nhap so luong dinh: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("So luong dinh khong hop le.\n");
        return 1;
    }

    printf("Nhap so luong canh: ");
    scanf("%d", &m);

    if (m < 0) {
        printf("So luong canh khong hop le.\n");
        return 1;
    }

    bool isDirected;
    printf("Do thi co huong khong? (1: Co, 0: Khong): ");
    scanf("%d", &isDirected);

    struct Graph* graph = createGraph(n);

    printf("Nhap danh sach cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v, isDirected);
    }

    printGraph(graph);

    if (hasCycle(graph, isDirected)) {
        printf("Do thi co chu ky.\n");
    } else {
        printf("Do thi khong co chu ky.\n");
    }

    for (int i = 0; i < n; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);

    return 0;
}
