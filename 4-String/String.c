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

// 赋值操作
int strassign(Str *str, char *ch) {
	if (str->ch) {
		free(str->ch);
	}
	int len = 0;
	char *c = ch;
	while (*c) {
		++len;
		++c;
	}
	if (len == 0) {
		str->ch = NULL;
		str->length = 0;
		return 1;
	} else {
		str->ch = (char*)malloc(sizeof(char) * (len + 1));
		if (str->ch == NULL) {
			return 0;
		} else {
			c = ch;
			for (int i = 0; i <= len; ++i, ++c) {
				str->ch[i] = *c;
			}
			str->length = len;
			return 1;
		}
	}
}

// 取串长度操作
int strlength(Str str) {
	return str.length;
}

// 串比较操作
int strcompare(Str s1, Str s2) {
	for (int i = 0; i < s1.length && i < s2.length; ++i) {
		if (s1.ch[i] != s2.ch[i]) {
			return s1.ch[i] - s2.ch[i];
		}
	}
	return s1.length - s2.length;
}

// 串连接操作
int concat(Str *str, Str str1, Str str2) {
	if (str->ch) {
		free(str->ch);
		str->ch = NULL;
	}
	str->ch = (char*)malloc(sizeof(char) * (str1.length + str2.length));
	if (str->ch == NULL) {
		return 0;
	}
	int i = 0;
	while (i < str1.length) {
		str->ch[i] = str1.ch[i];
		++i;
	}
	int j = 0;
	while (j <= str2.length) {
		str->ch[i + j] = str2.ch[j];
		++j;
	}
	str->length = str1.length + str2.length;
	return 1;
}

// 求子串操作
int substring(Str *substr, Str str, int pos, int len) {
	if (pos < 0 || pos >= str.length || len < 0 || len > str.length - pos) {
		return 0;
	}
	if (substr->ch) {
		free(substr->ch);
		substr->ch = NULL;
	}
	if (len == 0) {
		substr->ch = NULL;
		substr->length = 0;
		return 1;
	} else {
		substr->ch = (char*)malloc(sizeof(char) * (len + 1));
		int i = pos;
		int j = 0;
		while (i < pos + len) {
			substr->ch[j] = str.ch[i];
			++i;
			++j;
		}
		substr->ch[j] = '\0';
		substr->length = len;
		return 1;
	}
}

// 串清空操作
int clearstring(Str *str) {
	if (str->ch) {
		free(str->ch);
		str->ch = NULL;
	}
	str->length = 0;
	return 1;
}

int main() {
	Str str1 = newStr();
	strassign(&str1, "Hello World! ");
	printf("串: %s\n", str1.ch);
	printf("串长度: %d\n", strlength(str1));
	Str str2 = newStr();
	strassign(&str2, "I'm Wxk");
	printf("串比较结果: %d\n", strcompare(str1, str2));
	Str str3 = newStr();
	concat(&str3, str1, str2);
	printf("串连接结果: %s\n", str3.ch);
	Str substr = newStr();
	substring(&substr, str1, 6, 6);
	printf("求子串结果: %s\n", substr.ch);
	clearstring(&str1);
	printf("串清空操作结果: str1.ch = %s\n", str1.ch);
	return 0;
}