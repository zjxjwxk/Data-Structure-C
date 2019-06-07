#include <stdio.h>
#include <stdlib.h>

/*
 * 串
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

int main() {
	int next[8];
	Str substr = newStr();
	substr.ch = " ABABABB";
	substr.length = 8;
	getnext(substr, next);
	for (int i = 1; i < 8; ++i) {
		printf("%d\n", next[i]);
	}
	return 0;
}