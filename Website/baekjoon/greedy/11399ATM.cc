#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int sum = 0, res = 0;
	int n, i; ios_base::sync_with_stdio(false);
	cin >> n;
	vector<int> pi(n);
	for(i = 0; i < n; i++)
		cin >> pi[i];
	sort(pi.begin(), pi.end());
	
	for(i = 0; i < n; i++){
		sum += pi[i];
		res += sum;
	}

	cout << res << '\n';
	return 0;
}
