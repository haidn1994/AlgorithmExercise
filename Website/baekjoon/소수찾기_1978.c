#include <stdio.h>
#include <math.h>


// 이 코드는 입출력 부분에서 뭔가 잘못되었다. 다시 풀어보자.
int main(void)
{
	int nat_num, nat; 
	int	result = 0, i = 0;
	int j;

	scanf("%d", &nat_num);

next:
	for(; i < nat_num; i++){
		// 입력 받는 부분
		scanf("%d ", &nat);

		if(nat%2 != 0){
			for(j = 3; j < pow(nat, 0.5); j += 2) {
				if(nat%j == 0)
					goto not_prime;
			}
		}
		result++;
		goto next;
	not_prime:
		goto next;
	}

	printf("%d", result);

	return 0;
}
