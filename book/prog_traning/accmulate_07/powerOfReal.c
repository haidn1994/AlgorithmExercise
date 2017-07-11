/*
	실수 x와 0이상의 정수(int 형)n을 입력 받아 X^n을 구하는 함수 Power(double, int)를 작성하라. 
	x^n은 n개의 x를 곱한 것이므로, 루프를 n번 돌면서 각각 곱하는 것으로 코드를 작성할 수 있다.
 */

double power(double x, int n)
{
	double s = 1.0;
	int i;

	for(i = 0; i < n; i++)
		s *= x;
	return s;
}

/*
	위의 코드는 곱셈을 n번 한다. 하지만 곱셈 횟수가 너무 많아 보인다.  
	곱셈 횟수를 더 줄일 수는 없을까?

	이미 계산된 높은 차수의 계산 결과를 이용하면 더 적은 횟수로 거듭제곱을 계산할 수 있다.  
	5^20을 구하는 경우를 예로 들어보자. 다음과 같이 다섯 번의 곱셈으로 5^20의 값을 구할 수 있다.  

	5^20 = 5^10 * 5^10
	5^10 = 5^5 * 5^5
	5^5 = 5^2 * 5^2 * 5
	5^2 = 5 * 5

	이 아이디어를 사용하면 약 log2(n)정도의 시간 복잡도 함수를 가지는 "향상된 거듭제곱 알고리즘"을 정의할 수 있다.
	해당 아이디어를 재귀적으로 나타내면 다음과 같다.

	x^0 = 1, x^1 = x이다.
	n이 짝수면, x^n = (x^n/2)^2
	n이 홀수면, x^n = x^(n-1)*x

	이를 코드로 옮기면...
 */

double power2(double x, int n)
{
	double s;

	if(n == 0)
		return 1.0;
	if(n == 1)
		return x;
	if(n % 2 == 0){
		s = power(x, n/2);
		return s * s;
	}

	return power(x, n - 1) * x;
}

/*
	속도가 극적으로 빨라졌지만, 아직 느린감이 있다.  
	재귀호출을 없애고 반복문을 사용하는 방식을 사용해보자.  
 */

double power3(double x, int n)
{
	double s = 1.0;

	while(n > 0){
		if(n % 2 == 1){
			s *= x;
			if(n == 1)
				return s;
		}
		x *= x;
		n /= 2;
	}
	return s;
}


