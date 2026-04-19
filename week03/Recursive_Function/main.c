#include <stdio.h>
int factorial(int n);
int power(int x, int n);
int fib(int n);

int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}

int power(int x, int n) { //x의 n 제곱 
	if (n == 0) return 1;
	return x * power(x, n - 1);
}

int fib(int n) { //f(1) = 1   1 1 2 3 5 8 13
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 2) + fib(n - 1);
}

int main() {
	printf("제출자 : 김주혁(2371209)\n");
	printf("학번마지막숫자는 9이고 2를 더하면 11입니다.\n");
	printf("1. 팩토리얼 : 11!의 값은 %d\n", factorial(11));
	printf("2. 거듭제곱 : 2의 11제곱의 값은 %d\n", power(2, 11));
	printf("3. 피보나치 : n=11의 피보나치 수열 값은 %d\n", fib(11));

	return 0;
}
