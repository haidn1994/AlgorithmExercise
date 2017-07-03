#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

//  일단 다음과 같은 절차를 밟는다.

/*
	first와 second를 동시에 iterating하는 함수가 필요하다.
	이 함수는 특정 문자열이 최초로 등장 할때마다 맵과 같은 컨테이너에 스트링을 키(key)로 등록한다.  
	그리고 최초로 등록되었을 때의 값(value)는 1로 설정한다.  


	만약 서로 같은 문자열이 2번째 이상으로 등장한다면 해당 문자열에 매핑되어 있는 키의 값을 하나 증가시킨다.
	일련의 절차가 끝났다면, 맵에 있는 키를 차례대로 하나씩 탐색하여 가장 큰 값을 얻는다.
	그 값을 반환하면 끝난다!

	
	그런데 사실 생각해보면 그냥 단어의 빈도수를 세는 문제랑 다를 것이 없다.
	하지만 전체탐색이라는 점을 잊지는 말자!
*/
class InterestingParty{
public:
	int bestInvitaion(vector<string> first, vector<string> second)
	{
		int result;
		int i, size;
		map<string, int> temps;

		// 연산자 오버로딩 때문에 상당히 헷갈린다! 주의하자!
		size = first.size();
		for(i = 0; i < size; i++)
			++temps[i];

		size = second.size();
		for(i = 0; i < size; i++)
			++temps[i];

		// 가장 큰 숫자 고르기
		// 그런데 생각해보면 이런 함수는 이미 map STL에서 제공하고 있을 것 같다.
		// 내부 문서를 찾아보도록 하자!
		result = temps[0];
		size = temps.size();
		for(i = 0; i < size; i++)
			if(result < temps[i]) result = temps[i];
			
		return result;
	}
};

/*
	실제로 이렇게 작성하고 해답을 찾아보니 map을 사용하는게 보다 좋은 방법이고 전반적인 기조는 맞지만,
	map의 사용법이 틀린것 같다. 그리고 반복문을 사용해보는 방법을 구현하는 것도 좋다고 생각한다.
	일단 구현해보고, 더 나은 방법을 찾아보자!
 */
