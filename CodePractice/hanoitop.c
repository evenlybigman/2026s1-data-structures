#include <stdio.h>

void hanoi_tower(int n, char start, char tmp, char end) {
	if (n <= 0) return;
	else if (n == 1) {
		printf("원판 %d를 %c에서 %c로 옮긴다.\n",n, start, end);
	}
	else {
		hanoi_tower(n - 1, start, end, tmp);
		printf("원판 %d를 %c에서 %c로 옮긴다.\n",n, start, end);
		hanoi_tower(n - 1, tmp, start, end);
	}
}

int main() {
	hanoi_tower(4, 'a', 'b', 'c');
}