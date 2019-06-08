#include <stdio.h>
#include <stdlib.h>

/*
 * KMP算法
 */

/*
 * 字符存储在1～length的位置上
 */

typedef struct {
	char *ch;
	int length;
} Str;

Str newStr() {
	Str str;
	str.ch = NULL;
	str.length = 0;
	return str;
}

void getnext(Str substr, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < substr.length) {
		if (j == 0 || substr.ch[i] == substr.ch[j]) {
			++i;
			++j;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
}

int KMP(Str str, Str substr, int next[]) {
	int i = 1, j = 1;
	while (i <= str.length && j <= substr.length) {
		if (j == 0 || str.ch[i] == substr.ch[j]) {
			++i;
			++j;
			printf("i = %d, j = %d\n", i, j);
		} else {
			j = next[j];
			printf("j = %d\n", j);
		}
	}
	if (j > substr.length) {
		return i - substr.length;
	} else {
		return 0;
	}
}

int main() {
	int next[8];
	Str substr = newStr();
	substr.ch = " ABABABB";
	substr.length = 7;
	getnext(substr, next);
	for (int i = 1; i < 8; ++i) {
		printf("%d\n", next[i]);
	}
	Str str = newStr();
	str.ch = " ABABABABABBAB";
	str.length = 13;
	printf("KMP结果: %d\n", KMP(str, substr, next));
	return 0;
}