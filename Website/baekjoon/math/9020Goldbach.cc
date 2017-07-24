/*
	이 문제를 푸는 법
	0. 당연히 에라토스테네스의 체를 사용해서 10000까지의 소수를 전부 구해놓고 시작한다.
	1-1. 골드바흐 파티션을 구하기 위해서는 n부터 sqrt(n)까지만 둘러보면 알 수 있다. (추측)
	1-2. 골드바흐 파티션을 구하기 위해서는 n부터 n/2까지만 둘러보면 알 수 있다. (확신)
	2. 골드바흐 파티션이 여러개 나온다면 두 소수의 차이가 가장 작은 것을 출력해야 하는데, 
	이는 다이나믹 프로그래밍으로 구할 수 있다.
 
	이 코드는 실패한 것 같다.
 */

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

ll max_n = 10000;
bool isPrime[10001];

void eratosthenes(){
	ll i, j;
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	
	for(i = 2; i*i <= max_n; i++){
		if(isPrime[i])
			for(j = i*i; j <= max_n; j += i)
				isPrime[j] = false;
	}
}

int main()
{
	int tc, n, sub;
	int i, j;
	eratosthenes();
	scanf("%d", &tc);

	while(tc--){
		scanf("%d", &n);
		vector<pair<int, int>> g;
		for(i = 1; i <= n; i++)
			if(isPrime[i] && isPrime[max_n-i])
				g.push_back(make_pair(i, max_n-i));

		sub = 0, j = 0;
		for(i = 0; i < g.size(); i++){
			if(sub > g[i].second - g[i].first){
				sub = g[i].second - g[i].first;
				j = i;
			}
		}

		printf("%d %d\n", g[j].first, g[j].second);
	}
	return 0;
}
