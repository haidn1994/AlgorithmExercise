#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int int_pow(int base, int exp)
{
	int res = 1, i;
	for(i = 1; i <= exp; i++)
		res *= base;
	return res;
}

int main()
{
	int a, b, m; ios_base::sync_with_stdio(false);
	int decimal = 0, temp;
	int i;
	cin >> a >> b >> m;
	vector<int> arr(m);
	// 이건 높은 자리수임, 낮은 자리수부터 하나씩 차례대로 해야 한다.
	for(i = m-1; i >= 0; i--)
		cin >> arr[i];
	for(i = 0; i < m; i++)
		decimal += arr[i] * int_pow(a, i);

	// 이제 10진법수 dec_temp를 0이 될 때까지 계속 나머지를 구하면서 
	// b진법으로 바꾸면 된다.
	vector<int> res;
	while(decimal != 0){
		temp = decimal % b;
		decimal /= b;
		res.push_back(temp);
	}

	reverse(res.begin(), res.end());
	for(i = 0; i < res.size(); i++)
		cout << res[i] << ' ';
	cout << '\n';
	return 0;
}
