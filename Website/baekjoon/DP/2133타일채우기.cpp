#include <iostream>
using namespace std;


// 오답!: 하지만 2개는 맞았다.
// 1: 짝수만 양수를 반환한다는 사실, 그리고 가장 기본적인 점화식 d[n] = tiling(n-2)*3
// 2: 4+2n마다 새로운 패턴이 나온다는 사실, 사실 이게 가장 핵심인데 코드로 어떻게 표현해야 할지 잘 모르겠다.
int d[31];

long long tiling(long long n)
{
	if(n < 2 && n%2 != 0)
		return 0;
	if(n == 2)
		return 3;
	if(d[n] > 0)
		return d[n];

	// 4+2n개 마다 나타나는 모양을 반영해야 한다.
	d[n] += (tiling(n-2)*3);
	if((n-4)%2 == 0)
		d[n] += (tiling(n-2)*3)
	return d[n];
}

int main(void)
{
	long long n; ios_base::sync_with_stdio(false);
	cin >> n;

	cout << tiling(n) << '\n';
	return 0;
}
