#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct test {
	int i;
	char str[20];
}test;

int main() {
	struct test* ps;
	ps = malloc(sizeof(test));
	if (ps == NULL) {
		printf("용량이 부족해서 할당할 수 없습니다");
		exit(1);
	}
	else {
		ps->i = 100;
		strcpy(ps->str, "Just testing");

		printf("i = %d\n", ps->i);
		printf("str = %s\n", ps->str);
		free(ps);
	}
	return 0;
}