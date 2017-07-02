# kiwi juice easy - 풀이

## 나의 풀이

### 처음 생각

fromId와 toId벡터의 각 인덱스에 접근한다.
조건 -> while(bottles(fromId) != 0 && (capcities(fromId) + capacities(toId)) <= bottles(toId))
위의 조건을 만족하지 못한다면 루프를 탈출한다.


위의 조건을 만족한다면 내부적으로 만들어 놓은 벡터의 값을 바꾸면서 계속 인덱싱을 진행한다.  
bottles(toId[i]) = bottles(fromId) + bottles(toId) 
bottles(fromId[i]) = 0;
루프를 탈출하지 않는다면 위 로직이 핵심로직이다.  


그리고 내부 벡터에 값을 입력으로 들어온 벡터에 반영한다.  
그리고 위의 로직을 계속 진행한다.  

### 문제를 이해한 다음
이 위에서 말하는 모든 내용은 내가 이해를 잘못하고 말한 것이다. 실제로 문제에서 말하는 것은 이런 뜻 인것같다.
입력 m은 cap, bot, fromId, toId모두의 size()를 말하는 것이다.(값은 모두 같음)
각 벡터에 대해서, 다음의 절차를 수행한다.


fromId의 병안에 들어있는 키위 주스를 toId에다가 붓는다.


만약 fromId병안에 들어있는 키위주스의 양과 toId안에 들어 있는 키위주스의 양의 합이 toId의 용량보다 작거나 같다면,
toId안에 있는 키위 주스의 양은 원래 toId에 있던 양과 fromId에 있던 양을 합한것과 같게 된다.
그리고 fromId안의 키위주스의 양은 0이 된다.


하지만 두 키위주스의 합이 toId의 용량보다 크다면
toId안에 있는 키위 주스의 양은 toId의 용량과 같게 된다.
fromId안의 키위 주스의 양은 두 병안의 키위 주스의 용량을 합친 것에서 toId의 용량을 뺀것과 같게 된다.

> 결과적으로는 맞았다!

## 책의 풀이
	
* 참고:그런데 C++의 특징은 stack으로 들어온 변수도 입맛대로 상태를 바꾸어서 다시 반환값으로 사용할수 있는것 같다.

### 기본적인 풀이

```{.cpp}
class KiwiJuiceEasy{
public:
	vector<int> KiwiJuiceEasy::thePouring(vector<int> capacities,
										  vector<int> bottles,
										  vector<int> fromId, vector<int> toId)
	{
		int i, size;
		int f, t, space;

		// 기본적인 최적화!(이렇게 하지 않아도 O(1)을 보장하는 인터페이스가 있기는 하지만,
		// 습관을 들이자!
		size = fromId.size();
		for(i = 0; i < fromId.size(); i++){
			f = fromId[i];
			t = toId[i];
			space = capacities[t] - bottles[t];

			if(space >= bottles[f]){
				bottles[t] += bottles[f];
				bottles[f] = 0;
			} else {
				bottles[t] += space;
				bottles[f] -= space;
			}
		}

		return bottles;
	}
};
```

### 응용 기술1
이번 문제는 단순한 작업을 반복하는 시뮬레이션 문제이다. 하지만 이런 단순 반복 작업에서도 응용할 만한 기술이 있다.  
이번에 알아볼 응용기술은 조건문을 조금만 사용하는 방법이다. 
조건문이 필요이상으로 많으면 그만큼 코드의 양이 많아지고 입력에 따라 처리되지 않는 부분이 발생한다.  
이떄는 Example에서 오류가 검출되지 않으므로 버그를 찾기 힘들어진다. 조건문을 가능한 조금만 사용하고  
동일한 작업을 여러 번 하지 않는 것이 중요하다.  


이 문제에 대한 솔루션을 구현할 때 C++의 min이나 C# 또는 JAVA의 Math.min등의 최소값 함수를 사용하면  
간단하게 코드를 작성할 수 있다.(코드가 짧아지므로 실수도 줄일 수 있다.)  


*옮길 주스의 양*과 *기존 주스 병의 남은 용량*을 비교하면 둘 중 작은 것이 이동량이 된다.  
(수식으로 확인을 해보는 것이 좋을 것 같다.)  

*절차:
* 기존 주스에 이동량을 추가한다.
* 옮길 주스에 이동량을 제거한다.  

```{.cpp}
#include <vector>
#include <algorithm>
using namespace std;


class KiwiJuiceEasy{
public:
	vector<int> KiwiJuiceEasy::thePouring(vector<int> capacities,
										  vector<int> bottles,
										  vector<int> fromId, vector<int> toId)
	{
		int i, size;
		int f, t, vol;

		size = fromId.size();
		for(i = 0; i < fromId.size(); i++){
			f = fromId[i];
			t = toId[i];

			vol = min(bottles[f], capacities[t] - bottles[t]);

			bottles[f] -= vol;
			bottles[t] += vol;
		}

		return bottles;
	}
};
```
### 응용 기술2

이번에는 필자(topcoder 알고리즘 트레이닝의 저자)가 실전에서 사용한 코드를 소개한다.  
처음 이동량을 생각했을 떄 조건 분기에서 실수가 발생할 수도 있다.  
따라서 이동량을 무시하고, 옮길 주스와 기존 주스 병의 용량 중에 작은 값이 된다는 것을 이용하기로 한다.  
이를 사용하면 주스의 양을 다음과 같이 나타낼 수 있다.  

* 기존 주스: "옮길 주스와 기존 주스 병의 총합"과 "기존 주스 병의 용량"에서 작은 값
* 옮길 주스: "옮길 주스와 기존 주스 병의 총합"에서 위의 값을 제외한 값

이런 발상으로 실수를 줄여나가는 것이 중요하다. 코드를 보자.  
```{.cpp}
#include <algorithm>
#include <vector>

using namespace std;

class KiwiJuiceEasy{
public:
	vector<int> KiwiJuiceEasy::thePouring(vector<int> capacities,
										  vector<int> bottles,
										  vector<int> fromId, vector<int> toId)
	{
		int i, sum;

		size = fromId.size();
		for(i = 0; i < fromId.size(); i++){
			sum = bottles[fromId[i]] + bottles[toId[i]];
			bottles[toId[i]] = min(sum, capacities[toId[i]]);
			bottles[fromId[i]] = sum - bottles[toId[i]];
		}

		return bottles;
	}
};

```

## 정리

이번 문제에서는 다음 3개를 반드시 기억하라

1. 문제를 이해했다면 손으로 계산하라.
2. 코딩이 오래 걸린다면 다시 한번 손으로 계산하라.
3. 조건문은 되도록 적게 사용하라.
