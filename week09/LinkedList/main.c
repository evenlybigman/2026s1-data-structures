#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element item) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

	newNode->data = item;
	newNode->link = head;
	head = newNode;
	return head;
}

ListNode* insert(ListNode* head,ListNode* pre, element item) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

	newNode->data = item;
	newNode->link = pre->link;

	pre->link = newNode;
	return head;
}


ListNode* delete_first(ListNode* head) {
	if (head == NULL) return head;

	ListNode* removed = head;
	head = head->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
	if (pre->link == NULL) return head;

	ListNode* removed = pre->link;

	pre->link = removed->link;
	free(removed);

	return head;
}

void print_list(ListNode* head) {
	ListNode* current;
	for (current = head; current != NULL; current = current->link) {
		printf("%d -> ", current->data);
	}
	printf("\n");
}

int main() {
	ListNode* head = NULL;

	// insert_first 테스트
	printf("=== insert_first ===\n");
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i * 10);
		print_list(head);
	}

	// insert 테스트 (head 다음에 99 삽입)
	printf("=== insert ===\n");
	head = insert(head, head, 99);
	print_list(head);

	// delete 테스트 (head 다음 노드 삭제)
	printf("=== delete ===\n");
	head = delete(head, head);
	print_list(head);

	// delete_first 테스트
	printf("=== delete_first ===\n");
	for (int i = 0; i < 3; i++) {
		head = delete_first(head);
		print_list(head);
	}

	// delete NULL 체크 테스트 (마지막 노드의 pre->link == NULL)
	printf("=== delete NULL 체크 ===\n");
	ListNode* last = head;
	while (last->link != NULL) last = last->link;  // 마지막 노드 탐색
	head = delete(head, last);  // 마지막 노드의 pre->link는 NULL
	print_list(head);

	return 0;
}