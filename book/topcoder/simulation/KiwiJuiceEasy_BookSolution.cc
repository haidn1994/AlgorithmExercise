#include <vector>
using namespace std;

/*
	기본적인 개념은 다행히 맞은것 같다.
	그런데 C++의 특징은 stack으로 들어온 변수도 입맛대로 상태를 바꾸어서 다시 반환값으로 사용할수 있는것 같다.
 */

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
