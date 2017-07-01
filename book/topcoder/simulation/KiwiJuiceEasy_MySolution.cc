#include <vector>

using namespace std;

/*
	프로그래밍 대회 문제 풀이 3원칙

	1. 문제를 풀어보기 전에 손으로 풀어보자.

	2. 코드를 작성하는 속도가 너무 느리다면 손으로 다시 풀어본다.

	3. 조건문은 실수할 여지가 많아지니까 되도록 조금만 작성하도록 한다.
 */

class KiwiJuiceEasy{
	public:
		vector<int> thePouring(vector<int> capacities,
							   vector<int> bottles,
							   vector<int> fromId, vector<int> toId);
}


vector<int> KiwiJuiceEasy::thePouring(vector<int> capacities,
							    	  vector<int> bottles,
							   		  vector<int> fromId, vector<int> toId);
{
	// fromId와 toId벡터의 각 인덱스에 접근한다.
	// 조건 -> while(bottles(fromId) != 0 && (capcities(fromId) + capacities(toId)) <= bottles(toId))
	// 위의 조건을 만족하지 못한다면 루프를 탈출한다.

	/*
	   위의 조건을 만족한다면 내부적으로 만들어 놓은 벡터의 값을 바꾸면서 계속 인덱싱을 진행한다.  
	   bottles(toId[i]) = bottles(fromId) + bottles(toId) 
	   bottles(fromId[i]) = 0;
	   루프를 탈출하지 않는다면 위 로직이 핵심로직이다.  

	   그리고 내부 벡터에 값을 입력으로 들어온 벡터에 반영한다.  
	   그리고 위의 로직을 계속 진행한다.  
	 */
	// -----------------------------------------
	// 이 위에서 말하는 모든 내용은 내가 이해를 잘못하고 말한 것이다. 실제로 문제에서 말하는 것은 이런 뜻 인것같다.
	// 입력 m은 cap, bot, fromId, toId모두의 size()를 말하는 것이다.(값은 모두 같음)
	// 각 벡터에 대해서, 다음의 절차를 수행한다.

	/*
	   fromId의 병안에 들어있는 키위 주스를 toId에다가 붓는다.

	   만약 fromId병안에 들어있는 키위주스의 양과 toId안에 들어 있는 키위주스의 양의 합이 toId의 용량보다 작거나 같다면,
	   toId안에 있는 키위 주스의 양은 원래 toId에 있던 양과 fromId에 있던 양을 합한것과 같게 된다.
	   그리고 fromId안의 키위주스의 양은 0이 된다.

	   하지만 두 키위주스의 합이 toId의 용량보다 크다면
	   toId안에 있는 키위 주스의 양은 toId의 용량과 같게 된다.
	   fromId안의 키위 주스의 양은 두 병안의 키위 주스의 용량을 합친 것에서 toId의 용량을 뺀것과 같게 된다.
	 */

	// 반복자 
	int m = 0;

	// 내부적으로 스택으로 들어온 벡터를 받아서 조작하고, 그 결과를 반환하는 형태로 가자!  
	// 단, 이 변수가 deep-copy로 대입이 될 수도 있고, shallow-copy형태로 대입이 될 수도 있다.
	// 어느 쪽이든 정답에 영향을 주거나 컴파일 에러가 생겨서는 안된다.
	vector<int> temps = bottles;

	// C++에서 스택 프레임으로 들어온 변수를 조작할 수 있었던가?
	// 된다면 따로 만들필요는 없어지지만 안정성을 위해서 일단 그 방법은 피하도록 한다.
	// 마지막으로, result에서 result를 반영하는 형태로 만들어야 한다.

	// 벡터의 마지막을 만나면 루프에서 탈출한다.
	// 향상된 for문을 사용하자
	for(m : temps){
		if((bottles[fromId[m]] + bottles[toId[m]]) =< capacities[toId[m]]){
			// 이런 코드 말고 result벡터에서 result벡터로 접근해서 계산한 값을 대입하는 코드가 필요하다.
			temps[toId[m]] = bottles[fromId[m]] + bottles[toId[m]];
			temps[fromId[m]] = 0;
		} else {
			// 여기도 마찬가지!
			temps[toId[m]] = capacities[toId[m]];
			temps[fromId[m]] = (bottles[fromId[m]] + bottles[toId[m]]) - capacities[toId[m]];
		}
	}

	return temps;
}

