#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

DListNode* current;

void init(DListNode* head) {
	head->llink = head;
	head->rlink = head;
}

void dinsert(DListNode* before, element item) {
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newNode->data, item);

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
	DListNode* cur;
	for (cur = head->rlink; cur != head; cur = cur->rlink) {
		if (cur == current) {
			printf("<- | |#%s#| | -> ", cur->data);
		}
		else {
			printf("<- | |%s| | -> ", cur->data);
		}
	}
	printf("\n");
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "Mammamia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");
	
	current = head->rlink;

	print_dlist(head);

	char input = 0;
	while (1) {
		printf("명령어를 입력하시오(<,>,q): ");
		input = getchar();

		if (input == 'q') {
			break;
		}

		else if (input == '<') {
				current = current->llink;
				if (current == head) {
					current = current->llink;
				}
		}

		else if (input == '>') {
			current = current->rlink;
			if (current == head) {
				current = current->rlink;
			}
		}


		input = getchar();
		print_dlist(head);
	}

	free(head);
	return 0;
}