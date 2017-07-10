#include <iostream>
using namespace std;

#define max(x, y) (((x)>(y))?(x):(y))

// d[i][0], d[i][1], d[i][2]에서 최대값을 구하면 된다.
int d[301][3];

// 계단의 점수
int score[301];

int main(void)
{
	int res; ios_base::sync_with_stdio(false);
	int n, i; 
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> score[i];

	// d[i][0]은 없는 경우이므로 계산하지 않는다.
	d[1][2] = score[1];
	d[2][2] = score[1] + score[2];
	d[2][1] = score[2];
	for(i = 3; i <= n; i++){
		d[i][1] = max(d[i-2][1], d[i-2][2]) + score[i];
		d[i][2] = d[i-1][1] + score[i];
	}

	res = max(d[n][1], d[n][2]); 
	cout << res << '\n';
	return 0;
}
