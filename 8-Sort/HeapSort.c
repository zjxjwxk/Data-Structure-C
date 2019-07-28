#include <stdio.h>
#include <stdlib.h>

/*
 * 堆排序
 */

// 对在low位置的结点向下调整
void Sift(int R[], int low, int high) {
	int i = low;
	int j = 2 * i;
	int temp = R[i];
	while (j <= high) {
		if (j < high && R[j] < R[j + 1]) {
			++j;
		}
		if (temp < R[j]) {
			R[i] = R[j];
			i = j;
			j = 2 * i;
		} else {
			break;
		}
	}
	R[i] = temp;
}

// 堆排序算法
void heapSort(int R[], int n) {
	int i;
	int temp;
	for (i = n/2; i >= 1; --i) {
		Sift(R, i, n);
	}
	for (i = n; i >= 2; --i) {
		temp = R[1];
		R[1] = R[i];
		R[i] = temp;
		Sift(R, 1, i - 1);
	}
}

void printR(int R[], int n) {
	int i;
	for (i = 0; i < n; ++i) {
		printf("%d ", R[i]);
	}
	printf("\n");
}

int main() {
	int R[] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
	printf("排序前: ");printR(R, 9);
	heapSort(R, 9);	
	printf("排序后: ");printR(R, 9);
	return 0;
}