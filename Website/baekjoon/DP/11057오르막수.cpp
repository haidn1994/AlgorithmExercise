#include <iostream>
using namespace std;

int d[1001][10];

int main(void)
{
	int n;
	ios_base::sync_with_stdio(false);
	int i, j, k;
	cin >> n;

	// 자리수가 1인 계단수를 세팅한다.
	for(i = 0; i <= 9; i++)
		d[1][i] = 1;

	// 핵심 로직!
	for(i = 2; i <= n; i++){
		for(j = 0; j <= 9; j++){
			d[i][j] = 0;
			for(k = 0; k <= 9-j; k++)
				d[i][j] += d[i-1][j+k];
			d[i][j] %= 10007;
		}
	}

	long long res = 0;
	for(i = 0; i <= 9; i++)
		res += d[n][i];
	res %= 10007;
	cout << res << '\n';
	return 0;
}
