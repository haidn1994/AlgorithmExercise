/*
	3가지 경우를 고려해야 한다.

	1. 맨 앞에 공백문자가 왔을 경우
	2. 맨 뒤에 공백문자가 왔을 경우
	3. 공백문자가 연속해서 주어질 경우
 */
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s;
	int cnt = 1, i;
	getline(cin, s);

	if(s[0] == ' '){
		cnt = 0;
		goto out;
	}

	for(i = 0; i < s.size(); i++)
		if(s[i] == ' ') cnt++;
out:
	printf("%d\n", cnt);
	return 0;
}
