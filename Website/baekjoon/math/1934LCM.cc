#include <iostream>
using namespace std;

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
	int tc, a, b; ios_base::sync_with_stdio(false);
	int GCD, LCM;
	cin >> tc;

	while(tc--){
		cin >> a >> b;

		GCD = gcd(a, b);
		LCM = GCD * (a/GCD) * (b/GCD);
		cout << LCM << '\n';
	}
	return 0;
}
