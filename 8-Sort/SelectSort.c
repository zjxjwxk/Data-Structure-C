#include <stdio.h>
#include <stdlib.h>

/*
 * 选择排序
 */

void SelectSort(int R[], int n) {
	int i, j, k;
	int temp;
	for (i = 0; i < n; ++i) {
		k = i;
		for (j = i + 1; j < n; ++j) {
			if (R[j] < R[k]) {
				k = j;
			}
		}
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
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
	SelectSort(R, 8);
	printf("排序后: ");printR(R, 8);
	return 0;
}