#include <iostream>
using namespace std;

int a[100];

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
	int tc, n; ios_base::sync_with_stdio(false);
	int sum, i, j;
	cin >> tc;

	while(tc--){
		sum = 0;
		cin >> n;
		for(i = 0; i < n; i++)
			cin >> a[i];

		for(i = 0; i < n-1; i++)
			for(j = i+1; j < n; j++)
				sum += gcd(a[i], a[j]);

		cout << sum << '\n';
	}
	return 0;
}
