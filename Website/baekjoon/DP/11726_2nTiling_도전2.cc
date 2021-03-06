/*
	코드를 작성하기에 앞서서 먼저 짚고 넘어가야 할 코드가 있다.
	이 문제와 1,2,3더하기 문제의 경우 d[0] = 1이라 두고 문제를 풀어나가는 방법이 있는데,

	codeplus의 질문 답변 게시판에 따르면 (백준님 답변)
	이렇게 주는 경우는 경우의 수 문제의 경우에 주로 사용한다.
	
	1,2,3더하기 같은 경우에는 d[0] = 1의 의미가 보통 0을 만드는 방법이 1가지라는 뜻이다.
	(또는 방법이 없으므로 아무것도 하지 않는 것을 한가지 방법이라고 생각하는 것도 된다!)
	d[3]을 채우는 경우의 경우는 수를 

	* 0개를 사용해서 만든 2를 만드는 방법 + 그 뒤에 1을 사용한 방법 = d[3-1]
	* 0개를 사용해서 만든 1를 만드는 방법 + 그 뒤에 2을 사용한 방법 = d[3-2]
	* 0개를 사용해서 만든 0를 만드는 방법 + 그 뒤에 3을 사용한 방법 = d[3-3]

	d[0] = 0으로 하고 문제를 해결하려면, 수를 1개 사용한 방법, 
	(방법이 없으므로 0이라고 생각하고 싶다면)
	즉 d[1] = d[2] = d[3] = 1을 미리 초기화한 다음에 사용해야 한다.
 */

#include <iostream>
using namespace std;

int d[1001];

int mod = 10007;

int main(void){
	int n, i; ios_base::sync_with_stdio(false);
	cin >> n;

	d[1] = 1;
	d[2] = 2;
	for(i = 3; i <= n; i++){
		d[i] = d[i-2] + d[i-1];
		d[i] %= mod;
	}

	cout << '\n' << d[n] << '\n';
	return 0;
}
