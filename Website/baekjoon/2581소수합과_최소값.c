#include <stdio.h>
#include <math.h>

// PrimePi로 알아본 결과 n이 10000일때 최대 1229가 나왔다.
int prime_table[1230];

enum{
	false = 0,
	true  = 1 
};

int is_prime(int n)
{
	int div;
	// 1은 자연수이면서 유일하게 소수가 아니다.
	// 2는 짝수인데 유일한 소수이다.
	if(n <= 1) return false;
	if(n == 2) return true;

	// 2를 제외한 모든 짝수는 소수가 아니다.
	// 내가 이부분을 빼먹어서 틀렸다. 조심하자.
	if(n % 2 == 0) return false;

	// 2를 제외했으니 3이상의 모든 홀수로 나누어 보자
	// 사실 math.h를 사용하지 않아도 된다.
	// sqrt(n) = i는 n = i^2과 같다는 사실을 잘 알고 사용하면 된다.
	int sqrtn = (int)sqrt(n);
	for(div = 3; div <= sqrtn; div += 2)
		if(n % div == 0)
			return false;

	return true;
}

int arith_sum(int arr[], int start, int last)
{
	int	result = 0;
	int i;
	
	for(i = start; i < last; i++){
		result += arr[i];
	}
		return result;
}

int arr_min(int arr[], int start, int last)
{
	int i = start;
	int result = arr[start];

	for(; i < last; i++){
		if(result > arr[i])
			result = arr[i];
	}

	return result;
}



int main(void)
{
	int M;
	int N;
	int prime_num = 0;
	int i;

	scanf("%d", &M);
	scanf("%d", &N);

	for(i = M; i <= N; i++){
		if(is_prime(i)){
			prime_table[prime_num] = i;
			prime_num++;
		} else
			continue;
	}

	if(prime_table[0] != 0){
		printf("%d\n", arith_sum(prime_table, 0, prime_num));
		printf("%d", arr_min(prime_table, 0, prime_num));
	} else {
		printf("-1\n");
	}

	return 0;
}
