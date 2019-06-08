#include <stdio.h>
#include <stdlib.h>

/*
 * KMP算法的改进
 * 将next数组用nextval代替
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

void getnextval(Str substr, int nextval[]) {
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < substr.length) {
		if (j == 0 || substr.ch[i] == substr.ch[j]) {
			++i;
			++j;
			if (substr.ch[i] != substr.ch[j]) {
				nextval[i] = j;
			} else {
				nextval[i] = nextval[j];
			}
		} else {
			j = nextval[j];
		}
	}
}

int KMP(Str str, Str substr, int nextval[]) {
	int i = 1, j = 1;
	while (i <= str.length && j <= substr.length) {
		if (j == 0 || str.ch[i] == substr.ch[j]) {
			++i;
			++j;
			printf("i = %d, j = %d\n", i, j);
		} else {
			j = nextval[j];
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
	int nextval[8];
	Str substr = newStr();
	substr.ch = " ABABABB";
	substr.length = 7;
	getnextval(substr, nextval);
	for (int i = 1; i < 8; ++i) {
		printf("%d\n", nextval[i]);
	}
	Str str = newStr();
	str.ch = " ABABABABABBAB";
	str.length = 13;
	printf("KMP结果: %d\n", KMP(str, substr, nextval));
	return 0;
}