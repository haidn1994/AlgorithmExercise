#include <cstdio>
#include <cstring>

typedef long long ll;

ll max = 246912;
bool isPrime[246913];

void eratosthenes(){
	ll i, j;
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	
	for(i = 2; i*i <= max; i++){
		if(isPrime[i])
			for(j = i*i; j <= max; j += i)
				isPrime[j] = false;
	}
}

int main()
{
	int n, cnt = 0;
	int i;
	scanf("%d", &n);

	eratosthenes();
	while(n != 0){
		for(i = n+1; i <= 2*n; i++){
			if(isPrime[i])
				cnt++;
		}
		printf("%d\n", cnt);
		cnt = 0; scanf("%d", &n);
	}

	return 0;
}
