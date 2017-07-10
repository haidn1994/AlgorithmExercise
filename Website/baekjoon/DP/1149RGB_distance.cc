#include <iostream>
using namespace std;

#define min(x, y) (((x)>(y))?(y):(x))

// 현재 내가 선택한 d[n][0]은 빨강색 비용, d[n][1]은 초록색 비용, d[n][2]는 파랑색 비용
// 그 다음 하나씩 min값을 골라서 다음 d에 집어넣으면 된다.
int d[1001][3];

int main(void)
{
	int n, i; ios_base::sync_with_stdio(false);
	int res, cost[3];
	cin >> n;
	cin >> cost[0] >> cost[1] >> cost[2];

	d[1][0] = cost[0];
	d[1][1] = cost[1];
	d[1][2] = cost[2];
	for(i = 2; i <= n; i++){
		cin >> cost[0] >> cost[1] >> cost[2];
		
		d[i][0] = min(d[i-1][1], d[i-1][2]) + cost[0];
		d[i][1] = min(d[i-1][0], d[i-1][2]) + cost[1];
		d[i][2] = min(d[i-1][0], d[i-1][1]) + cost[2];
	}

	res = min(d[n][0], min(d[n][1], d[n][2]));
	cout << res << '\n';
	return 0;
}
