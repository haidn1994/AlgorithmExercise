#include <iostream>
using namespace std;

int a[10001];

int main(void)
{
	int n, x; ios_base::sync_with_stdio(false);
	int i, temp;
	cin >> n >> x;
	for(i = 1; i <= n; i++)
		cin >> a[i];

	for(i = 1; i <= n; i++){
		if(a[i] < x){
			cout << a[i] << ' ';
		}
	}

	return 0;
}

