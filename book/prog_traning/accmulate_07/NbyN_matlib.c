#include <stdio.h>

#define N 2

typedef struct{
	double e[N][N];
} matrix_t;

void input_matrix()
{
	matrix_t r;
	int i, j;

	for(i = 0;i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%lf", &(r.e[i][j]));
	return r;
}

matrix_t matrix_sum(matrix_t x, matrix_t y)
{
	matrix_t r;
	int i, j;

	for(i = 0;i < N; i++)
		for(j = 0; j < N; j++)
			r.e[i][j] = x.e[i][j] + y.e[i][j];
	return r;
}

void matrix_prod(matrix_t x, matrix_t y)
{
	matrix_t r;
	double s;
	int i, j, k;

	// 이 코드에서 행렬의 곱은 3중 루프안에 들어가 있어 O(n^3)의 시간복잡도를 보이지만,
	// 실제로는 1969년 풀커 스트라센(Volker Strassen)이 약 O(n^2.807)의 시간 복잡도 함수를 가지는
	// 행렬 곱셈 알고리즘을 찾은 것을 발단으로, 현재까지 다양한 행렬 곱셈의 복잡도를 낮추는 연구 결과를 발표했다고 한다.
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++){
			s = 0;
			for(k = 0; k < N; k++)
				s += x.e[i][k] * y.e[k][j];
			r.e[i][j] = s;
		}

	return r;
}

void print_matrix(matrix_t x, matrix_t y)
{
	int i, j;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			printf("%lf ", x.e[i][j]);
		printf("\n");
	}
}

int main(void)
{
	matrix_t x, y;

	printf("Input X: ");
	x = input_matrix();
	printf("Input Y: ");
	y = input_matrix();

	printf("X+Y:\n");
	print_matrix(matrix_sum(x, y));
	printf("X*Y:\n");
	print_matrix(matrix_prod(x, y));

	return 0;
}
