#include <iostream>
using namespace std;

// d에 들어갈 값은 연산횟수의 "최소값"이다.
int d[1000001];

// top-down방식
int getMinCount(int n)
{
	// 입력이 1로 들어왔을 때가 바로 기저 사례
	if(n == 1) return 0;
	// 부분 문제를 풀기 전에 앞서 풀어놓은 답이 있는지 확인한다.
	// 다이나믹 프로그래밍의 기본이다.
	if(d[n] > 0) return d[n];
	// 1을 빼는 연산의 경우
	d[n] = getMinCount(n-1) + 1;
	// 2로 나누어 떨어진다.
	if(n % 2 == 0){
		int temp = getMinCount(n/2) + 1;
		if(d[n] > temp) d[n] = temp;
	}
	// 3으로 나누어 떨어진다.
	if(n % 3 == 0){
		int temp = getMinCount(n/3) + 1;
		if(d[n] > temp) d[n] = temp;
	}
	// 내부적으로는 꽤 많은 연산을 통해서 정답을 구해나갈 것이다.
	return d[n];
}

int main(void)
{
	int input; ios_base::sync_with_stdio(false);
	cin >> input;
	cout << getMinCount(input) << '\n';

	return 0;
}
