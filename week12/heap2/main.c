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