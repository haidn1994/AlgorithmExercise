#include <iostream>
using namespace std;

int main(void)
{
	int MAC[5];
	int temp = 0, i;
	for(i = 0; i < 5; i++){
		cin >> MAC[i];
		temp += MAC[i]*MAC[i];
	}

	temp %= 10;
	cout << temp << '\n';
	return 0;
}
