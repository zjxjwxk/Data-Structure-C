#include <stdio.h>
#include <stdlib.h>

#define maxSize 10

/*
 * 矩阵
 */

// 矩阵转置
void trsmat(int A[][5], int B[][4], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			B[j][i] = A[i][j];
		}
	}
}

// 矩阵相加
void addmat(int C[][4], int A[][4], int B[][4], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

// 矩阵相乘
void mutmat(int C[][4], int A[][5], int B[][4], int m, int n, int k) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			C[i][j] = 0;
			for (int h = 0; h < n; ++h) {
				C[i][j] += A[i][h] * B[h][j];
			}
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
	printf("\n");
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
	int C[5][4];
	addmat(C, B, B, 5, 4);
	printMatrix(C, 5, 4);
	int D[4][4];
	mutmat(D, A, B, 4, 5, 4);
	printMatrix(D, 4, 4);
	return 0;
}