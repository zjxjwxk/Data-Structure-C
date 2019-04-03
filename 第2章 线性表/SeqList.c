#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * 顺序表
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

// 将元素e插入到顺序表L中第i个位置
bool ListInsert(SeqList *L, int i, ElemType e) {
	printf("------插入元素------\n");
	if (i < 1 || i > L->length + 1) {

		return false;
	}
	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	printf("插入元素的位置: %d, 插入的元素: %d\n", i, e);
	return true;
}

// 删除顺序表L中第i个位置的元素
bool ListDelete(SeqList *L, int i, ElemType *e) {
	printf("------删除元素------\n");
	if (i < 1 || i > L->length) {
		return false;
	}
	*e = L->data[i - 1];
	for (int j = i; j < L->length; j++) {
		L->data[j - 1] = L->data[j];
	}
	L->length--;
	printf("删除元素的位置: %d, 删除的元素: %d\n", i, *e);
	return true;
}

// 查找顺序表中值为e的元素，如果查找成功，返回元素位序，否则返回0
int LocateElem(SeqList L, ElemType e) {
	printf("------查找元素的位置------\n");
	int i;
	for (int i = 0; i < L.length; i ++) {
		if (L.data[i] == e) {
			printf("元素的位置: %d, 查找的元素: %d\n", i + 1, e);
			return i + 1;
		}
	}
	printf("找不到该元素, 查找的元素: %d\n", e);
	return 0;
}

void PrintList(SeqList L) {
	printf("------输出元素------\n");
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n线性表的当前长度: %d\n", L.length);
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

	PrintList(L);

	ListDelete(&L, 2, &e);
	
	PrintList(L);
	
	LocateElem(L, 9);

	return 0;
}