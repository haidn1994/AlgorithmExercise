/*
	C로는 자료구조를 직접 구현해야 하는데 사실 꽤나 번거로운 작업이다.
	일단 문제를 풀때는 C++을 사용하자 그리고 나만의 라이브러리를 하나씩 만들고 그 때 C로 풀어보자!
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	stack<int> s;

	while(n--){
		// 할 때마다 새로 입력 받아야 하니까...
		string cmd;
		cin >> cmd;

		if(cmd == "push"){
			int num;
			cin >> num;
			s.push(num);
		} else if(cmd == "top"){
			cout << (s.empty() ? -1 : s.top()) << '\n';
		} else if(cmd == "size" {
			cout << s.size() << '\n';
		} else if {
			cout << s.empty() << '\n';
		} else if {
			cout << (s.empty() ? -1 : s.top()) << '\n';
			if(!s.empty()){
				s.pop();
			}
		}
	}

	return 0;
}
