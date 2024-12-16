#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int inDegree[MAX], outDegree[MAX];
int vertices;

void initGraph() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        inDegree[i] = 0;
        outDegree[i] = 0;
    }
}

void addEdge(int u, int v, int isDirected) {
    graph[u][v] = 1;
    if (!isDirected) graph[v][u] = 1;
}

void calculateDegrees(int isDirected) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j]) {
                if (isDirected) {
                    outDegree[i]++;
                    inDegree[j]++;
                } else {
                    outDegree[i]++;
                }
            }
        }
    }
}

void findMaxDegree(int isDirected) {
    int maxDegree = 0, maxVertex = -1;
    for (int i = 0; i < vertices; i++) {
        int degree = isDirected ? (inDegree[i] + outDegree[i]) : outDegree[i];
        if (degree > maxDegree) {
            maxDegree = degree;
            maxVertex = i;
        }
    }
    printf("Dinh co bac cao nhat la: %d\n", maxVertex);
}

int main() {
    int edges, u, v, isDirected;
    printf("Do thi co huong (1) hay vo huong (0): ");
    scanf("%d", &isDirected);
    printf("Nhap so dinh: ");
    scanf("%d", &vertices);
    printf("Nhap so canh: ");
    scanf("%d", &edges);
    initGraph();
    printf("Nhap cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v, isDirected);
    }
    calculateDegrees(isDirected);
    findMaxDegree(isDirected);
    return 0;
}
