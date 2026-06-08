#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* head) {
	head->llink = head;
	head->rlink = head;
}

void dinsert(DListNode* before, element item) {
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	newNode->data = item;

	newNode->llink = before;
	newNode->rlink = before->rlink;
	before->rlink->llink = newNode;
	before->rlink = newNode;
}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head)
		return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;

	free(removed);
}

void print_dlist(DListNode* head) {
	DListNode* current;
	for (current = head->rlink; current != head; current = current->rlink) {
		printf("<- | |%d| | -> ", current->data);
	}
	printf("\n");
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {
		// 헤드 노드의 오른쪽 삽입
		dinsert(head, i);
		print_dlist(head);
	}

	printf("\n삭제 단계\n");

	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}

	free(head);
	return 0;
}