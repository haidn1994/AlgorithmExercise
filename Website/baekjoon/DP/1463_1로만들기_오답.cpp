#include <iostream>
#include <vector>
using namespace std;

/*
	오답이다. 이유는 다음과 같다.
	1. 일단 DP를 사용하지 않았다.
	2. 채점에 통과하지 못했다.
 */

// 이게 크기가 얼마나 나올지 알수가 없다. 따라서 일단 벡터를 사용해 보자.
// 일단 dp가 아닌 방법으로 풀어보자.
// vector<int> dp;

int main(void)
{
	// cin과 cout의 속도를 scanf와 printf에 버금가게 만드는 옵션
	ios_base::sync_with_stdio(false);

	int input, result = 0;
	// int i = 0;
	cin >> input;

	// 이건 dp가 아닌데...?
	while(input != 1){
		switch(input % 3){
		case 2:
			// 여기에 반례가 있다. 
			// 짝수인 경우와 홀수인 경우로 나눠야 한다.
			if(input % 2 == 0){
				input /= 2;
				result++;
			} else {
				input--;
				input /= 2;
				result += 2;
			}
			break;
		// 이 부분은 힌트에서 알려준대로 가보자.
		case 1:
			input--;
			input /= 3;
			result += 2;
			break;
		case 0:
			input /= 3;
			result++;
			break;
		}
	}

	cout << result;
	return 0;
}
