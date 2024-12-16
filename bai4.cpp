#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) return -1;
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void initGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
}

void bfs(int startVertex, int vertices) {
    Queue* q = createQueue();
    visited[startVertex] = 1;
    enqueue(q, startVertex);
    printf("Thu tu duyet BFS: ");
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node* temp = adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, startVertex;
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
        addEdge(u, v);
    }
    printf("Nhap dinh bat dau: ");
    scanf("%d", &startVertex);
    bfs(startVertex, vertices);
    return 0;
}
