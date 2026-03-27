#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int i;
	int l;
	for (i = 0; i <= 4; i++)
	{
		for (l = 9; l >= 0; l--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}