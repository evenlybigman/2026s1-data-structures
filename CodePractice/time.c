#include <stdio.h>
#include <time.h>

int main() {
	time_t start, stop;
	double duration;
	long long sum = 0;
	start = time(NULL);
	for (long long i = 0; i < 1000000000; i++) {
		sum += i;
	}
	stop = time(NULL);
	duration = (double)difftime(stop, start);
	printf("sum의 값: %lld\n", sum);
	printf("수행시간은 %lf초입니다.\n", duration);
}
