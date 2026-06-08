#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* head) {
	if (head == NULL) return;

	ListNode* current = head->link;

	do {
		printf("%d -> ", current->data);
		current = current->link;
	} while (current != head->link);
}

ListNode* insert_first(ListNode* head, element item) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = item;

	if (head == NULL) {
		head = newNode;
		newNode->link = newNode;
	}

	else {
		newNode->link = head->link;
		head->link = newNode;
	}

	return head;
}

ListNode* insert_last(ListNode* head, element item) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = item;

	if (head == NULL) {
		head = newNode;
		newNode->link = newNode;
	}

	else {
		newNode->link = head->link;
		head->link = newNode;
		head = newNode;
	}

	return head;
}

int main() {
	ListNode* head = NULL;

	//10 -> 20 -> 30 -> 40 
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	
	print_list(head);

	return 0;
}