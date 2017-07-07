#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
		// 마찬가지로 하나만 있어도 길이는 1이다.
		d[i] = 1;
		for(j = 0; j < i; j++){
			// 조건 1. 수열의 맨 마지막 값 v[i]가 v[j]보다 더 커야 부분 수열의 조건이 될 수 있다. -> 오답!
			// 사실 조건1은 만족하지 않아도 상관없다. sum[i]가 sum[j]보다 더 크기만 하면 길이는 별로 상관없다.

			// 조건 2. 수열의 모든 합을 담은 sum[i]가 v[j]보다 더 커야 부분 수열의 조건이 될 수 있다.
			// 조건 3. 조건1과 조건2를 만족하면 d[j]에 있는 부분수열의 길이를 하나 늘린 값이 현재 값보다 큰지 알아 본다.
			// 조건1, 조건2, 조건3을 모두 만족하면 해당 값으로 교체한다.
			if(v[j] < v[i] && d[j]+v[i] > d[i])
				d[i] = d[j] + v[i];
		}
	}   

	res = *max_element(d.begin(), d.end());
	cout << res << '\n';
	return 0;
}

