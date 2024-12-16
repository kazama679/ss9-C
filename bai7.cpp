#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int graph[MAX][MAX], visited[MAX], degree[MAX], vertices, edges;

void addEdge(int u, int v) {
    graph[u][v] = graph[v][u] = 1;
    degree[u]++;
    degree[v]++;
}

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && !visited[i]) dfs(i);
    }
}

int isConnected() {
    for (int i = 0; i < vertices; i++) visited[i] = 0;
    int start = -1;
    for (int i = 0; i < vertices; i++) if (degree[i] > 0) { start = i; break; }
    if (start == -1) return 1;
    dfs(start);
    for (int i = 0; i < vertices; i++) if (degree[i] > 0 && !visited[i]) return 0;
    return 1;
}

int hasEulerCycle() {
    for (int i = 0; i < vertices; i++) if (degree[i] % 2 != 0) return 0;
    return isConnected();
}

void eulerCycle(int v) {
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i]) {
            graph[v][i] = graph[i][v] = 0;
            eulerCycle(i);
        }
    }
    printf("%d ", v);
}

int main() {
    int u, v;
    printf("Nhap so dinh: "); scanf("%d", &vertices);
    printf("Nhap so canh: "); scanf("%d", &edges);
    for (int i = 0; i < vertices; i++) degree[i] = 0;
    for (int i = 0; i < edges; i++) { scanf("%d %d", &u, &v); addEdge(u, v); }
    if (hasEulerCycle()) { printf("Chu trinh Euler: "); eulerCycle(0); }
    else printf("Do thi khong co chu trinh Euler");
    return 0;
}
