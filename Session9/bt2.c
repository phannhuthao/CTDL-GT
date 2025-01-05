#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int vertex1;
    int vertex2;
};

int main() {
    int n, m;

    printf("Nhap so luong dinh: ");
    scanf("%d", &n);

    printf("Nhap so luong canh: ");
    scanf("%d", &m);

    struct Edge *edges = (struct Edge *)malloc(m * sizeof(struct Edge));

    printf("Nhap danh sach cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edges[i].vertex1, &edges[i].vertex2);
    }

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].vertex1;
        int v = edges[i].vertex2;

        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    free(edges);
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
