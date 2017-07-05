#include <iostream>
#include <algorithm>
using namespace std;

int d[10001][3];
int w[10001];

int main(void)
{
	int n; ios_base::sync_with_stdio(false);
	int i, j, res;

	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> w[i];
	
	d[1][0] = d[1][1] = d[1][2] = w[1];
	d[2][0] = d[2][1] = d[2][2] = w[1] + w[2];
	for(i = 1; i <= n; i++){
		d[i][0] = w[i-2] + w[i-1];
		d[i][1] = w[i-2] + w[i];
		d[i][2] = w[i-1] + w[i];
	}
		
	// res = std::max(d[n][0], d[n][2]);
	res = d[n][0] + d[n][1] + d[n][2];
	cout << res << '\n';
	return 0;
}
