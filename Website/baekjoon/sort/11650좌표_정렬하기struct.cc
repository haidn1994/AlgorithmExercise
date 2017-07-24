#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Point{
	int x, y;
};

// 이 함수를 만들때(정확히 말하면 비교함수를 만들 때) const와 &는 붙여야 한다.
bool cmp(const Point &u, const Point &v)
{
	if(u.x < v.x)
		return true;
	else if(u.x == v.x)
		return u.y < v.y;
	else
		return false;
}

// 구조체를 만들고 비교함수도 만들어서 문제를 푸는 버전.
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

	sort(pairs.begin(), pairs.end(), cmp);
	for(i = 0; i < pairs.size(); i++)
		printf("%d %d\n", pairs[i].x, pairs[i].y);
	return 0;
}

