#include <stdio.h>
#include <stdlib.h>

/*
 * 冒泡排序
 */

void BubbleSort(int R[], int n) {
	int i, j, flag;
	int temp;
	for (i = n - 1; i >= 1; --i) {
		flag = 0;
		for (j = 1; j <= i; ++j) {
			if (R[j - 1] > R[j]) {
				temp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			return;
		}
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
	BubbleSort(R, 8);
	printf("排序后: ");printR(R, 8);
	return 0;
}