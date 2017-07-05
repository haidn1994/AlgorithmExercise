#include <iostream>
#include <vector>
using namespace std;

// 여기서 눈여겨 봐야할 것은 벡터의 사용법과 
// min함수와 max함수의 사용법이다!

int main(void)
{
	int n; ios_base::sync_with_stdio(false);
	int i, j;
	cin >> n;
	// 내부에 들어있는 함수나 범용성을 원한다면 vector를 쓰는 것이 좋다
	vector<int> a(n+1);
	vector<int> d(n+1);

	// 붕어빵 세트메뉴의 가격을 받는 로직이다.
	for(i = 1; i <= n; i++)
		cin >> a[i];
	// 버블소트에서 이런 코드모양을 많이 보았을 것이다. 기억하라!
	for(i = 1; i <= n; i++){
		for(j = 1; j <= i; j++){
			d[i] = max(d[i], d[i-j] + a[j]);
		}
	}

	cout << d[n] << '\n';
	return 0;
}
