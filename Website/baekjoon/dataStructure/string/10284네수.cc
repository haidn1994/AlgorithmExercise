#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string inputs[4];
	int i;
	long long t1, t2, t3;
	for(i = 0; i < 4; i ++)
		cin >> inputs[i];

	t1 = stoll(inputs[0] + inputs[1]);
	t2 = stoll(inputs[2] + inputs[3]);
	t3 = t1 + t2;
	cout << t3 << '\n';
	return 0;		
}
