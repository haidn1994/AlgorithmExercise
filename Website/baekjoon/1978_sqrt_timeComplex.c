#include <stdio.h>
#include <math.h>

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
	int sqrtn = (int)sqrt(n);
	for(div = 3; div <= sqrtn; div += 2)
		if(n % div == 0)
			return false;

	return true;
}

int naturals[1000];

int main(void)
{
	int nat_num;
	int not_prime_num = 0;
	int i;

	scanf("%d", &nat_num);
	for(i = 0; i < nat_num; i++)
		scanf("%d", &naturals[i]);

	for(i = 0; i < nat_num; i++){
		if(is_prime(naturals[i]))
			continue;
		else
			not_prime_num++;
	}

	printf("%d\n", nat_num - not_prime_num);
	return 0;
}
