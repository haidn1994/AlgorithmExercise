#include <iostream>
using namespace std;

int d[41][2];

int main(void)
{
	int tc, n, i; ios_base::sync_with_stdio(false);
	cin >> tc;

	d[1][0] = d[0][1] = 0;
	d[1][1] = d[0][0] = 1;
	while(tc--){
		cin >> n;
		for(i = 2; i <= n; i++){
			d[i][0] = d[i-1][0] + d[i-2][0];
			d[i][1] = d[i-1][1] + d[i-2][1];
		}

		cout << d[n][0] << ' ' << d[n][1] << '\n';
	}

	return 0;
}

