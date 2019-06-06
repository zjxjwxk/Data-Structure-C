#include <stdio.h>
#include <stdlib.h>

/*
 * 串
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
	for (int i = 0; i < 8; ++i) {
		printf("%d\n", next[i]);
	}
}

int main() {
	int next[8];
	Str substr = newStr();
	substr.ch = "ABABABB";
	getnext(substr, next);
	return 0;
}