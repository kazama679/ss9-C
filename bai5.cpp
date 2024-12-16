#include <stdio.h>
#include <limits.h>
#define MAX 100

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int vertices;

void initGraph() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
}

int findMinVertex() {
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int src) {
    dist[src] = 0;
    for (int count = 0; count < vertices - 1; count++) {
        int u = findMinVertex();
        visited[u] = 1;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int edges, u, v, w, src;
    printf("Nhap so luong dinh: ");
    scanf("%d", &vertices);
    printf("Nhap so luong canh: ");
    scanf("%d", &edges);
    initGraph();
    printf("Nhap cac canh voi trong so (dinh1 dinh2 trong so):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    printf("Nhap dinh nguon: ");
    scanf("%d", &src);
    dijkstra(src);
    printf("Khoang cach ngan nhat tu dinh %d:\n", src);
    for (int i = 0; i < vertices; i++) {
        printf("Dinh %d: %d\n", i, dist[i]);
    }
    return 0;
}
