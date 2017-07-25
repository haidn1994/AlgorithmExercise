#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll b, ll s) { return s ? gcd(s, b%s) : b; }

int main(void)
{
	int a = 9, b = 12;
	int l, g;

	// 두 수의 최대공약수
	g = gcd(a, b);
	// 두 수의 최소공배수
	l = g * (a/g) * (b/g);
	cout << "9와 12의 GCD: " << g << '\n';
	cout << "9와 12의 LCM: " << l << '\n';
	return 0;
}
