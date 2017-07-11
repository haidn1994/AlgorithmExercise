#include <iostream>
#include <string>
using namespace std;

char low_alphabets[26];

int main(void)
{
	string s; int i, range;
	ios_base::sync_with_stdio(false);
	std::fill_n(low_alphabets, 26, -1);
	cin >> s;

	range = s.size();
	for(i = 0; i < range; i++){
		if(low_alphabets[s[i]-'a'] == -1)
			low_alphabets[s[i]-'a'] = i;
	}
	// 이거 내부적으로 연산자 오버로딩이 되어 있을텐데 어떤 타입을 반환하는 거지?
	for(i = 0; i < 26; i++)
		cout << (int)low_alphabets[i] << ' ';
	return 0;
}

