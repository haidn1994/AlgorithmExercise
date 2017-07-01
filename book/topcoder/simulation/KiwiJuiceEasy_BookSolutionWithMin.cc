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
