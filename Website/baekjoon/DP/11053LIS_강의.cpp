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
		// 가... 아니고, 1은 길이일때 통하는 말이고, "수열의 합"으로 문제에서 주어진 자료가 바뀌었으므로 
		// d[i] = a[i]가 보다 알맞은 초기값이다.
		d[i] = v[i];
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
		d[i] = 1;
		for(j = 0; j < i; i++){
			if(v[j] > v[i] && d[j] > d[i])
				d[i] = d[j] + 1;
		}
	}

	res = *max_element(d.begin(), d.end());
	cout << res << '\n';
	return 0;
}
