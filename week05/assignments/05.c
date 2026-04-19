//person 구조체 만들기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct person {
	char name[10];
	int age;
	float pay;
};

int main() {
	struct person me;
	strcpy(me.name, "김주혁");
	me.age = 23;
	me.pay = 56;
	printf("이름: %s\n나이: %d\n월급: %f", me.name, me.age, me.pay);
	return 0;
}