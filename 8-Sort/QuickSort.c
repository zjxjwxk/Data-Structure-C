#include <stdio.h>
#include <stdlib.h>

/*
 * 快速排序
 */

void QuickSort(int R[], int low, int high) {
	int temp;
	int i = low;
	int j = high;
	if (low < high) {
		temp = R[low];
		while (i < j) {
			while (i < j && R[j] >= temp) {
				--j;
			}
			if (i < j) {
				R[i] = R[j];
				++i;
			}
			while (i < j && R[i] < temp) {
				++i;
			}
			if (i < j) {
				R[j] = R[i];
				--j;
			}
		}
		R[i] = temp;
		QuickSort(R, low, i - 1);
		QuickSort(R, i + 1, high);
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
	QuickSort(R, 0, 7);
	printf("排序后: ");printR(R, 8);
	return 0;
}