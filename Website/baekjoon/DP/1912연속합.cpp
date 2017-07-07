#include <iostream>
using namespace std;

int v[100001];
int d[100001];

int main(void)
{
	int n; ios_base::sync_with_stdio(false);
	int i;
	int res;

	// 입력
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> v[i];

	// 핵심 로직
	d[1] = v[1];
	// 연속합 문제의 특징을 살펴보면, 연속합을 만드는 경우는 2가지로 나눌 수 있다.
	// 1. 기존의 연속합을 유지하는 경우
	// 2. 새로운 연속합을 시작하는 경우
	for(i = 2; i <= n; i++){
		// 새로운 연속합을 시작하는 경우로, 기존 연속합(d[i-1])과 현재 값(v[i])을 더했는데도 불구하고,
		// 현재 값보다 더 작다면 새로운 연속합을 시작한다.
		if((d[i-1] + v[i]) < v[i])
			d[i] = v[i];
		// 아니라면 계속 연속합을 유지하면 된다.
		else
			d[i] = d[i-1] + v[i];
	}

	// d에서 가장 큰 값을 골라서 출력
	res = d[1];
	for(i = 2; i <= n; i++)
		if(res < d[i])
			res = d[i];
	cout << res << '\n';
	return 0;
}
