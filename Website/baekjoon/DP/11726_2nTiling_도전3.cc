#include <iostream>
using namespace std;

int d[1001];

int mod = 10007;

int go(int n)
{
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	if(d[n] > 0)
		return d[n];

	d[n] = go(n-1) + go(n-2);
	d[n] %= mod;

	return d[n];
}

int main(void)
{
	int n;
	cin >> n;

	cout << go(n) << '\n';
	return 0;
}
