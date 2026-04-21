#include <stdio.h>

int factorial(int n) {
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}

int main() {
	int result = 1;
	int n = 5;
	for (int n = 5; n > 0; n--) {
		result *= n;
	}
	printf("%d 팩토리얼의 값: %d", 5, result);
}