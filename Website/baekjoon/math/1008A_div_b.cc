#include <iostream>
using namespace std;

int main()
{
	int a, b;
	double res;

	// 소수의 출력 포맷을 설정하는 코드다. 주의해서 보도록 한다.
	cout.setf(ios::showpoint);
	cout.precision(9);
	cin >> a >> b;

	res = (double)a/b;
	cout << res << '\n';
	return 0;
}
