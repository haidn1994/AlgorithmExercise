#include <iostream>
#include <algorithm>
using namespace std;

// d는 다이나믹 테이블
// 앞으로 값의 배열을 v라고 한다.
// 벡터를 사용할 때와 배열을 사용할 때는 off-by-one error를 각별하게 조심해야 한다!

int main(void)
{
	int n; ios_base::sync_with_stdio(false);
	int i, j, res;

	cin >> n;
	vector<int> v(n);
	for(i = 0; i < n; i++)
		cin >> v[i];

	vector<int> d(n);
	for(i = 0; i < n; i++){
		// 하나만 있어도 길이는 1이다. 
		d[i] = 1;
		for(j = 0; j < i; j++){
			// 조건 1. 수열의 맨 마지막 값 v[i]가 v[j]보다 더 커야 부분수열의 조건이 될 수 있다.
			// 조건 2. 조건1을 만족하면, d[j]에 있는 부분수열의 길이를 하나 늘린 값이 현재 값보다 더 큰지 알아본다.
			// 크다면 해당 값으로 교체한다.
			if(v[j] < v[i] && d[j]+1 > d[i])
				d[i] = d[j] + 1;
		}
	}

	// 범위는 [begin, end)이다.
	res = *max_element(d.begin(), d.end());
	cout << res << '\n';
	return 0;
}
