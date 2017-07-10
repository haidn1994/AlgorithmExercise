#include <iostream>
using namespace std;

#define min(x, y) (((x)>(y))?(y):(x))
// 문제에서 구하고자 하는 것 "연산을 사용하는 횟수의 최소값"

// 다이나믹 테이블에 담기는 값 해당 인덱스를 "수"로 보았을 때 연산을 사용하는 횟수의 최소값
// 인덱스를 "대상이 되는 수"로 사용하기 때문에 +1을 해줘야 한다.
int d[1000001];

int main(void)
{
	int n, i; ios_base::sync_with_stdio(false);
	cin >> n;

	d[1] = 0;
	d[2] = d[3] = 1;
	// 여기가 왜 맞는 건지 잘 모르겠지만 일단 이유를 생각해보면...
	// 이유는 먼저 d[i] = d[i-1] + 1;에서 1을 먼저 더해주었기 때문에 
	// 조건문에서 +1을 하지 않아도 +1을 한것으로 간주되어서... 일까?
	for(i = 4; i <= n; i++){
		d[i] = d[i-1] + 1;
		if(d[i] > d[i/3] && i%3 == 0)
			d[i] = d[i/3] + 1;
		if(d[i] > d[i/2] && i%2 == 0)
			d[i] = d[i/2] + 1;
	}

	cout << d[n] << '\n';
	return 0;
}
