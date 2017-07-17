#include <iostream>
#include <string>
using namespace std;

// 18라인에서 갑자기 cnt가 0보다 작으면 나머지 문자열은 다 보지도 않고 NO를 반환한다.
// 왜 그럴까? -> 그 이유는 괄호의 짝이 맞으려면 반드시 닫는 괄호 *앞*에 여는 괄호가 있어야 한다.
// 스택을 대표하는 값인 cnt가 음수가 되었다는 것은 앞에 여는 괄호가 없는 닫는 괄호가 있다는 뜻이다.
// 그런 괄호가 단 한개라도 있으면 올바르지 않은 괄호가 생성되고, 앞으로 어떤 괄호들이 나오건 간에,
// 이를 만회할 수 없기 때문에 바로 "NO"를 출력해도 상관 없는 것이다.

string vaild(string input)
{
	int range, cnt = 0;
	int i;

	range = input.size();
	for(i = 0; i < range; i++){
		(input[i] == '(') ? (cnt++) : (cnt--);
		// 사실 여기서 의문증이 생길수 있다. 왜 그런지 위에서 설명한다.
		if(cnt < 0) return "NO";
	}

	return (cnt == 0) ? "YES" : "NO";
}

int main(void)
{
	string input;
	int tc; cin >> tc;

	while(tc--){
		cin >> input;
		cout << vaild(input) << '\n';
	}

	return 0;
}
