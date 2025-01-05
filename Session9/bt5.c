#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

int minDistance(int dist[], int visited[], int n) {
    int min = INF, minIndex;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int** graph, int n, int src) {
    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;


        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Khoảng cách ngắn nhất từ đỉnh %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Đỉnh %d: Không thể tới được\n", i);
        else
            printf("Đỉnh %d: %d\n", i, dist[i]);
    }
}

int main() {
    int n, e;

    printf("Nhập số lượng đỉnh: ");
    scanf("%d", &n);

    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhập số lượng cạnh: ");
    scanf("%d", &e);

    printf("Nhập các cạnh với trọng số (định dạng: u v w):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // Lưu trọng số cạnh u -> v
        graph[v][u] = w; // Nếu đồ thị vô hướng
    }

    int src;
    printf("Nhập đỉnh nguồn: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
