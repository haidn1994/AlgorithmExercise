#include <stdio.h>

// 꼭 배열을 만들놓고 연산을 시작하자.


// 이건 틀렸다! 내일 다시 해보자
int main(void){
	int numbers[1000];

	int nat_num;
	int result = 0;
	int i, j;

	scanf("%d", &nat_num);

	for(i = 0; i < nat_num; i++)
		scanf("%d", &numbers[i]);

	i = 0;

next:
	for(; i < nat_num; i++){
		if(numbers[i]%2 != 0){
			for(j = 3; j <= numbers[i]; j += 2){
				if(numbers[i]%j == 0){
					i++;
					goto next;
				}
			}
			result++;
		}
	}

	printf("%d", result);

	return 0;
}
