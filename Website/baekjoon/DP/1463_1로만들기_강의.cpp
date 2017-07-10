#include <iostream>
using namespace std;

// 테이블의 크기는 입력과 비례한다.
// 즉, 입력의 크기가 10^6이므로 테이블의 크기로 10^6보다 더 커야 한다.
// 왜 그럴까? 그 이유는 에라토스테네스의 체와 마찬가지로 인덱스가 입력된 자연수 n을 뜻하기 때문이다.
// 이제 풀이를 설명하겠다.

/*
	이 문제를 작은 문제로 쪼개는 방법은 다음과 같다.  
	먼저, 문제를 푸는것과 문제를 더 작은 문제로 쪼개는 행위는 같다(?).
	그리고 그 방법은 3가지다.

	1. 3으로 나누어 떨어진다면 3으로 나누고 몫을 취함
	2. 2로 나누어 떨어진다면 2로 나누고 몫을 취함
	3. 1을 뺀다.

	보통 3으로 나누는 행위가 자연수n의 크기를 빠르게 줄일수 있기 때문에 3이나 2로 나누어 떨어뜨릴수 있는지 먼저 보고,
	나누어 떨어지지 않는다면 1을 빼는 방법을 선택하게 된다.
	내가 해봤는데 안된다.

	그렇다면 다른 방법을 모색해야 하는데, 여기서 다이나믹 프로그래밍을 적용해 볼 수 있다.  
	먼저 테이블에 어떤 값을 넣어야 할지 잘 생각해야 한다. 어떤 값을 넣어야 할까?
	그건 문제를 잘 읽고 이해한다면 정할 수 있다.
	함수의 인자 n(이는 d의 인덱스이기도 하다.)에 대하여, "1로 만들기" 연산횟수의 최소값을 저장해야 한다.
	그럼 연산은 어떤게 있을까? 위에서도 언급했지만 3가지 종류가 있다. 
	이제 입력 N에 대해서 이 3가지 연산을 가지고 얻을 수 있는 연산회수의 최소값을 D[N]이라고 하자.
	그리고 3가지 연산을 적절하게 계속 반복하면 N에서 1으로 만드는 최소한의 연산회수 D[N]을 얻는다.

	하지만 이정도로는 부족하다. 우리가 원하는 것은 구체적인 D[N]의 값이 아니었던가?
	연산의 종류는 3가지이고, 하나씩 부분 문제를 구해보면 D[N]에 대한 부분문제는 다음 3가지로 나눌 수 있다.

	1. D[n] = D[n/3]+ 1
	2. D[n] = D[n/2]+ 1
	3. D[n] = D[n-1]+ 1

	이 때, 연산 횟수의 "최소값"을 지정하라고 했으니 3개중 "가장 작은" 값을 구하면 되겠다.
	여기서 "이거 시간 복잡도가 너무 큰 거 아닐까?" 라는 생각을 할 수도 있는데, 
	사실 내부적으로 루프가 없고, 내부에서 일어나는 핵심적인 연산도 단 단계마다 3개씩이기 때문에
	O(n*3) = O(n)이 된다. 따라서 10^6정도의 연산은 가뿐하게 수행한다.
 */
int d[1000001];
/*
int go_bottom_up(int n)
{
	if(n == 1) return 0;		// 입력이 1로 들어왔을 때가 바로 기저 사례이다.
	if(d[n] > 0) return d[n];	// 부분 문제를 풀기 전에 앞서 풀어놓은 답이 있는지 확인한다.
	d[n] = go(n-1) + 1;			// 1을 빼는 연산을 했을 경우
	// 2로 나누어 떨어짐
	if(n % 2 == 0){
		int temp = go(n/2) + 1;
		if(d[n] > temp) d[n] = temp;
	}
	// 3으로 나누어 떨어짐
	if(n % 3 == 0){
		int temp = go(n/3) + 1;
		if(d[n] > temp) d[n] = temp;
	}
	// 전부 구해서 넘겨준다.
	return d[n];
}
*/
int go_top_down(int n)
{
	int i;
	// 인덱스는 숫자를 나타낸다는 점 명심할것!
	d[1] = 0;
	for(i = 2; i <= n; i++){
		d[i] = d[i-1] + 1;
		if(i%2 == 0 && d[i] > d[i/2] + 1){
			d[i] = d[i/2] + 1;
		}
		if(i%3 == 0 && d[i] > d[i/3] + 1){
			d[i] = d[i/3] + 1;
		}
	}

	return d[n];
}

int main(void)
{
	int input, result = 0;
	ios_base::sync_with_stdio(false);
	cin >> input;

	result = go_top_down(input);
	cout << result << '\n';
	
	return 0;
}
