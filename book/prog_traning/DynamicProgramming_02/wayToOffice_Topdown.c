/*
 * 너무 느리므로 다이나믹 프로그래밍을 적용해서 문제를 풀어보도록 한다.
 *
 *
 */
#include <stdio.h>

#define N 100
#define M 100
int map[N][M];

// 모든 경우의 수를 구하는 프로그램이므로 다이나믹에 적합하다.
long long d[N][M];

// 재귀함수로 작성해보자.
// 이건 top-down방식이고,  책에서 소개하는 방법은 bottom-up인데, 
// 이건 다른 소스코드에서 살펴본다.
long long num_path(int n, int m)
{
	// 2개의 기저사례
	if(n == 0 && m == 0)
		return 1;
	if(map[n][m] == 0)
		return 0;

	// 테이블에 요소가 들어있다면
	if(d[n][m] > 0)
		return d[n][m];

	d[n][m] = ((n > 0) ? num_path(n - 1, m) : 0) +
		      ((m > 0) ? num_path(n, m - 1) : 0);
	return d[n][m];
}

int main(void)
{
	int n, m;
	int i, j;

input:
	scanf("%d %d", &n, &m);
	if(n > 100 || m > 100){
		printf("impossible\n");
		goto input;
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &map[i][j]);
		}
	}

	// main algorithm
	printf("%lld", num_path(n-1, m-1));
	return 0;
}
