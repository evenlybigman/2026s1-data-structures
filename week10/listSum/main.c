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
	printf("%리스트에 %d를 넣었습니다.\n", value);
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
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

ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
	}
	printf("head1과 head2를 합쳤습니다.\n");
	return head1;
}

int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	print_list(head1);
	head1 = insert_first(head1, 20);
	print_list(head1);
	head1 = insert_first(head1, 30);
	print_list(head1);
	head2 = insert_first(head2, 40);
	print_list(head2);
	head2 = insert_first(head2, 50);
	print_list(head2);
	head2 = insert_first(head2, 60);
	print_list(head2);
	ListNode* total = concat_list(head1, head2);
	print_list(total);
	return 0;
}
