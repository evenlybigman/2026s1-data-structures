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