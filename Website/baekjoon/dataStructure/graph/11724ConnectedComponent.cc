#include <cstdio>
#include <vector>
using namespace std;

// 인접 리스트를 위한 벡터 배열
vector<int> a[1001];
// 방문 확인을 위한 bool배열
bool check[1001];

// 재귀 함수로 구현하면 함수 콜 프레임을 사용하면 되기 때문에, 명시적으로 스택을 사용할 필요도 없고,
// 간선 정보도 저장하지 않아도 된다. 정점 정보만 저장하면 된다.
void dfs(int node){
	int i;
	// 시작점이 되는 노드는 방문 한것으로...
	check[node] = true;
	for(i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if(check[next] == false){
			dfs(next);
		}
	}
}

int main(void)
{
	int n, m;
	int i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	// 연결요소의 개수를 나타내는 변수
	// 그런데 이 부분의 이해가 좀 어렵다.
	// 그림을 그리면서 이해하면 조금 더 이해가 잘 될지도...?
	int components = 0;
	for(i = 1; i <= n; i++){
		if(check[i] == false){
			// 처음 dfs를 돌리면 일단 도달할 수 있는 모든 정점은 모두 check한다.
			// 따라서 모든 정점에 대해 전부 dfs를 하면 각 연결요소마다 components++가 되어서
			// 우리가 원하는 답을 얻을 수 있다. 이렇게 해석하면 될 것 같다.
			dfs(i);
			components++;
		}
	}
	printf("%d\n", components);
	return 0;
}
