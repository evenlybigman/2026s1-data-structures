#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
	int key;
	char task[100];
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element data) {
	int i;

	i = ++(h->heap_size);

	while (i != 1 && data.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = data;
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[h->heap_size - 1];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {

		if (child < h->heap_size &&
			(h->heap[child].key) &&
			(h->heap[child].key < h->heap[child + 1].key))
			child++;

		if (temp.key >= h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent] = temp;
	return item;;
}

int main() {
	HeapType* heap;
	element item;
	char command;

	heap = create();
	init(heap);

	while (1) {

		printf("\n삽입(i), 삭제(d), 종료(q): ");
		scanf(" %c", &command);

		if (command == 'i') {
			printf("할일: ");
			scanf("%s", &item.task);
			printf("우선순위: ");
			scanf("%d", &item.key);

			insert_max_heap(heap, item);
		}

		else if (command == 'd') {
			if (heap->heap_size == 0) { //예외 처리
				printf("할 일이 없습니다.\n");
			}

			else {
				item = delete_max_heap(heap);
				printf("제일 우선 순위가 높은 일은 %s\n", item.task);
			}
		}

		else if (command == 'q')
			break;

		else {
			printf("잘못된 입력입니다.\n");
		}
	}

	free(heap);
	return 0;
}
