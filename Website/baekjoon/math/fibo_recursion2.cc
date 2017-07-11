#include <iostream>
using namespace std;

long long d[91];

long long fibo(long long n)
{
	if(n == 0)
		return d[0];
	if(n == 1)
		return d[1];
	if(d[n] > 0)
		return d[n];

	d[n] = fibo(n-1) + fibo(n-2);
	return d[n];
}

int main(void)
{
	long long n; cin >> n;
	d[1] = 1;
	cout << fibo(n) << '\n';
	return 0;
}
