#include <iostream>
using namespace std;

int main(void)
{
	int cnt = 0;
	int n, i; cin >> n;

	// 팩토리얼의 특징을 분석하면 풀 수 있는 문제
	// 사실 이 문제는 손으로 풀어도 충분하다.
	for(i = 125; i <= n; i += 125) cnt++;
	for(i = 25; i <= n; i += 25) cnt++;
	for(i = 5; i <= n; i += 5) cnt++;

	cout << cnt << '\n';
	return 0;
}
