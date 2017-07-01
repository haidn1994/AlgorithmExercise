/*
   에라토스테네스의 체: 좀 더 정형화된 방식은 없는지 알아봐야 하겠다.
 */

enum{
	false = 0,
	true  = 1
};

int n;
char is_prime[MAX_N+1];

// 가장 단순한 형태의 에라토스테네스의 체의 구현
// 종료한 뒤 is_prime[i] = i가 소수인가?

void eratosthenes()
{
	int i, j;
	memset(is_prime, 1, sizeof(is_prime));

	// 1은 자연수 이면서 소수가 아닌 유일한 수, 예외 처리를 해두자.
	is_prime[0] = is_prime[1] = false;
	int sqrtn = (int)sqrt(n);
	for(i = 2; i <= sqrtm; ++i)
		// 이 수가 아직 지워지지 않았다면,
		if(is_prime[i])
			// i의 배수 j들에 대해 is_prime[i] = false로 둔다.
			// i*i미만의 배수는 이미 지워졌으므로 신경쓰지 않는다.
			for(j = i*i; j <= n; j += i)
				is_primr[j] = false;
}
