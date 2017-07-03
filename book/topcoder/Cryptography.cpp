// 이 문제는 2가지 방법(효율적임)으로 풀 수 있는 문제이다.
// 첫번째 방법으로는 앞서 한 방법과 마찬가지로 전체 탐색을 이용하는 방법이 있고
// 두번째 방법으로는 수학적인 지식을 활용하여 빠르게 정답을 얻어내는 방법이 있다.

/*
	여기서 생각나는게 한가지 있는데 전체 탐색은 map이 상당히 자주 쓰인다는 사실을 알 수 있다.  
	어떤 입력이 순차적이고, 순서에 따라 다른 값을 가지거나(배열로 해결할 수도 있음)
	특정한 문자열이 나오는 횟수를 세고 싶다면 문자열을 키로 하고, 횟수를 값으로 엮으면 된다.
	다른 예시가 또 나온다면 더 작성하겠다.  
 */
#include <iostream>
#include <vector>
#include <map>

class Cryptography{
public:
	long long encrypt(vector<int> numbers)
	{
		// 앞쪽은 +1을 할 숫자의 번호, 뒤는 그렇게 해서 얻어진 모든 리스트 내의 숫자의 곱
		// 그런데 사실 이건 map말고 vector나 array를 사용해도 무방하지 않을까?
		map<int, int> temps;
		long long result;
		int i, size;

		size = first.size();
		for(i = 0; i < size; i++){
			numbers[i] += 1; // 하나 늘리고(출력을 얻어내기 위함)
			temps[i] = productTerms(numbers);
			numbers[i] -= 1; // 하나 줄이고(원상복구 하기 위함)
		}

		// 여기서 map의 값 중 제일 큰 값을 얻어야 한다. 
		// 표준화된 코드가 있으리라 생각한다. 그 절차를 통해서 result에 적합한 값을 넣어서 리턴한다.  

		return result;
	}
	int productTerms(vector<int> terms)
	{
		// Pi Notation을 함수로 만든 것
		int i, result = 1;

		for(i : terms)
			result *= terms[i];

		return result;
	}
};
