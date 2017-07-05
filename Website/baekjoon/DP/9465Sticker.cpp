#include <stdio.h>
using namespace std;

int d[2][100001];

int main(void)
{
	int tc, n; ios_base::sync_with_stdio(false);
	int res;
	int i, j;
	cin >> tc;
	while(tc--){
		// 입력 받는 코드
		cin >> n;
		for(i = 0; i <= n; i++)
			cin >> d[0][i];
		for(i = 0; i <= n; i++)
			cin >> d[1][i];

		
		cout << res << '\n';
	}

	return 0;
}
