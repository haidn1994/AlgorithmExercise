#include <iostream>
using namespace std;

// 재귀함수를 활용하여 최대한 짧게 구현한 유클리드 호제법
//long long gcd (long long b, long long s) { return s : gcd(s, b%s) ? b; }

// 재귀함수를 사용하지 않고 구현한 유클리드 호제법
int gcd(int a, int b)
{
	int r;
	while(b != 0){
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	int a, b;
	int GCD, LCM;
	cin >> a >> b;

	GCD = gcd(a, b);
	LCM = GCD * (a/GCD) * (b/GCD);
	cout << GCD << '\n' << LCM << '\n';

	return 0;
}
