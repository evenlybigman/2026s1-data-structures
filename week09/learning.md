# 자료구조 9주차

## 리스트

### 리스트란?

데이터를 일렬로 순서대로 나열하는 기본적인 선형 자료구조.

### 리스트의 기본 연산

L = (item0, item1, item2, item3, ...itemN)

1. 삽입 
   - 리스트에 새로운 항목을 추가한다.
2. 삭제 
   - 리스트에서 항목을 삭제한다.
3. 탐색
   - 리스트에서 특정한 항목을 찾는다.

### 리스트 ADT

리스트의 추상 자료형은 다음과 같다.

insert(list,pos,item)           - item을 pos 위치에 넣는다.

insert_first(list,item)     - item을 리스트 맨 앞에 넣는다.

insert_last(list,item)      - item을 리스트 맨 뒤에 넣는다.

delete(list,pos)                 - pos 위치에 요소를 삭제한다. 

clear(list)                       - 리스트의 모든 요소를 제거한다.

*get_entry(list,pos)         - pos 위치에 요소를 반환한다.

get_length(list)                        - 리스트의 길이를 구한다.

is_empty(list)                    - 리스트가 비었는지 검사한다. 

is_full(list)                     - 리스트가 가득 찼는지 검사한다.

print_list(list)                    - 리스트의 요소들을 출력한다.

### 리스트 구현 방법

- 배열을 이용한 구현(순차 리스트)
  - 장점 : 구현이 쉽다. 탐색 연산이 빠르다. (인덱스 이용 O(1))
  - 단점 : 크기가 정해져 있다. 삭제와 추가가 느리다.

- 연결 리스트를 이용한 구현
  - 장점 : 삽입과 삭제의 속도가 빠르다. 크기의 제한이 없다.
  - 단점 : 구현이 복잡하다. 탐색 속도가 느리다.(O(n))

## 배열로 구현한 리스트(순차 리스트)

size = 다음에 들어갈 자리로 외운다. 

삽입과 삭제의 size가 들어가는 조건문에 유의한다.

각 요소들의 자리를 옮길 때 값이 덮어씌어지지않도록 유의한다.

```c
#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct ArrayListType {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

void init(ArrayListType* L) {
	L->size = 0;
}

int is_empty(ArrayListType* L) {
	return L->size == 0;
}

int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

void insert(ArrayListType* L, int pos, element item) {
	if (is_full(L) || pos < 0 || pos > L->size) {
		printf("삽입 실패\n");
		return;
	}

	for (int i = (L->size-1); i >= pos; i--) {
		L->array[i+1] = L->array[i];
	}

	L->array[pos] = item;
	L->size++;
}

void insert_last(ArrayListType* L, element item) {
	if (is_full(L)) {
		printf("삽입 실패\n");
		return;
	}

	L->array[L->size++] = item;
}

element delete(ArrayListType* L, int pos) {
	if (is_empty(L) || pos < 0 || pos > (L->size-1)) {
		printf("삭제 실패");
		return -1;
	}

	element item = L->array[pos];

	for (int i = pos; i < (L->size-1); i++) {
		L->array[i] = L->array[i + 1];
	}

	L->size--;
	return item;
}

void clear(ArrayListType* L) {
	L->size = 0;
}

//pos위치에 요소 반환
element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size) {
		printf("반환 실패\n");
		return -1;
	}

	return L->array[pos];
}

int get_length(ArrayListType* L) {
	return L->size;
}

void print_list(ArrayListType* L) {
	for (int i = 0; i < (L->size); i++) {
		printf("%d -> ", L->array[i]);
	}

	printf("\n");
}
```

## 연결 리스트

노드들을 연결해 리스트를 구현할 수 있다. 이를 연결 리스트라고 한다.

### 연결 리스트의 종류

연결리스트는 3가지 종류가 있다.

1. 단순 연결 리스트
   - 하나의 방향만 가지고 있는 리스트
   - 앞으로 되돌아갈 수 없다.
   - 마지막 노드의 링크는 NULL을 가리킨다.
2. 원형 연결 리스트 (chaine)
   - 마지막 노드가 첫번 째 노드를 가리키는 리스트이다.
   - 끝과 처음이 이어져 있다
3. 이중 연결 리스트
   - 각 노드가 앞의 링크와 뒤의 링크를 둘 다 가지고 있는 리스트이다.
   - 앞과 뒤 모두 자유롭게 이동 가능한 리스트이다.
   - 가장 많이 사용된다.

## 단순 연결 리스트

### 노드의 구조

단순 연결 리스트의 노드는 자기 참조 구조체를 이용해 구현한다.

데이터를 저장하는 data 필드와 다음 노드를 가리키는 link 필드가 있다.

head는 첫번째 노드를 가리키는 포인터이고 마지막 노드의 링크는 NULL이다.

### 연산

insert_first(head,item)   - 리스트 맨 앞에 노드를 추가한다.

insert(head,pre,item)              - pre 뒤에 노드를 추가한다.

delete_first(head)           - 리스트 맨 앞에 노드를 삭제한다.

delete(head,pre)         	    - pre 뒤에 노드를 삭제한다.

print_list(head)                - 리스트의 모든 요소를 출력한다.

### 구현

실수 했던 것

1. insert_first에 불필요한 코드 추가
   head->link = newNode;
2. delete_first return타입 불일치
   if (head == NULL) return -1
3. delete NULL 체크 대상, 반환 값 오류
   if (head == NULL) return NULL;

```c
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


```

## 실습

### 1. search 함수

```c
ListNode* search(ListNode* head, element x) {
    ListNode* curr = head;
    while(curr != NULL) {
        if (curr->data == x) return curr;
        curr = curr->link;
    }
    return NULL;
}
```

못 찾았을 경우 NULL 반환

### 2. reverse 함수

```c
ListNode* reverse(ListNode* head) {
    ListNode *prev, *curr, *next;
    prev = NULL;
    curr = head;
    next = NULL;
    
    while(curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}
```

모든 노드의 링크를 next에서 prev로 바꿔주면 된다. 그럼 prev가 헤드가 되니 prev를 리턴한다.

### 3. sumList 함수

```c
ListNode* sumList(ListNode* head1, ListNode* head2) {
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    else {
        ListNode * head;
        head = head1;
        
        while( head1->link != NULL) {
            head1 = head1->link;
        }
        
        head1->link = head2;
        
        return head;
    }
}
```

head1을 바꾸든 head를 바꾸던 똑같다. 여기서는 head1을 바꿨음 어차피 값에 의한 호출이라 실제 head1은 바뀌지 않음.

