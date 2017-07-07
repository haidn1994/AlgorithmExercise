// 출처: https://github.com/kijeongeun/algorithm/blob/master/boj_11066_%ED%8C%8C%EC%9D%BC_%ED%95%A9%EC%B9%98%EA%B8%B0.md
// 모든 문서와 코드의 권한은 위 URL의 주인에게 있다.

/*
	이 문제를 풀려면 다음과 같은 지식이 있을 때 쉽게 풀 수 있다.
	1. 연쇄 행렬의 최소 곱셈 알고리즘 -> 이 방법을 알고 있다면, 그리고 연관성을 찾았다면 기억을 더듬어서 찾을 수 있다.
	2. Knuth Optimaization: 크누스 최적화 -> 위의 지식을 알면서, 크누스 최적화에 대한 지식도 알고 있다면
	   메모리를 조금 더 쓰고 더 빠른 시간안에 정답을 찾을 수 있다.
	
	문제설명: 최종적으로 구하고 싶은 것은 두 수의 합이다. 경우는 3가지가 있다.

	1. 자기 자신을 합하는 경우: 합할 수 없는 것이나 마찬가지이므로 0을 반환한다.
	2. 인접한 두 수를 합하는 경우: 이 경우만 더할 수 있다는 점을 명심하라!
	3. 세 개의 파일을 합하는 경우: ??? 설명을 봐도 잘 모르겠다.
	
	주의 사항: 최소값을 구하라고 했으니 최소값을 구하는 코드가 있어야 한다.
	언제 2차원 배열을 사용하고, 안하는지 정확하게 알아야 하는데 그것이 문제로다.
	
	따라서 점화식을 세우면 다음과 같다.
	dp[i부터][j까지 합치는데 드는 비용] = dp[i][k] + dp[k+1][j] + sum[i부터 j까지의 합]
 */

// 모든 코드의 권한은 출처 URL의 주인에게 있습니다.
#include <iostream>
#include <algorithm>
#define INF 0x7fffffff/2
using namespace std;


int arr[501];
int dp[501][501];
int sum[501]; // 1~인덱스번째 까지의 합이 각각 들어있다.

// top-down방식으로 풀었다.

int f(int start, int end)
{
	// 자기 자신이 합쳐질때: 즉, 합쳐지지 않는 것이나 다름없다.
	if (start >= end) 
		return 0; 

	// 이미 값이 있을 때: 테이블을 참고하여 반환한다.
	if (dp[start][end] != -1) 
		return dp[start][end];

	// 이웃한 경우: 문제에서 이웃한 경우에만 합치는 것을 허용한다.
	if (end == start + 1)
		return arr[start] + arr[end];

	// 이런 문제를 보면 갑자기 INF가 등장하는데, 왜 그런지는 잘 모르겠다.
	dp[start][end] = INF;

	for (int i = start; i <= end; i++) {
		int tmp = f(start, i) + f(i + 1, end) + sum[end]-sum[start-1];
		// 최소값을 집어넣자.
		dp[start][end] = min(dp[start][end], tmp);
	}

	return dp[start][end];
}

void initialize(int n)
{
	// 초기화
	for (int i = 1; i <= n; i++) {
		sum[i] = 0;
		for (int j = 1; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;

		initialize(n);

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		cout << f(1, n) <<'\n';
	}
	return 0;
}
