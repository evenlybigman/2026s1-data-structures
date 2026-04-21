#include <stdio.h>

//하노이 탑
//n개의 탑을 start에서 end로 옮긴다.
//n = 1일때 n을 end로 옮긴다.
//n-1을 임시 공간으로 옮긴다. n을 end로 옮긴다.
//n-1을 end로 옮긴다.
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