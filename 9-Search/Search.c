#include <stdio.h>
#include <stdlib.h>

/*
 * 顺序查找和折半查找
 */

// 以下数组从下标1开始存

// 顺序查找
int search(int a[], int n, int k) {
	int i;
	for (i = 1; i <= n; ++i) {
		if (a[i] == k) {
			return i;
		}
	}
	return 0;
}

// 折半查找
int Bsearch(int R[], int low, int high, int k) {
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (k == R[mid]) {
			return mid;
		} else if (k < R[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return 0;
}

int main() {
	int R[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int k = 4;
	int i;
	if ((i = search(R, 11, k)) != 0) {
		printf("找到元素%d, 下标: %d\n", k, i);
	}
	if ((i = Bsearch(R, 1, 11, k)) != 0) {
		printf("找到元素%d, 下标: %d\n", k, i);
	}
}