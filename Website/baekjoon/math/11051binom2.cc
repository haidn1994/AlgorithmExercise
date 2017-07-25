#include <iostream>
using namespace std;

int d[1001][1001];

int binom(int n, int r)
{
	if(n == r || r == 0)
		return 1;
	if(d[n][r] > 0)
		return d[n][r];

	d[n][r] = binom(n-1, r-1) + binom(n-1, r);
	d[n][r] %= 10007;
	return d[n][r];
}

int main(void)
{
	int n, r; cin >> n >> r;
	cout << binom(n, r) << '\n';
	return 0;
}
