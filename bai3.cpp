#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX]; 
int visited[MAX]; 
int recStack[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v, int isDirected) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    if (!isDirected) { 
        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
}

void initGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }
}

int dfsDirected(int v) {
    visited[v] = 1; 
    recStack[v] = 1; 
    Node* temp = adjList[v];
    while (temp != NULL) {
        int u = temp->vertex;
        if (!visited[u] && dfsDirected(u)) {
            return 1; 
        } else if (recStack[u]) {
            return 1; 
        }
        temp = temp->next;
    }
    recStack[v] = 0; 
    return 0;
}

int dfsUndirected(int v, int parent) {
    visited[v] = 1;
    Node* temp = adjList[v];
    while (temp != NULL) {
        int u = temp->vertex;
        if (!visited[u]) {
            if (dfsUndirected(u, v)) {
                return 1;
            }
        } else if (u != parent) {
            return 1; 
        }
        temp = temp->next;
    }
    return 0;
}

void checkCycle(int vertices, int isDirected) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    int hasCycle = 0;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (isDirected) {
                hasCycle = dfsDirected(i);
            } else {
                hasCycle = dfsUndirected(i, -1);
            }
            if (hasCycle) break;
        }
    }
    if (hasCycle) {
        printf("Do thi co chu ky.\n");
    } else {
        printf("Do thi khong co chu ky.\n");
    }
}

int main() {
    int vertices, edges, isDirected;
    printf("Do thi co huong (1) hay vo huong (0): ");
    scanf("%d", &isDirected);
    printf("Nhap so luong dinh: ");
    scanf("%d", &vertices);
    printf("Nhap so luong canh: ");
    scanf("%d", &edges);
    initGraph(vertices);
    printf("Nhap cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Canh %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v, isDirected);
    }
    checkCycle(vertices, isDirected);
    return 0;
}
