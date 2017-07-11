#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s;
	//int range, i;
	getline(cin, s);

	//range = s.size();
	/*
	for(i = 0; i < range; i++){
		if('a' <= s[i] && s[i] <= 'z'){
			s[i] += 13;
			if(s[i] > 'z') s[i] = (s[i]%'z') + 'a'-1;
		}
		if('A' <= s[i] && s[i] <= 'Z'){
			s[i] += 13;
			if(s[i] > 'Z') s[i] = (s[i]%'Z') + 'A'-1;
		}
	}
	*/

	// 내가 한 방법으로 하면 하나씩 깨진다. 
	// 왜 그런 일이 일어나는지는 알 수 없다.
	for (int i=0; i<s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'm') {
			s[i] = s[i] + 13;
		} else if (s[i] >= 'n' && s[i] <= 'z') {
			s[i] = s[i] - 13;
		} else if(s[i] >= 'A' && s[i] <= 'M') {
			s[i] = s[i] + 13;
		} else if(s[i] >= 'N' && s[i] <= 'Z') {
			s[i] = s[i] - 13;
		}
	}

	cout << s << '\n';
	return 0;
}
