#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100;
typedef int element;

typedef struct ListNode {
	element data;
	ListNode* link;
}ListNode;

ListNode* add(ListNode *head, element value) { //다음 노드보다 작을떄 걍 넣음 크면 다음 노드로 가야함 20 40있는 상태에서 30
	if (is_full(head)) return head;

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;

	if (is_empty(head) || value < head->data) {
		p->link = head;
		head = p;
		return head;
	}

	ListNode* pre = head;
	while (pre->link != NULL && ) { //pre의 값이 있는데 넣을 값이 pre값보다 작으면 다음으로 넘어감
		pre = pre->link;

	}
}

ListNode* delete(ListNode* list, element item) {
}

void clear(list) {

}

bool is_in_list(ListNode* list, element item) {
}

int get_length(ListNode* list) {
	int length = 0;
	ListNode* p = list;
	while (p != NULL) {
		p = list->link;
		length++;
	}
	return length;
}

bool is_empty(ListNode* list) {
	if (list->link == NULL) return true;
	else return false;
}

bool is_full(ListNode* list) {
	if (get_length(list) >= MAX_LIST_SIZE) return true;
	return false;
}

void display(ListNode* list) {
	ListNode* p = list;
	while (p != list) {
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("NULL\n");
}

int main() {
	ListNode* list;
	list = add(list, 10);
	display(list);
	list = add(list, 30);
	display(list);
	list = add(list, 20);
	display(list);
}