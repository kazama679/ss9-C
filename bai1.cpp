#include<stdio.h>
#define V 3

void addEdge(int matrix[V][V], int i, int j){
	matrix[i][j] = 1;
//	matrix[j][i] = 1;
} 

void printMatrix(int matrix[V][V]){
	for(int i = 0; i< V; i++){
		for(int j=0; j<V; j++){
			printf("%d\t", matrix[i][j]); 
		} 
		printf("\n"); 
	} 
} 

void addEdge2(int matrix[V][V], int i, int j){
	matrix[i][j] = 1;
	matrix[j][i] = 1;
} 

void printMatrix2(int matrix[V][V]){
	for(int i = 0; i< V; i++){
		for(int j=0; j<V; j++){
			printf("%d\t", matrix[i][j]); 
		} 
		printf("\n"); 
	} 
} 

int main(){
	int matrix[V][V] = {0};
	int matrix2[V][V] = {0};
	addEdge(matrix, 0, 2);
	addEdge(matrix, 1, 2);
	addEdge(matrix, 2, 1);
	printf("do thi co huong: \n"); 
	printMatrix(matrix);
	
	addEdge2(matrix2, 0, 2);
	addEdge2(matrix2, 1, 2);
	printf("\ndo thi vo huong: \n"); 
	printMatrix2(matrix2);
	
	return 0;
}
