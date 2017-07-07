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
	for(i = n-1; i >= 0; i--){
		d[i] = 1;
		// 여기는 왜 이런지 알수가 없다.
		for(j = i; j < n; j++){
			if(v[j] > v[i] && d[j]+1 > d[i])
				d[i] = d[j] + 1;
		}
	}

	int res = d[1];
	for(i = 2; i <= n; i++){
		if(res < d[i]){
			res = d[i];
		}
	}
	cout << res << '\n';
	return 0;
}
