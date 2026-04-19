//복소수 더하는 함수 만들기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct complex {
	float real;
	float imaginary;
}Complex;

Complex complex_add(Complex a, Complex b) {
	Complex result;
	result.real = a.real + b.real;
	result.imaginary = a.imaginary + b.imaginary;
	return result;
}

int main() {
	Complex c1, c2;
	printf("복소수 a의 값을 입력하세요.\n");
	printf("실수의 값:");
	scanf("%f", &c1.real);
	printf("허수의 값:");
	scanf("%f", &c1.imaginary);
	printf("복소수 b의 값을 입력하세요.\n");
	printf("실수의 값:");
	scanf("%f", &c2.real);
	printf("허수의 값:");
	scanf("%f", &c2.imaginary);
	printf("복소수 a + b의 값은 %.2f + %.2fi입니다.",complex_add(c1,c2).real,complex_add(c1,c2).imaginary);
	return 0;
}
