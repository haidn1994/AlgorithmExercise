#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	vector<pair<int, int>> pairs(n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &pairs[i].first, &pairs[i].second);

	// 비교함수를 만들어서 넘길 필요가 없다!
	// 이미 pair컨테이너 안쪽에서 연산자 오버로딩이 되어 있기 때문!
	// 만약 직접 구조체를 만든다면 두가지 방법이 있다.

	// 1. 비교함수를 만들어서 함수 포인터로 넘긴다.
	// 2. 연산자 오버로딩을 하여 sort내부에서 쓸 수 있게 한다.
	sort(pairs.begin(), pairs.end());
	for(i = 0; i < pairs.size(); i++)
		printf("%d %d\n", pairs[i].first, pairs[i].second);
	return 0;
}
