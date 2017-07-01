#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	int tc;
	int i;
	cin >> tc;

	stack<char> s;

	while(tc--){
		char buf[50];
		int close_paren_num = 0;
		i = 0;

		cin >> buf;
		while(buf[i]){
			(buf[i] == '(') ? (close_paren_num--) : (close_paren_num++);
			i++;
		}

		if(close_paren_num < 0)
			cout >> "YES";
		else
			cout >> "NO";
	}

	return 0;
}
