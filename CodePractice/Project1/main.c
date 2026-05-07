#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "apple";
	char str2[] = "apple";

	if (str1 == str2) {
		printf("Strings are equal\n");
	} else {
		printf("Strings are NOT equal\n");
	}

	return 0;
}