#include <iostream>
using namespace std;

// d에는 n을 1,2,3의 합으로 나타내는 방법의 수를 메모한다.
int d[11];

int plus123(int n)
{
	if(n <= 1)
		return 1;
	if(d[n] > 0)
		return d[n];

	d[n] = plus123(n-1) + plus123(n-2) + plus123(n-3);
	return d[n];
}

int main(void)
{
	int input, tc; 
	d[2] = 2;
	d[3] = 4;
	d[4] = 7;
	ios_base::sync_with_stdio(false);
	cin >> tc;
	
	while(tc--){
		cin >> input;
		cout << plus123(input) << '\n';
	}
	return 0;
}
