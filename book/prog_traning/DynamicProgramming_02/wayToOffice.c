/*
 *	주된 논리는 다음과 같다. 
 *
 *	1. 지루해씨가 가고자하는 길이 공사장이 아니라면 map[i][j]에는 1로 적는다. 공사장이면 0
 *	2. map[i][j]가 0이라면 공사장이므로 path도 0을 반환한다.
 *	3. map[i][j]가 1이라면 다음과 같이 경우를 나눈다.
 *
 *		3-1. i = 0, j = 0이면 1을 반환한다. 사무실에 도착했다는 뜻이다.
 *		3-2. i > 0, j = 0이면 path(i-1, j)를 반환한다.
 *		3-3. i = 0, j > 0이면 path(i, j-1)를 반환한다.
 *		3-4. i > 0, j > 0이면 path(i-1, j) + path(i, j-1)을 반환한다.
 *
 * 이제 책에서 나온대로 코드를 작성해보자.
 */
#include <stdio.h>

#define N 100
#define M 100
int map[N][M];

// 재귀함수로 작성해보자.
long long num_path(int n, int m)
{
	if(n == 0 && m == 0)
		return 1;
	if(map[n][m] == 0)
		return 0;

	return ((n > 0) ? num_path(n - 1, m) : 0) +
		   ((m > 0) ? num_path(n, m - 1) : 0);
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
// 하지만 이 방법은 너무나 중복계산을 많이 하기때문에 N과 M이 조금만 커져도 무척 느리다.
