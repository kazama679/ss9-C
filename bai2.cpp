#include <stdio.h>
#include <stdlib.h>

void addEdge(int **matrix, int i, int j) {
    matrix[i][j] = 1;
    matrix[j][i] = 1; 
}

void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    printf("Nhap vao so luong dinh: ");
    scanf("%d", &n);
    printf("Nhap vao so luong canh: ");
    scanf("%d", &m);
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)calloc(n, sizeof(int));
    }
    printf("Nhap vao cac canh (dinh1 dinh2):\n");
    for (int k = 0; k < m; k++) {
        int u, v;
        printf("Canh %d: ", k + 1);
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            addEdge(matrix, u, v);
        } else {
            printf("Canh khong hop le, vui long nhap lai!\n");
            k--;
        }
    }
    printf("\nMa tran ke cua do thi:\n");
    printMatrix(matrix, n);
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
