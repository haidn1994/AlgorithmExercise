#include <iostream>
#include <algorithm>
using namespace std;

int v[1001];
int d[1001];

int main(void)
{
	int n; ios_base::sync_with_stdio(false);
	int i, j, res;
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> v[i];

	// 감소하는 부분 수열을 찾는 문제이므로, 거꾸로 구하면 된다.
	for(i = n; i >= 1; i--){
		d[i] = 1;
		// 여기도 마찬가지로 거꾸로 구하면 된다.
		for(j = i+1; j <= n; j++){
			if(v[i] > v[j] && d[i] < d[j]+1){
				d[i] = d[j] + 1;
			}
		}
	}

	// d[]에서 가장 큰 값(즉, 가장 긴 감소하는 부분 수열의 길이)를 얻는 수열
	res = d[1];
	for(i = 2; i <= n; i++){
		if(res < d[i])
			res = d[i];
	}
	cout << res << '\n';
	return 0;
}
