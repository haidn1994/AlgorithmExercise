/*
   종만북에서 맨 처음 나오는 문제로, 나의 풀이는 무식하게 풀기(브루트 포스)다
   사실 시간을 더 줄일 수 있는 방법이 있을거라는 생각이 들기는 하지만 잘 모르겠다.

   5/28 아직 못 푼 문제이다. 이 코드는 아직 컴파일도 하지 않았다.
 */

#include <stdio.h>

int[1000] borrowing_price;
double[100] results;

int main(void)
{
	int tcase_num, day_num, pteam_num;
	int i, j, ptemp;
	double min_price;

	scanf("%d", &tcase_num);

	// 한줄로 길게 있는 입력을 받아서 처리하는 방법을 알아야 한다.
	// http://m.todayhumor.co.kr/view.php?table=total&no=7901303 여기에 scanf의 동작에 대해 자세하게 나와있다. 참고하라.
	// 그리고 i[], i, i[j], &i[j]는 모두 다른 의미를 가지고 있는 점을 꼭 알도록 한다.

	// 여기에 더해 이 코드를 C++로 바꿔주는 연습을 해보도록 하자.
	for(i = 0; i < tcase_num; i++){
		scanf("%d %d", &day_num, &pteam_num);
		for(j =0; j < day_num; j++)
			scanf("%d", &borrowing_price[j]);

		results[i] = find_min_price(day_num, pteam_num, borrowing_price[]);
	}

	for(i = 0; i < tcase_num; i++)
		printf("%f\n", results[i]);

	return 0;
}

double find_min_price(int day_num, int pteam_num, int[] borrowing_price)
{
	float result, temp;
	int i, j;
	
	// 이 부분은 파이프라이닝을 설명할 때 쓰는 그림을 생각하면 이해하기 쉬울 것이다.
	for(i = pteam_num; i <= day_num; i++){
		for(j = 0; j < day_num - i + 1; j++){
			temp = arith_mean(i, borrwing_price[j]);
			
			if(temp < result)
				result = temp;
		}
	}

	return result;
}

double arith_mean(int total_n, int[] terms)
{
	double result;
	int i, temp;

	for(i = 0; i < total_n; i++)
		temp += terms[i];
	
	return temp / total_n;
}


