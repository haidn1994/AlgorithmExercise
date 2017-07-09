#include <stdio.h>

#define N 100
#define M 100
int map[N][M];

int d[N][M];

#define max(x, y) (((x)>(y))?(x):(y))

void calculate_max_joy(int n, int m)
{
	int i, j;

	// 아래 3개는 어차피 대입되는 값이 곧 최대값이다.
	// 좀 참고는 하긴 했지만 일단은 맞았다!
	d[0][0] = map[0][0];
	for(i = 0; i < n; i++){
			d[i][0] = map[i][0] + d[i-1][0];
	}
	for(j = 0; j < m; j++){
			d[0][j] = map[0][j] + d[0][j-1];
	}
	for(i = 1; i < n; i++)
		for(j = 1; j < m; j++)
			d[i][j] = max(map[i-1][j], map[i][j-1]) + map[i][j];
}

int main(void)
{
	int n, m;
	int i, j;

input:
	scanf("%d %d", &n, &m);
	if(n > 100 || m > 100){
		printf("impossible. try diffrent number\n");
		goto input;
	}
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf("%d", &map[n][m]);
	
	printf("%d", d[n-1][m-1]);
	return 0;
}
