#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p=p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}

int main() {
	ListNode* head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);
	head = insert_first(head, 40);
	print_list(head);

	int number = 0;
	printf("숫자를 입력하세요: ");
	scanf("%d", &number);
	if (search_list(head, number) != NULL) printf("리스트에서 %d를 찾았습니다.\n", number);
	else printf("리스트에서 %d를 찾지 못했습니다.", number);
	
	return 0;
}
