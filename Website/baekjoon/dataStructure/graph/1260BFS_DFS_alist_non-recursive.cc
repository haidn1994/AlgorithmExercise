/*
	인접 리스트를 활용하되, 재귀적인 구현을 배제한 DFS구현을 선보인다.
	따라서 함수 콜 프레임을 사용할 수 없기 때문에, STL stack을 사용해야 한다.
 */

#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// 인접 리스트 대신 사용할 컨테이너
vector<int> a[1001];

// 방문유무를 검사하는 배열
bool check[1001];

void dfs(int node)
{
	int i;
	// 그리고 정점 정보만 넣어서도 안되고, 정점과 간선 정보를 한 데 넣어야 한다.
	// 따라서 pair를 사용하는 것이 제일 좋다.
	stack<pair<int, int>> s;
	s.push(make_pair(node, 0));
	printf("%d ", node);
	while(!s.empty()){
		int node = s.top().first;
		int start = s.top().second;
		s.pop();
		for(i = start; i < a[node].size(); i++){
			int next = a[next][i];
			if(check[next] == false){
				printf("%d", next);
				check[next] = true;
				s.push(make_pair(node, i+1));
				s.push(make_pair(next, 0));
				break;
			}
		}
	}
}


// 맨 처음 만든 BFS알고리즘과 완전히 같다.
void bfs(int start){
	int i;
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true;
	q.push(start);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		printf("%d ", node);

		for(i = 0; i < a.[node].size(); i++){
			int next = a[node][i];
			if(check[next] == false){
				check[next] = true;
				q.push(next);
			}
		}
	}
}


// main함수도 마찬가지로 맨 처음 만든 것과 완전히 같다.
int main(void)
{
	// 세팅
	int n, m, start;
	int i;
	scanf("%d %d %d", &n, &m, &start);
	for(i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end());

	// 핵심 알고리즘 호출
	dfs(start);
	puts("");
	bfs(start);
	puts("");
	return 0;
}
