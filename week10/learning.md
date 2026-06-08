# 자료구조 10주차

## 원형 연결 리스트

원형 리스트는 제일 처음 노드가 마지막 노드와 연결되어 있는 리스트를 말한다.

헤드가 가장 마지막 노드를 가리킨다. (tail)

NULL을 가리키는 상황은 비어있을 때 밖에 없다.

head를 원하는 노드로 바꿔주면 그것이 마지막 노드가 된다.

가장 앞에 있는 노드는 멀리 돌아가야 되기 때문에 탐색이 느리다.

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



## 원형 연결 리스트 응용

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

## 이중 연결 리스트

노드가 llink와 rlink로 양방향으로 연결된 리스트이다.

값이 존재하지 않는 맨 처음 노드를 가리키는 헤드 노드가 존재한다. (값이 존재하지 않음)

모든 노드에 대해 llink->rlink->llink = link,  rlink -> llink-> rlink = rlink가 성립한다. 따라서 헤드 노드는 데이터 없이 llink와 rlink가 자신을 가리킨다.

노드 간의 앞뒤 접근이 자유로워 삽입 삭제가 빠르다.

이 수업에서 이중 연결 리스트는 원형 리스트와 이중 연결 리스트가 합쳐진 리스트를 다룬다.

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* head) {
	head->llink = head;
	head->rlink = head;
}

void dinsert(DListNode* before, element item) {
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	newNode->data = item;

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
	DListNode* current;
	for (current = head->rlink; current != head; current = current->rlink) {
		printf("<- | |%d| | -> ", current->data);
	}
	printf("\n");
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {
		// 헤드 노드의 오른쪽 삽입
		dinsert(head, i);
		print_dlist(head);
	}

	printf("\n삭제 단계\n");

	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}

	free(head);
	return 0;
}
```

## 이중 연결 리스트 응용

### MP3 재생 프로그램

mp3의 재생목록은 순서대로 노래 제목이 저장되어 있고 현재 재생하는 노래에서 앞과 뒤로 바꿀 수 있다. 이를 자료구조로 구현하기 적합한 방법이 이중 연결 리스트를 이용하는 것이다. 이중 연결 리스트는 앞 뒤 모두 접근 할 수 있기 때문에 재생목록을 구현하기에 적합하다.

current를 llink로 보냈을때 head라면 head는 더미 노드기 때문에 한번 더 llink로 보내야 한다.

rlink도 마찬가지이다.

```c 
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
```

