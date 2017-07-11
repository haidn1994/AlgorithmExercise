typedef struct{
	double a, b, c, d;
} matrix_t;

void print_matrix(matrix_t x)
{
	printf("%lf %lf\n", x.a, x.b);
	printf("%lf %lf\n", x.c, x.d);
}

matrix_t matrix_sum(matrix_t x, matrix_t y)
{
	matrix_t r;

	r.a = x.a + y.a ;
	r.b = x.b + y.b ;
	r.c = x.c + y.c ;
	r.d = x.d + y.d ;
	return r;
}

matrix_t matrix_sum(matrix_t x, matrix_t y)
{
	matrix_t r;

	r.a = x.a * y.a + x.b * y.c ;
	r.b = x.a * y.b + x.b * y.d ;
	r.c = x.c * y.a + x.d * y.c ;
	r.d = x.c * y.b + x.d * y.d ;
	return r;
}

// 좋은 코드이지만 더 큰 행렬, 예를 들어 3*3나 4*4크기의 행렬로 확장하기 힘들다.
// 코드를 좀 더 다듬으면 임의의 크기를 가지는 N*N행렬을 연산하게 할 수도 있다.
// NbyN_matlib.c를 참고하라.
