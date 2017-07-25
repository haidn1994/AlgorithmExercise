#include <cstdio>

int a[10001];
//int cnt_sum[10001];

int main()
{
	int temp;
	int n, i, j; scanf("%d", &n);

	for(i = 1; i <= n; i++){
		scanf("%d", &temp);
		// 숫자가 등장하는 횟수를 센다.
		a[temp]++;
	}

	for(i = 1; i <= 10000; i++){
		for(j = 0; j < a[i]; j++)
			printf("%d\n", i);
	}
	/*
	// 누적합을 구성한다.
	cnt_sum[0] = a[0];
	for(i = 1; i <= 10000; i++)
	cnt_sum[i] = cnt_sum[i-1] + count[i];
	// 뒤에서부터 수열 A를 순회한다.
	for(i = n; i >= 1; i--)
	 */    
}
