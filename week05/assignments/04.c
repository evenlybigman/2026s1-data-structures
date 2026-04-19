//2의 n제곱 배열 만들기
#include <stdio.h>

int main() {
	int two[10];
	int pow = 1;
	for (int i = 0; i < 10; i++) {
		two[i] = pow;
		pow *= 2;
		printf("2의 %d승은 %d입니다.\n", i,two[i]);
	}
	return 0;
}