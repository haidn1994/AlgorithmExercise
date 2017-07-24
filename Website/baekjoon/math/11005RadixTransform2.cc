#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char chars[26];

int main(void)
{
	int n, b, temp;
	// 스트링도 int형과 마찬가지로 뭔가를 집어넣고 싶다면 반드시 초기화를 해주어야 한다!
	string res = "";
	int i; cin >> n >> b;
	for(i = 0; i < 26; i++)
		chars[i] = i + 'A';

	// 10진법 수 N을 B진법으로 바꾸려면 n이 0이 될때 까지 나머지를 계속해서 구하면 된다.
	while(n != 0){
		temp = n % b;
		n /= b;
		// 게다가 이걸 거꾸로 출력해야 비로소 우리가 원하는 숫자가 나온다.
		// string을 이용하는 것이 제일 편하다.
		// 그리고 여기에 정수를 넣었다가 문자를 넣었다가 번갈아 넣지 말고,
		// type을 통일해서 집어넣어야 한다는 사실을 알아야 한다.
		if(temp > 9)
			res += chars[temp-10];
		else 
			res += (char)temp + '0';
		// 이렇게 코드를 쑤셔 넣으면 보기에는 아주 좋지만 형변환에 있어서 약간 문제가 생기기 때문에
		// 고려해서 삼항 연산자를 사용하도록 하자.
		// cout << ((temp > 9) ? (char)chars[temp-10] : temp);
	}

	// 마지막 마무리로 뒤집어주면 우리가 원하는 진법 변환의 최종결과를 얻을 수 있다.
	reverse(res.begin(), res.end());
	cout << res << '\n';
	return 0;
}
