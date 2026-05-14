#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 100
typedef int element;

typedef struct ListNode{
	element data;
	struct ListNode* link;
}ListNode;

ListNode* add(ListNode* list, element item);
ListNode* delete(ListNode* list, element deleteElement);
ListNode* clear(ListNode* list);
bool is_in_list(ListNode* list, element searchElement);
int get_length(ListNode* list);
bool is_empty(ListNode* list);
bool is_full(ListNode* list);
void display(ListNode* list);

ListNode* add(ListNode* list, element item) { // 오름차순 -> 작은값이 앞
	if (is_full(list)) return list;

	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = item;

	if (is_empty(list) || item < list->data) {
		newNode->link = list;
		list = newNode;
		return list;
	}

	ListNode* pre = list; 
	while (pre->link != NULL && item > pre->link->data) { //삽입할 노드 앞으로 가기 
		pre = pre->link;
	}
	newNode->link = pre->link;
	pre->link = newNode;
	return list;
}

ListNode* delete(ListNode* list, element deleteElement) {
	if(is_empty(list)) return list;

	if (list->data == deleteElement) {
		ListNode* removed = list;
		list = list->link;
		free(removed);
		printf("리스트에서 %d를 지웠습니다.\n", deleteElement);
		return list;
	}

	ListNode* pre = list;
	while (pre->link != NULL && pre->link->data != deleteElement) {
		pre = pre->link;
	}

	if (pre->link == NULL) {
		printf("리스트에서 %d를 찾을 수 없습니다.", deleteElement);
		return list;
	}

	ListNode* removed = pre->link;
	pre->link = removed->link;
	free(removed);
	printf("리스트에서 %d를 지웠습니다.\n", deleteElement);
	return list;
}

ListNode* clear(ListNode* list) {
	ListNode* current = list;
	while (current != NULL) {
		ListNode* removed = current;
		current = current->link;
		free(removed);
	}
	return NULL;
}

bool is_in_list(ListNode* list, element searchElement) {
	ListNode* current = list;
	while (current != NULL) {
		if (current->data == searchElement) return true;
		current = current->link;
	}
	return false;
}

int get_length(ListNode* list) {
	int count = 0;
	ListNode* current = list;
	while (current != NULL) {
		current = current->link;
		count++;
	}
	return count;
}

bool is_empty(ListNode* list) {
	if (list == NULL) return true;
	return false;
}

bool is_full(ListNode* list) {
	if (get_length(list) >= MAX_LIST_SIZE) return true;
	else return false;
}

void display(ListNode* list) {
	ListNode* current = list;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->link;
	}
	printf("NULL\n");
}

int main() {
	ListNode* head = NULL;
	head = add(head, 10);
	display(head);
	head = add(head, 20);
	display(head);
	head = add(head, 0);
	display(head);
	printf("리스트의 길이 : %d\n",get_length(head));
	if (is_in_list(head, 10)) {
		printf("리스트에 10이 있습니다.\n");
	}
	else printf("리스트에 10이 없습니다.\n");
	head = delete(head, 10);
	display(head);
	head = clear(head);
	display(head);
}