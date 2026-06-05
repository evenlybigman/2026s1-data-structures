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

insert(list,pos,item)    -    item을 pos 위치에 넣는다.

insert_first(list,item)   -   item을 리스트 맨 앞에 넣는다.

insert_last(list,item)    -   item을 리스트 맨 뒤에 넣는다.

delete(list,pos)             -  pos 위치에 요소를 삭제한다. 

clear(list)                       -  리스트의 모든 요소를 제거한다.

*get_entry(list,pos)     -  pos 위치에 요소를 반환한다.

get_length(list)            -  리스트의 길이를 구한다.

is_empty(list)               -  리스트가 비었는지 검사한다. 

is_full(list)                    -  리스트가 가득 찼는지 검사한다.

print_list(list)              -  리스트의 요소들을 출력한다.

### 리스트 구현 방법

- 배열을 이용한 구현(순차 리스트)
  - 장점 : 구현이 쉽다. 탐색 연산이 빠르다. (인덱스 이용 O(1))
  - 단점 : 크기가 정해져 있다. 삭제와 추가가 느리다.

- 연결 리스트를 이용한 구현
  - 장점 : 삽입과 삭제의 속도가 빠르다. 크기의 제한이 없다.
  - 단점 : 구현이 복잡하다. 탐색 속도가 느리다.(O(n))

### 배열로 구현한 리스트

size = 다음에 들어갈 자리로 외운다. 삽입과 삭제의 size가 들어가는 조건문에 유의한다.

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


int main() {
	//ArrayListType를 정적으로 생성하고 ArrayListTpe를
	//가리키는 포인터를 함수의 매개변수로 전달한다.
	
	ArrayListType list;

	init(&list);
	insert(&list, 0, 10);  print_list(&list);
	insert(&list, 0, 20);  print_list(&list);
	insert(&list, 0, 30);  print_list(&list);
	insert_last(&list,40); print_list(&list);
	delete(&list, 0);      print_list(&list);
	clear(&list);          print_list(&list);
	insert(&list, 0, 30);  print_list(&list);
	return 0;
}
```





