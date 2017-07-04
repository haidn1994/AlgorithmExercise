#include <iostream>
using namespace std;

int d[1001];

int tiling(int n)
{
	// 예외 처리
	// 1. 여기를 ||로 했어야 하는데 &&로 했다!
	// 1인 경우와 0인 경우 2가지를 전부 1로 채워야 한다?
	if(n == 0 || n == 1) 
		return 1;
	// 다이나믹 프로그래밍 활용
	if(d[n] > 0) 
		return d[n];
	// 1*2타일을 먼저 채워넣은 경우 + 2*1타일을 먼저 채워넣은 경우
	// 다이나믹 테이블에 먼저 저장해야만 한다. 그래야 다이나믹 프로그래밍을 사용하는 의미가 있다!
	d[n] = tiling(n-1) + tiling(n-2);
	// 오버플로우 에러를 방지하기 위해서 넣어주는 코드! 기억하자!
	d[n] %= 10007;

	return d[n];
}
int main(void)
{
	int input; 
	ios_base::sync_with_stdio(false);
	cin >> input;
	cout << tiling(input) << '\n';

	return 0;
}
