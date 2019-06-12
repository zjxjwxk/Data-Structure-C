#include <stdio.h>
#include <stdlib.h>

/*
 * 稀疏矩阵的三元组表示法
 */

void createtrimat(float A[][4], int m, int n, float B[][3]) {
	int k = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (A[i][j] != 0) {
				B[k][0] = A[i][j];
				B[k][1] = i;
				B[k][2] = j;
				++k;
			}
		}
	}
	B[0][0] = k - 1;
	B[0][1] = m;
	B[0][2] = n;
}

// 通过三元组打印矩阵
void print(float B[][3]) {
	int k = 1;
	for (int i = 0; i < (int) B[0][1]; ++i) {
		for (int j = 0; j < (int) B[0][2]; ++j) {
			if (i == (int) B[k][1] && j == (int) B[k][2]) {
				printf("%f ", B[k][0]);
				++k;
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

int main() {
	float A[5][4] = {
		{1.1, 0, 2.1, 1.1},
		{3.2, 1.2, 0, 0},
		{2.3, 0, 4.3, 6.0},
		{0, 0, 1.2, 2.3},
		{1.4, 0, 3.5, 2.6},
	};
	float B[21][3];
	createtrimat(A, 5, 4, B);
	printf("打印三元组\n");
	for (int i = 0; i < B[0][0] + 1; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%f ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("通过三元组打印原矩阵\n");
	print(B);
	return 0;
}