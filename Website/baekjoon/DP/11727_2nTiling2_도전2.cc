#include <iostream>
using namespace std;

int d[1001];

int mod = 10007;

int main(void)
{
	int n, i;
	cin >> n;

	d[1] = 1;
	d[2] = 3;
	for(i = 3; i <= n; i++){
		d[i] = d[i-1] + d[i-2] + d[i-2];
		d[i] %= mod;
	}

	cout << d[n] << '\n';
	return 0;
}
