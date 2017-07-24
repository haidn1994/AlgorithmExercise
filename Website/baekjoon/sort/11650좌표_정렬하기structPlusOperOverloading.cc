#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

// 오버로딩 문법이 좀 독특해 보인다.
struct Point{
	int x, y;
	bool operator < (const Point &v) const {
		if(x < v.x)
			return true;
		else if(x == v.x)
			return y < v.y;
		else
			return false;
	}
};


// 구조체를 만들고 연산자를 오버로딩해서 문제를 푸는 버전.
// 이렇게 해야만 하는 이유가 있을때만 할 것. 
// 현업에서는 pair사용법을 익혔다면 굳이 이런방식으로 할 필요가 없다.
int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	vector<Point> pairs(n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &pairs[i].x, &pairs[i].y);

	// 이제 비교함수가 필요없어진다.
	sort(pairs.begin(), pairs.end());
	for(i = 0; i < pairs.size(); i++)
		printf("%d %d\n", pairs[i].x, pairs[i].y);
	return 0;
}

