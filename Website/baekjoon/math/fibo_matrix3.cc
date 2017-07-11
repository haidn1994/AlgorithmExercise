#include <iostream>
using namespace std;

struct matrix22{
	int e[2][2];
};

struct matrix21{
	int e[1][2];
};

long long mod = 1000000;

struct matrix22 matrix_prod(struct matrix21

// 행렬곱셈 함수는 따로 빼놓도록 하자. 섞어서 구현하면 버그에 시달린다.
long long fibo(long long n)
{
	struct matrix21 res;
	struct matrix22 multi;
	multi.e[0][0] = multi.e[0][1] = multi.e[1][0] = 1;
	multi.e[1][1] = 0;
	 
	res.e[0][0] %= mod;
	res.e[0][1] %= mod;

	return res;
}

// 미완성: 관련 라이브러리를 아직 작성하지 못했다.  
int main(void)
{
	struct matrix21 temp;
	long long n, fibo_n; cin >> n;

	temp = fibo(n);
	// 두개 다 할 필요는 없고, 2번째 원소만 취하면 된다.
	fibo_n = temp.e[0][0] + temp[0][1];
	cout << fibo_n << '\n';
	return 0;
}
