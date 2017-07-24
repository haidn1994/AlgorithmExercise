#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int int_pow(int base, int exp)
{
	int res = 1, i;
	// 이 코드는 0부터 시작하면 절대로 안된다! 0부터 시작해야 한다!
	for(i = 1; i <= exp; i++)
		res *= base;
	return res;
}

int main(void)
{
	string s;
	int res = 0, temp;
	int n, b, i;
	cin >> s;
	cin >> b;

	// 여기도 마찬가지로 뒤집어주어야 한다.
	reverse(s.begin(), s.end());
	for(i = 0; i < s.size(); i++){
		if((int)(s[i] - '0') > 9)
			temp = (int)(s[i] - 'A' + 10);
		else
			temp = (int)(s[i] - '0');
		res += temp * int_pow(b, i);
	}
	cout << res <<'\n';
	return 0;
}
