#include <stdio.h>
#define ROWS 3
#define COLS 5


int matrix_change(int A[ROWS][COLS]) {
	return A[COLS][ROWS];
}
//행렬 전치 함수
void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]) { 
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			B[c][r] = A[r][c];
		}
	}
}

void matrix_print(int A[ROWS][COLS]) {
	printf("===============\n");
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			printf("%d ", A[r][c]);
		}
		printf("\n");
	}
	printf("===============\n");
}

void matrix_print_T(int B[ROWS][COLS]) {
	printf("===============\n");
	for (int r = 0; r < COLS; r++) {
		for (int c = 0; c < ROWS; c++) {
			printf("%d ", B[r][c]);
		}
		printf("\n");
	}
	printf("===============\n");
}

int main() {
	int array1[ROWS][COLS] = { {2,3,0,1,2 },{ 8,9,1,3,4 },{ 7,0,5,6,7 } };
	int array2[COLS][ROWS];
	matrix_print(array1);
	matrix_transpose(array1, array2);
	matrix_print_T(array2);
	return 0;
}