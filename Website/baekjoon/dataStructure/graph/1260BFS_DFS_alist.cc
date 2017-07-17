/*
	인접 리스트를 활용한 DFS알고리즘과 BFS알고리즘
	사실 어떤 자료구조를 사용한다고 할지라도 DFS와 BFS의 시간 복잡도는 같다.

	시간 복잡도:
	인접 행렬로 구현하면 O(V^2)
	인접 리스트로 구현하면 O(V+E)
	간선 리스트로 구현하면 인접 리스트로 구현 한 것과 같다.

	공간 복잡도:
	인접 행렬로 구현하면 O(V^2)
	인접 리스트로 구현하면 O(E)
	간선 리스트로 구현하면 인접 리스트로 구현 한 것과 같다.

	여기서는 인접 리스트 + DFS는 재귀함수 활용을 통해서 구현을 알아보자.
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// 이건 2차원 배열
vector<int> a[1001];

// 방문했는지 아닌지를 알아보기 위한 배열
bool check [1001];

// 재귀 함수를 활용한 dfs의 구현
// 놀랍게도 재귀함수를 사용하면 함수 콜 프레임을 스택으로 활용할 수 있어서
// 명시적으로 스택이 필요없고 구현이 편하다.
void dfs(int node){
	int i;
	// 시작노드를 node로 받고, 시작노드는 방문한 것이나 다름 없으므로 true
	check[node] = true;
	printf("%d ", node);
	// C++은 항상 ::와 ->와 .이 헷갈린다. 확실하게 정리해야 한다!
	for(i = 0; i < a[node].size(); i++){
		// 실제로 2차원 배열처럼 사용할 수 있다는 것도 잊지 말 것!
		int next = a[node][i];
		if(check[next] == false)
			dfs(next);
	}
}

// 재귀함수로 구현한 bfs에 비해서 구현이 약간 어려운 편이지만 
// BFS는 중요할 뿐만 아니라 좋은 성질도 갖고 있으므로 유의해서 공부하자.
void bfs(int start){
	int i;
	// bfs는 큐를 사용하여 그래프를 탐색하는 알고리즘이다.
	// dfs는 스택을 사용하여 그래프를 탐색하는 알고즘이다.
	// 두 알고리즘의 목적은 같다. 주어진 그래프의 모든 정점을 빠짐 없이 방문하는 것...!
	queue<int> q;
	// C++에서 사용할 수 있는 메모리 초기화 함수는 std::fill_n()과 cstring안에 있는 memset이다.
	// 전자가 조금 더 편하지만, C에 익숙하다면 memset도 괜찮다.
	memset(check, false, sizeof(check));
	// 시작 정점은 방문확인 배열에 등록 해둔다.
	check[start] = true;
	// 큐에도 정점정보를 enqueue해놓는다.
	q.push(start);

	// 위에서 세팅을 다 마치면 해당과정을 큐가 텅텅 빌때까지 계속한다.
	while(!q.empty()){
		// 여기는 방문하지 않은 노드가 현재 노드의 간선에 없어서 큐에서 하나를 빼고 다시 찾는 로직
		int node = q.front();
		q.pop();
		printf("%d ", node);

		// 여기는 방문하지 않은 노드가 현재 노드의 간선에 연결되어 있으면 수행되는 로직
		for(i = 0; i < a[node].size(); i++){
			int next = a[node][i];
			if(check[next] == false){
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	int n, m, start;
	int i;
	scanf("%d %d %d", &n, &m, &start);
	for(i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(i = 1; i <= n; i++){
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	puts("");
	bfs(start);
	puts("");
	return 0;
}
