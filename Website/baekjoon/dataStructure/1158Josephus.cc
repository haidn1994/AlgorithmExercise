#include <cstdio>
#include <queue>
using namespace std;

int main(void)
{
	int n, m;
	queue<int> q;
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++)
		q.push(i);

	printf("<");
	// 그리고 무조건 n-1번 m-1번만 반복하면 된다.
	for(i = 0; i < n-1; i++){
		for(j = 0; j < m-1; j++){
			q.push(q.front());
			q.pop(); // 반환값 때문에 바로 q.pop을 할 수는 없다. 
		}
		printf("%d ", q.front());
		q.pop();
	}
	printf("%d>", q.front());
	return 0;
}
