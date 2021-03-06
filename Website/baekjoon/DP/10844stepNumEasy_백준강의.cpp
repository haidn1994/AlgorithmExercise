/*
	이 문제는 "계단 수"라는 문제로부터 파생되었다.
	
	앞서 풀어본 이친수 문제는 마지막 자리에 올 수 있는 문자가 1아니면 0밖에 없어서 
	1차원 배열로도 문제를 푸는 데 지장이 없지만, 이 문제부터는 마지막 자리에 오는 수의 종류가 많아서(10개)
	2차원 배열을 사용해야만 다이나믹 프로그래밍을 통해서 문제를 쉽게 풀 수 있다.
	어쨌든 해당 문제부터 적극적으로 2차원 배열이 사용되기 시작하는데
	배열의 차원 수가 하나씩 더 늘어날 때마다 생각할 것이 더 많아진다.
	그렇다면, 이제 차근 차근 하나씩 생각해 보자.

	먼저 정의를 생각해 보자.
	예를 들어, 45656이란 수를 생각하자.
	이 수는 인접한 모든 자리수의 차이가 1이 난다.
	이런 수를 계단 수라고 한다. (단, 0으로 시작하는 숫자는 없다.)
	그런데 이제 수의 길이가 N이라고 할 때 계단수의 개수를 구하려고 한다.

	다이나믹 테이블 D[N][L]이 주어졌을 때, 
	다이나믹 테이블의 1번째 차원은 "N자리 계단 수"의 개수를 뜻한다. 
	그리고 2번째 차원에는 "마지막 수 L"이 들어간다. 
	그리고 1번째 차원에 딸려 있는 모든 요소를 더하면 N자리 계단의 수를 얻을 수 있다.

	N이 1일때는 무조건 9로 정의한다. 
	예를 들어 N이 2일때는 계단수의 개수는 17개다. 
	위에서 언급한 정의에 기초하여 만들면 N이 1부터 8까지인 경우에는 다음과 같은 점화식을 얻을 수 있다. 
	D[N][L] = D[N-1][L-1] + D[N-1][L+1] (1 <= L <= 8)
	
	그리고 0과 9는 예외인데, 0은 에서 -1을 하면 -1인데 이는 십진법의 자리수에 들어갈 수 없다. 
	9의 경우에는 +1을 하면 10인데 이 역시 십진법의 자리수에 들어갈 수 없다. 
	따라서 0과 9에 대해서는 다음과 같은 점화식을 얻을 수 있다. 
	D[N][0] = D[N-1][1] 
	D[N][9] = D[N-1][8] 

	이를 top-down방식으로 풀어보도록 한다.
 */
#include <iostream>
using namespace std;

long long d[101][10];
long long mod = 1000000000; // 10^9

int main(void)
{
	int n;
	int i, j; 
	ios_base::sync_with_stdio(false);
	cin >> n;

	// 자리수가 1인 계단수를 세팅한다.
	for(i = 1; i <= 9; i++)
		d[1][i] = 1;

	// 핵심 로직!
	for(i = 2; i <= n; i++){
		for(j = 0; j <= 9; j++){
			d[i][j] = 0;
			if(j-1 >= 0)
				d[i][j] += d[i-1][j-1];
			if(j+1 <= 9)
				d[i][j] += d[i-1][j+1];
			d[i][j] %= mod;
		}
	}

	long long res = 0;
	for(i = 0; i<= 9; i++)
		res += d[n][i];
	res %= mod;
	cout << res << '\n';
	return 0;
}
