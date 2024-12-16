#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

typedef struct {
    int vertex, g, f;
} Node;

typedef struct {
    Node nodes[MAX];
    int size;
} PriorityQueue;

int graph[MAX][MAX], heuristic[MAX], visited[MAX], parent[MAX], vertices;
int start, goal;

void initGraph() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) graph[i][j] = 0;
        heuristic[i] = 0, visited[i] = 0, parent[i] = -1;
    }
}

void addEdge(int u, int v, int weight) {
    graph[u][v] = weight;
    graph[v][u] = weight;
}

void push(PriorityQueue *pq, int vertex, int g, int f) {
    pq->nodes[pq->size].vertex = vertex;
    pq->nodes[pq->size].g = g;
    pq->nodes[pq->size++].f = f;
}

Node pop(PriorityQueue *pq) {
    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) if (pq->nodes[i].f < pq->nodes[minIndex].f) minIndex = i;
    Node minNode = pq->nodes[minIndex];
    pq->nodes[minIndex] = pq->nodes[--pq->size];
    return minNode;
}

int isEmpty(PriorityQueue *pq) { return pq->size == 0; }

void printPath(int current) {
    if (parent[current] != -1) printPath(parent[current]);
    printf("%d ", current);
}

void aStar() {
    PriorityQueue pq = {0};
    push(&pq, start, 0, heuristic[start]);

    while (!isEmpty(&pq)) {
        Node current = pop(&pq);
        int u = current.vertex;

        if (u == goal) {
            printf("Duong di ngan nhat tu %d den %d la: ", start, goal);
            printPath(goal);
            printf("\nTong chi phi: %d\n", current.g);
            return;
        }

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !visited[v]) {
                int g = current.g + graph[u][v];
                int f = g + heuristic[v];
                push(&pq, v, g, f);
                if (parent[v] == -1) parent[v] = u;
            }
        }
    }
    printf("Khong tim thay duong di tu %d den %d.\n", start, goal);
}

int main() {
    int edges, u, v, weight;
    printf("Nhap so dinh: "); scanf("%d", &vertices);
    printf("Nhap so canh: "); scanf("%d", &edges);
    initGraph();

    printf("Nhap cac canh va trong so (u v trong so):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(u, v, weight);
    }

    printf("Nhap gia tri heuristic:\n");
    for (int i = 0; i < vertices; i++) scanf("%d", &heuristic[i]);

    printf("Nhap dinh bat dau: "); scanf("%d", &start);
    printf("Nhap dinh dich: "); scanf("%d", &goal);

    aStar();
    return 0;
}
