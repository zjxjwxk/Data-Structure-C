#include <stdio.h>
#include <stdlib.h>

/*
 * 顺序查找
 */

int search(int a[], int n, int k) {
	int i;
	for (i = 1; i <= n; ++i) {
		if (a[i] == k) {
			return i;
		}
	}
	return 0;
}