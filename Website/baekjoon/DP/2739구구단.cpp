#include <iostream>
using namespace std;

int main(void)
{
	int n;
	int i;
	cin >> n;

	for(i = 1; i <= 9; i++)
		cout << n << " * " << i << " = " << (n*i) << '\n';
	return 0;
}
