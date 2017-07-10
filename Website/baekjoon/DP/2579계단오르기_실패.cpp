#include <iostream>
using namespace std;

int v[301];
int d[301];

int main(void)
{
	int n; ios_base::sync_with_stdio(false);
	int i, res;

	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> v[i];

	d[1] = v[1];
	d[2] = v[1] + v[2];
	// 일부러 마지막 계단은 제외했다. 여기에 더해서 마지막 수의 경우 2번 연속하는 경우도 빼야 한다.
	// 예외처리를 확실하게 하라!
	for(i = 3; i < n; i++){
		// 0번 연속하는 경우: 이번 계단은 넘긴다 = 다음 계단을 기약한다. = 3칸 연속으로는 짚지 못한다.
		d[i] = d[i-1];
		// 1번 연속하는 경우: 지금 계단을 짚었지만 저번 계단은 짚지 않았다. = 2칸 뛰기
		if(d[i] < d[i-1] + v[i])
			d[i] = d[i-1] + v[i];
		if(d[i] < d[i-2] + v[i])
			d[i] = d[i-2] + v[i];
		// 여기서 예외처리가 한번 들어가야 한다.
		if(d[i] < d[i-3] + v[i] + v[i-1])
			d[i] = d[i-3] + v[i] + v[i-1];
	}
	// 여기에 최대값을 고르는 코드가 이미 있기 때문에 아래에서 따로 구해줄 필요는 없다.

	for(i = 1; i <= n; i++)
		cout << "d[i]: " << d[i] << '\n';

	res = d[n-1];

	// 마지막 계단의 값을 더해주었다.
	cout << res + v[n] << '\n';
	return 0;
}
