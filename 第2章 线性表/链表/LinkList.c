/*
 * 链表
 */

typedef int Element;

typedef struct LNode {
	Element data;
	struct LNode *next;
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList *L) {
	LNode *s;
	int x;
	L = (LinkList *) malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while(x != 9999) {
		s = (LNode *) malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

int main() {
	LinkList L;
	List_HeadInsert(&L);
	return 0;
}