#include <iostream>
#include <string>
using namespace std;

char low_alphabets[26];

int main(void)
{
	string s; ios_base::sync_with_stdio(false);
	int i, range;
	cin >> s;

	range = s.size();
	for(i = 0; i < range; i++)
		low_alphabets[s[i]-'a']++;
	// 이거 내부적으로 연산자 오버로딩이 되어 있을텐데 어떤 타입을 반환하는 거지?
	for(i = 0; i < 26; i++)
		cout << (int)low_alphabets[i] << ' ';
	return 0;
}

