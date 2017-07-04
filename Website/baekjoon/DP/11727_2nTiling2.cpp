#include <iostream>
using namespace std;

int d[1001];

int tiling(int n)
{
	if(n == 1 || n == 0)
		return 1;
	if(d[n] > 0)
		return d[n];

	d[n] = tiling(n-1) + tiling(n-2) + tiling(n-2);
	d[n] %= 10007;
	return d[n];
}

int main(void)
{
	int input; ios_base::sync_with_stdio(false);
	cin >> input;
	cout << tiling(input) << '\n';

	return 0;
}
