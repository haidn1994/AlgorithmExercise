/*
	결국 1시간 내로 못 풀어서 일단 풀이를 보고 풀도록 한다.

	짝수는 검사할 필요가 없다...는 확실히 맞는것 같은데 왜 여기서는 안되는지 잘 모르겠다.
 */

#include <stdio.h>

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
		// 1은 소수가 아닌 유일한 자연수
		// 2는 소수인 유일한 짝수
		int divisor = 2;

		if(naturals[i] == 1){
			not_prime_num++;
			continue;
		}

		while(divisor * divisor <= naturals[i]){
			if(naturals[i] % divisor == 0){
				not_prime_num++;
				break;
			}
			divisor++;
		}
	}

	printf("%d\n", nat_num - not_prime_num);

	return 0;
}
