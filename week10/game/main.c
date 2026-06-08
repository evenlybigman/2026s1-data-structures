#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element item) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, item);

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

int main() {
	ListNode* head = NULL;

	//10 -> 20 -> 30 -> 40 
	head = insert_first(head, "KIM");
	head = insert_first(head, "PARK");
	head = insert_first(head, "CHOI");

	ListNode* current = head;

	for (int i = 0; i < 10; i++) {
		printf("현재 차례: %s\n", current->data);
		current = current->link;
	}

	return 0;
}