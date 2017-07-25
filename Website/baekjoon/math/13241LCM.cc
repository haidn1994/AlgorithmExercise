#include <iostream>
using namespace std;

typedef long long int lli;

lli gcd(lli b, lli s) { return s ? gcd(s, b%s) : b; }

int main(void)
{
	lli a, b;
	lli l, g;
	cin >> a >> b;

	g = gcd(a, b);
	l = g * (a/g) * (b/g);

	cout << l << '\n';
	return 0;
}
