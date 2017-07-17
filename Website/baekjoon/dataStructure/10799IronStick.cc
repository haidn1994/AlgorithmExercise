#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	string s;
	stack<int> stk;
	int i, range, ans = 0;
	cin >> s;

	range = s.size();
	for(i = 0; i < range; i++){
		if(s[i] == '('){
			stk.push(i);
		} else {
			if(stk.top()+1 == i){
				stk.pop();
				ans += stk.size();
			} else {
				// 이 부분이 관건이다!
				// 하나 추가될때마다 쇠막대기가 하나씩 늘어나고
				// 레이저가 있으면 쇠막대기가 X2씩 된다고 생각하면 문제의 풀이를 납득할 수 있다.
				stk.pop();
				ans++;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
