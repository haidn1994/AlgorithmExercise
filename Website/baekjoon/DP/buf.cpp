#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;

/*
    *백준 알고리즘 기초 강의에서 발췌*

	이 문제를 수형도를 통한 경우의 수를 세는 문제가 아닌, "부분 문자열"로 접근하여 풀어보자면
	이차원 배열을 통해서 문제를 풀어볼 수도 있다.

	D[i][j] = i자리 이친수의 개수 중에서 j로 끝나는 것의 개수

	첫번째 정의로 부터...
	1. 0으로 시작하지 않는다.
	2. 1의 정의로 부터 D[1][0] = 0
	3. D[1][1] = 1

	두번째 정의로 부터...
	1. 1다음에는 1이 올 수 없다. 따라서 가능한 경우는 다음과 같다.
	2. 0으로 끝나는 경우(D[i][0])
		* 앞에 0과 1이 올 수 있다.
		* D[i-1][0] + D[i-1][1]
	3. 1로 끝나는 경우(D[i][1])
		* 앞에 1은 올 수 없다. 즉, 0만 올 수 있다.
		* D[i-1][0]

	그러므로, 
	D[1][0] = 0
	D[1][1] = 1 이다.

	그리고
	D[n][1] = d[n-1][0]
	D[n][0] = d[n-1][0] + d[n-1][1]

	따라서 정답은 D[n][0] + D[n][1]

 */
long long int d[91][2];

long long int vinary(int n, int m)
{
	if(n == 1)
		return d[1][m];
	if(d[n][m] > 0)
		return d[n][m];

	d[n][0] = vinary(n-1, 0) + vinary(n-1, 1);
	d[n][1] = vinary(n-1, 0);
	return d[n][m];
}

int main(void)
{
	int n;
	ios_base::sync_with_stdio(false);
	scanf("lld\n", &n);
	d[1][0] = 0;
	d[1][1] = 1;
	printf("%lld\n", vinary(n, 0) + vinary(n, 1));

	return 0;

}
