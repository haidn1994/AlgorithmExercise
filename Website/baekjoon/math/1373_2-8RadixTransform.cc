#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int i, range; 
	cin >> s; range = s.size();

	// 역시 내 생각대로 3개씩 묶어서 처리하되, 약간의 예외처리를 하고 시작한다.
	// 1개나 2개 남았을 경우 처리해서 먼저 출력한다.
	if(range%3 == 1)
		cout << s[0];
	else if(range%3 == 2)
		cout << (s[0] - '0')*2 + (s[1] -'0');
	// 나머지를 3개씩 묶어서 처리한다.
	for(i = range%3; i < range; i += 3)
		cout << (s[i] - '0')*4 + (s[i+1] - '0')*2 + (s[i+2] - '0');

	cout << '\n';
	return 0;
}
