#include <stdio.h>
#include <stdlib.h>

void InsertSort(int R[], int n) {
	int i, j;
	int temp;
	for (i = 1; i < n; ++i) {
		temp = R[i];
		j = i - 1;
		while (j >= 0 && temp < R[j]) {
			R[j + 1] = R[j];
			--j;
		}
		R[j + 1] = temp;
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
	InsertSort(R, 8);
	printf("排序后: ");printR(R, 8);
	return 0;
}