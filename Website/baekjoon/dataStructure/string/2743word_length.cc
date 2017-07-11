#include <iostream>
using namespace std;

// 여기에 NULL문자가 들어갈 공간이 필요하기 때문에 length + 1byte만큼의 메모리가 필요하다.
char s[101];

int main(void)
{
	int i, length = 0;
	cin >> s;

	for(i = 0; s[i]; i++)
		length++;
	cout << length << '\n';
	return 0;
}
