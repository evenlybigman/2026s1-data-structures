# 자료구조 12주차

# 우선순위 큐

우선순위를 가진 항목들을 저장하는 큐이다.

우선순위가 높은 데이터가 먼저 나가게 된다. 만약 우선순위를 먼저 들어온 데이터로 한다면 일반 큐, 나중에 들어온 데이터로 한다면 스택이 된다.

가장 일반적인 큐이다.

### 구현 방법

우선순위 큐는 3가지로 구현할 수 있다.

배열과 연결 리스트는 정렬 유무에 따라 시간 복잡도가 다르다.

### 배열을 이용한 우선순위 큐

- 정렬 없는 배열
  - 삽입: O(1)  삭제: O(n)
- 정렬 배열
  - 삽입: O(n) 삭제: O(1)

### 연결 리스트를 이용한 우선순위 큐

- 정렬 없는 연결 리스트
  - 삽입: O(1) 삭제: O(n)
- 정렬 연결 리스트
  - 삽입: O(n) 삭제: O(1)

### 히프를 이용한 우선순위 큐

삽입: O(log n) 삭제: O(log n) 

## 히프

부모 노드의 키 값이 항상 자식 노드보다 큰 이진 트리

중복된 값 허용

히프는 완전 이진 트리이기 때문에 완전 이진 트리의 성질을 갖는다.

### 히프의 높이

완전 이진 트리와 마찬가지로 레벨이 i일 때 마지막 레벨을 제외하고 i에는 2^i-1의 노드를 갖는다. 

### 히프의 구현

히프는 배열을 이용해 구현 한다.

완전 이진 트리 구현과 똑같이 각 번호를 인덱스로 사용한다. 부모와 자식의 위치를 편하게 접근하기 위함이다.

핵심.

- 삽입과 삭제 모두 처음에 heap_size를 수정한다.
- 

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct element{
	int key;
}element;

typedef struct HeapType {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* heap) {
	heap->heap_size = 0;
}

# 자기보다 작은 부모 찾으면 바꿈
void insert_max_heap(HeapType* heap, element item) {
	int i;
	i = ++(heap->heap_size);

	while (i != 1 && (item.key > heap->heap[i / 2].key)) {
		heap->heap[i] = heap->heap[i / 2];
		i = i / 2;
	}
	heap->heap[i] = item;
}

# 반환용을 저장해둔다.
# 자식중에 더 큰 자식을 부모로 한다.
# 중복을 허용
element delete_max_heap(HeapType* heap) {

	int parent, child;
	element item, temp;

	//반환용 데이터 저장
	item = heap->heap[1];
	temp = heap->heap[(heap->heap_size)--];

	parent = 1;
	child = 2;
	
	while (child <= heap->heap_size) {

		if ((child < heap->heap_size) &&
			(heap->heap[child].key) < heap->heap[child + 1].key)
			child++;

		if (temp.key >= heap->heap[child].key)
			break;

		heap->heap[parent] = heap->heap[child];
        parent = child;
		child *= 2;
	}

	heap->heap[parent] = temp;
	return item;
}

int main() {
	element e1 = { 10 }, e2 = { 20 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;

	heap = create();
	init(heap);

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	
	e6 = delete_max_heap(heap);
	printf("< %d > ", e6.key);
	

	free(heap);
	return 0;
}
```

### 히프의 시간 복잡도

삽입의 최악의 경우 자기가 루트 값일 경우 레벨 만큼 이동 O(log n)

삭제는 가장 낮은 값이 루트가 되니 자기 위치를 찾아가는데 레벨 만큼 걸린다. O(log n)

### 히프 정렬

