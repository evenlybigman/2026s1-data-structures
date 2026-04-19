#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	char** p;

	//*(p+0)에서 *(p+1)까지에 해당하는 메모리 생성
	p = (char**)malloc(sizeof(char*) * 2);
	// *(*(p+0)+0)에서 *(*(p+1)+2)까지에 해당하는 메모리 생성
	for (int i = 0; i < 2; i++) {
		*(p + i) = (char*)malloc(3 * sizeof(char));
	}
	//주소마다 값 1씩 증가 시키기
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			*(*(p + i) + j) = i * 3 + j;
		}
	}
	//출력
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("*(*(p + %d) + %d)의 주소(%p)와 값(%d)\n",
				i, j, *(p + i) + j, *(*(p + i) + j));
		}
	}
	for (int i = 0; i < 2; i++) {
		free(*(p + i));
	}
	free(p);
	return 0;
}