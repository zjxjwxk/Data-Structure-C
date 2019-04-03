#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * 线性表
 */

typedef int ElemType;

// 静态存储
// typedef struct {
// 	int data[MaxSize];
// 	int length;
// } SqList;

// 动态存储
#define InitSize 10
typedef struct {
	ElemType *data;
	int length, MaxSize;
} SeqList;

void InitList(SeqList *L) {
	printf("------创建线性表------\n");
	L->data = (ElemType*) malloc(sizeof(ElemType) * InitSize);
	L->length = 0;
	L->MaxSize = 50;
	printf("线性表的当前个数: %d\n", L->length);
	printf("线性表的最大容量: %d\n", L->MaxSize);
}

bool ListInsert(SeqList *L, int i, int e) {
	printf("%s\n", "------插入元素------");
	printf("插入的位置: %d, 插入的元素: %d\n", i, e);
	if (i < 1 || i > L->length + 1)
	{
		return false;
	}
	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}

void PrintList(SeqList *L) {
	printf("%s\n", "------输出元素------");
	for (int i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n线性表的当前长度: %d\n", L->length);
}

int main() {
	ElemType e;
	SeqList L;
	InitList(&L);
	
	ListInsert(&L, 1, 1);
	ListInsert(&L, 1, 2);
	ListInsert(&L, 1, 3);
	ListInsert(&L, 1, 4);
	ListInsert(&L, 1, 5);
	
	PrintList(&L);
	return 0;
}