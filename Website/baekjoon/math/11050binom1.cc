#include <iostream>
using namespace std;

int binom(int n, int r)
{
	if(n == r || r == 0)
		return 1;

	return binom(n-1, r-1) + binom(n-1, r);
}

int main(void)
{
	int n, r; cin >> n >> r;
	cout << binom(n, r) << '\n';
	return 0;
}
