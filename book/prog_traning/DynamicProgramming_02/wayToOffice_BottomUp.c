
#include <stdio.h>

#define N 100
#define M 100
int map[N][M];

// 모든 경우의 수를 구하는 프로그램이므로 다이나믹에 적합하다.
// 점화식의 경우의 수가 많으면 역시 경우에 맞춰서 일일이 점화식을 세워줘야 한다!
// 명심하자!
long long d[N][M];

void calculate_path(int n, int m)
{
	int i, j;

	d[0][0] = map[0][0];
	// 예외처리 및, 정의에 따른 계산
	for(i = 0; i < n; i++){
		if(map[i][0] == 0)
			d[i][0] = 0;
		else
			d[i][0] = d[i-1][0];
	}
	for(j = 0; j < m; j++){
		if(map[0][j] == 0)
			d[0][j] = 0;
		else
			d[0][j] = d[0][j-1];
	}
	for(i = 1; i < n; i++){
		for(j = 1; j < m; j++){
			if(d[i][j] == 0)
				d[i][j] = 0;
			else
				d[i][j] = d[i-1][j] + d[i][j-1];
		}
	}
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
	printf("%lld", d[n-1][m-1]);
	return 0;
}
