# 자료구조 9주차

## 원형 연결 리스트

원형 리스트는 제일 처음 노드가 마지막 노드와 연결되어 있는 리스트를 말한다.

헤드가 가장 마지막 노드를 가리킨다. (tail)

NULL을 가리키는 상황은 비어있을 때 밖에 없다.

head를 원하는 노드로 바꿔주면 그것이 마지막 노드가 된다.

### 구현

```c
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
```



## 응용

### 원형 큐

원형 큐는 head를 REAR로 head->link를 front로 하여 구현 할 수 있다.

insert_last(head,item)로 enqueue(q,e) 구현

delete_first(head)로 dequeuer(q) 구현

### 멀티 플레이어 게임

```c
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
```

