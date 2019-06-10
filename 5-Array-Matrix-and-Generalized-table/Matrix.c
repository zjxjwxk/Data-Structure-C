#include <stdio.h>
#include <stdlib.h>

#define maxSize 10

void trsmat(int A[][5], int B[][4], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			B[j][i] = A[i][j];
		}
	}
}

void printMatrix(int matrix[][4], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int A[4][5] = {
		{1, 1, 1, 1, 1},
		{2, 2, 2, 2, 2},
		{3, 3, 3, 3, 3},
		{4, 4, 4, 4, 4}
	};
	int B[5][4];
	trsmat(A, B, 4, 5);
	int m = sizeof(B) / sizeof(B[0]);
	int n = sizeof(B[0]) / sizeof(B[0][0]);
	printMatrix(B, m, n);
	return 0;
}