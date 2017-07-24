#include <cstdio>
#include <cstring> // memset은 cstring안에 있다.

typedef long long ll;

ll n = 1000000;
bool isPrime[1000001];

void eratosthenes(){
	ll i, j;
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	
	for(i = 2; i*i <= n; i++){
		if(isPrime[i])
			for(j = i*i; j <= n; j += i)
				isPrime[j] = false;
	}
}

int main()
{
	int m, n;
	int i;
	scanf("%d %d", &m, &n);

	eratosthenes();
	for(i = m; i <= n; i++){
		if(isPrime[i])
			printf("%d\n", i);
	}

	return 0;
}
