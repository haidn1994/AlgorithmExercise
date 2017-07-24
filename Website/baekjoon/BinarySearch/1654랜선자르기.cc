// 여기서 완벽하게 잘 동작하는 이진 탐색의 예를 알아야 한다는 사실을 알 수 있다.
// 주로 두 수의 나눗셈에서 그 문제가 발생하는데, 잘 기억해 두자.
#include <cstdio>
// cstdio와 cstring은 namespace std가 필요없다!

long long a[10000];
int n, k;

bool is_size_valid(long long x)
{
	int cnt = 0;
	int i;
	// 랜선을 x라는 길이에 맞게 잘라보고, 그에 맞는 모든 랜선의 수를 얻는다.
	for(i = 0; i < n; i++)
		cnt += a[i]/x;

	// 랜선의 숫자가 문제에서 원하는 k개와 일치하는지 알아본다.
	return cnt >= k;
}

int main(void)
{
	// 가장 긴 랜선의 길이를 찾아서 집어넣어준다.
	long long max = 0, res = 0;
	long long l, r, mid;
	int i;
	scanf("%d %d", &n, &k);
	// 가장 긴 랜선의 길이를 찾아서 집어넣는 로직
	for(i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		if(max < a[i]) max = a[i];
	}

	// 이분 탐색을 통해서 정답을 찾는 로직
	// 만약 어떤 기준을 잡고 그 기준 오른쪽으로는 예, 왼쪽으로는 아니오 등으로 답이 나오는 것이 아니라,
	// 예, 아니오가 3개 이상의 구간에서 번갈아 나온다면 이분탐색으로는 답을 찾을 수 없다.
	l = 1; r = max;
	while(l <= r){
		mid = (l+r) >> 1;
		if(is_size_valid(mid)){
			// 적합한 사이즈가 나왔다면, 답에 mid를 넣는다.(애초에 mid가 답으로 적합한지 보는 로직이다.) 
			// 즉, 여기서는 인덱스가 바로 적합한 랜선의 길이가 될 수 있다.
			if(res < mid) res = mid;
			l = mid + 1;
		} else{
			r = mid - 1;
		}
	}
	printf("%lld\n", res);

	return 0;
}
