#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct element {
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

void insert_max_heap(HeapType* heap, element item) {
	int i;
	i = ++(heap->heap_size);

	while (i != 1 && (item.key > heap->heap[i / 2].key)) {
		heap->heap[i] = heap->heap[i / 2];
		i = i / 2;
	}
	heap->heap[i] = item;
}

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

void heap_sort(element a[], int n) {
	int i;

	HeapType* h;

	h = create();
	init(h);

	for (int i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}

	for (int i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}

	free(h);
}

int main() {
	element list[8] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, 8);
	for (int i = 0; i < 8; i++) {
		printf("%d ", list[i].key);
	}

	printf("\n");
	return 0;
}