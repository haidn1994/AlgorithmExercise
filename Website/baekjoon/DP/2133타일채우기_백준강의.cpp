#include <iostream>
using namespace std;

long long d[31];

int main(void)
{
	int n; ios_base::sync_with_stdio(false);
	int i, j;
	cin >> n;
	// 확실히 0은 1이 맞나보다.
	d[0] = 1;
	// 그리고 홀수는 0이 맞다.
	for(i = 2; i <= n; i+=2){
		d[i] = d[i-2]*3;
		// 4+2n마다 나오는 패턴을 반영한다.
		for(j = i-4; j >= 0; j-= 2)
			d[i] += d[j]*2;
	}

	cout << d[n] << '\n';
	return 0;
}
