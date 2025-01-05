#include <stdio.h>

#define MAX 100

void calculateDegree(int graph[MAX][MAX], int n, int isDirected) {
    int degrees[MAX] = {0};
    int maxDegree = 0;
    int maxVertex = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                degrees[i]++;
                if (!isDirected) {
                    degrees[j]++;
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        if (degrees[i] > maxDegree) {
            maxDegree = degrees[i];
            maxVertex = i;
        }
    }

    printf("Bậc của các đỉnh:\n");
    for (int i = 0; i < n; i++) {
        printf("Đỉnh %d: %d\n", i, degrees[i]);
    }

    printf("Đỉnh có bậc lớn nhất là: %d\n", maxVertex);
}

int main() {
    int n, e, isDirected;
    int graph[MAX][MAX] = {0};

    printf("Nhập số đỉnh: ");
    scanf("%d", &n);

    printf("Nhập số cạnh: ");
    scanf("%d", &e);

    printf("Đồ thị có hướng? (1: Có hướng, 0: Vô hướng): ");
    scanf("%d", &isDirected);

    printf("Nhập các cạnh (định dạng: u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        if (!isDirected) {
            graph[v][u] = 1;
        }
    }

    calculateDegree(graph, n, isDirected);

    return 0;
}
