#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> a[20001];
// 여기는 이제 bool대신에 더 많은 정보를 표현해야 하므로, int형 타입을 사용해야 한다.
int color[20001];

// 물론 전반적인 코드는 완전히 같지만 색깔 정보를 다루기 위해서 부분부분이 조금씩 변경되었다.
void dfs(int node, int c){
	int i;
	color[node] = c;
	for(i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if(color[next] == 0)
			dfs(next, 3-c);
	}
}

int main(void)
{
	int tc;
	// 그래프 정점과 간선의 총 개수
	int n, m;
	// 정점 간선 연결 정보를 그때 그때 받아주는 변수
	int u, v;
	bool isBiGraph;
	int i, j, k;
	scanf("%d\n", &tc);
	
	// 핵심 로직
	while(tc--){
		scanf("%d %d", &n, &m);
		for(i = 1; i<= n; i++){
			// 벡터의 API를 한번 정도는 정리하는 공부가 필요할 것 같다.
			a[i].clear();
			color[i] = 0;
		}
		for(i = 0; i < m; i++){
			scanf("%d %d", &u, &v);
			// 해당 코드는 양방향 그래프임을 가정하고 만들어졌다.
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(i = 1; i <= n; i++){
			// color값이 0이라면 아직 해당 정점에 어떤 색깔도 주어지지 않았음을 의미한다.
			if(color[i] == 0)
				dfs(i, 1);
		}
		isBiGraph = true;
		for(i = 1; i <= n; i++){
			for(k = 0; k < a[i].size(); k++){
				j = a[i][k];
				if(color[i] == color[j]) isBiGraph = false;
			}
		}
		printf("%s\n", isBiGraph ? "YES" : "NO");
	}

	return 0;
}
