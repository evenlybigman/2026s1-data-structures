#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

void init(DlistNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void dinsert(DlistNode* before, element data) {
	DlistNode* newNode = (DlistNode*)malloc(sizeof(DlistNode));
	newNode->data = data;
	newNode->llink = before;
	newNode->rlink = before->rlink;
	before->rlink->llink = newNode;
	before->rlink = newNode;
}

void ddelete(DlistNode* phead, DlistNode* removed) {
	if (removed == phead) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void printReverse(DlistNode* phead) {
	DlistNode* current;
	for (current = phead->llink; current != phead; current = current->llink) {
		printf("%d ", current->data);
	}
	printf("\n");
}

int main() {
	DlistNode* phead = (DlistNode*)malloc(sizeof(DlistNode));
	init(phead);
	int dataSize = 0;
	int data = 0;
	printf("데이터의 개수를 입력하시오: ");
	scanf("%d", &dataSize);
	for (int i = 0; i < dataSize; i++) { 
		printf("노드 #%d의 데이터를 입력하시오: ", i+1);
		scanf("%d", &data);
		dinsert(phead->llink, data);
	}
	printf("데이터를 역순으로 출력: ");
	printReverse(phead);
	return 0;
}