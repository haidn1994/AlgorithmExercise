#include <iostream>
using namespace std;

int d[101];

int step_num(int n)
{
	if(n == 1)
		return 9;
	if(d[n] > 0)
		return d[n];


	return d[n];
}


int main(void)
{
	int n;
	ios_base::sync_with_stdio(false);
	cin >> input;
	cout << step_num(n) << '\n';

	return 0;
}
