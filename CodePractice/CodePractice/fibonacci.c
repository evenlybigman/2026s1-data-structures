#include <stdio.h>


int fibonacci(int n) {
	if (n <= 1) return n;
	else return fibonacci(n - 2) + fibonacci(n - 1);
}

//반복문을 이용한 피보나치 수열
int fibonacci_iter(int n) {
	int first = 0, second = 1, next = 0;
	if (n <= 1) return n;
	for (int i = 2; i <= n; i++) { // 2
		next = first + second;
		first = second;
		second = next;
	}
	return next;
}

int main() {
	printf("%d\n", fibonacci_iter(8));
	printf("%d", fibonacci(7));
}