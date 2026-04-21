#include <stdio.h>


void hanoi_tower(int n, char from, char tmp, char to) {
	int count = 0;
	if (n <= 1) return;
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("%c를 %c로 옮겼습니다.\n", from, to);
		hanoi_tower(n-1, from, tmp, to);
		
	}
}


int main() {
	hanoi_tower(4, 'a','b','c');
}