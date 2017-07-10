#include <iostream>
using namespace std;

// d[k]에 딸려있는 모든 2차원 배열의 값을 더하면 모든 경우의 수를 얻을 수 있다.  
int d[10001][101];

// 동전의 종류마다 값을 저장한다.
int coin[101];

// 경우의 수를 구하는 문제이므로 모두 더해야 한다.
// 그런데 그리디 알고리즘하고 다이나믹 프로그래밍하고 무슨 관련이 있을까?
int main(void)
{
	int n, k;
	int res = 0;
	int i, j;
	cin >> n >> k;
	for(i = 1; i <= n; i++)
		cin >> coin[i];
	for(i = 1; i <= n; i++)
		d[0][i] = 1;

	for(i = 1; i <= k; i++){
		for(j = 1; j <= n; j++){
			// 음수 인덱심 보호 및, 동전을 딱 나누어 떨어지게 하기 위함
			if(i - coin[j] >= 0)
				d[i][j] += d[i-coin[j]][j];
		}
	}

	for(i = 1; i <= n; i++)
		res += d[k][i]; 
	cout << res << '\n';
	return 0;
}
