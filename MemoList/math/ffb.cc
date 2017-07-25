#include <iostream>
using namespace std;

typedef long long ll;

ll factorial(int n)
{
	if(n <= 1) return 1;
	return factorial(n-1) * n;
}

ll fibo(int n)
{
	if(n <= 0) return 0;
	if(n == 1) return 1;
	return fibo(n-1) + fibo(n-2);
}

ll binom(int n, int r)
{
	if(n == r || r == 0) return 1;
	return binom(n-1, r-1) + binom(n-1, r);
}

int main(void)
{
	int n = 5, r = 3;
	cout << "factorial(5): " << factorial(n) << '\n';
	cout << "fibonacci(5): " << fibo(n) << '\n';
	cout << "binomial(5, 3): " << binom(n, r) << '\n';
	return 0;
}
