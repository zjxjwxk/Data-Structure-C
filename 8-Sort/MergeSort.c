#include <stdio.h>
#include <stdlib.h>

/*
 * 归并排序
 */

void merge(int A[], int low, int mid, int high) {
	int B[high - low + 1];
	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high) {
		if (A[i] <= A[j]) {
			B[k++] = A[i++];
		} else {
			B[k++] = A[j++];
		}
	}
	while (i <= mid) {
		B[k++] = A[i++];
	}
	while (j <= high) {
		B[k++] = A[j++];
	}
	k = 0;
	for (i = low; i <= high; ++i) {
		A[i] = B[k++];
	}
}

void mergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(A, low, mid);
		mergeSort(A, mid + 1, high);
		merge(A, low, mid, high);
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
	int R[] = {49, 38, 65, 97, 76, 13, 27, 49};
	printf("排序前: ");printR(R, 8);
	mergeSort(R, 0, 7);
	printf("排序后: ");printR(R, 8);
	return 0;
}