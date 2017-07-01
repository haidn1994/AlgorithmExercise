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
