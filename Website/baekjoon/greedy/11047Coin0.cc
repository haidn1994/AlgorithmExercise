#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, k; ios_base::sync_with_stdio(false);
	int sum = 0, ans = 0;
	int i;
	cin >> n >> k;
	vector<int> coins(n);

	for(i = 0; i < n; i++)
		cin >> coins[i];
	// 판단하는 함수가 틀렸다. 좀 더 탐욕적인 방법을 적용해야 한다.
	// 가장 큰 액수부터... 차례대로..
	for(i = n-1; i >= 0; i--){
		sum += k/coins[i];
		k %= coins[i];
	}
	ans = sum;
	cout << ans << '\n';

	return 0;
}
