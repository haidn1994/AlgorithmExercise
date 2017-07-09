#include <stdio.h>

#define N 100
#define M 100
int map[N][M];

#define max(x, y) (((x)>(y))?(x):(y))

int max_joy(int n, int m)
{
	// 아래 3개는 어차피 대입되는 값이 곧 최대값이다.
	if(n == 0 && m == 0)
		return map[0][0];
	if(n == 0)
		return max_joy(n, m-1) + map[n][m];
	if(m == 0)
		return max_joy(n-1, m) + map[n][m];

	// 여기는 max를 사용해야 한다.
	if(n > 0 && m > 0)
		return max(max_joy(n-1, m), max_joy(n, m-1)) + map[n][m];
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
	
	printf("%d", max_joy(n-1, m-1));
	return 0;
}
