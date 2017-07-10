#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A)
{
	int temp = a[0], range;
	int i;

	range = a.size();
	for(i = 1; i < range; i++)
		temp ^= A[i];
	return temp;
}

int main(void)
{
	int n, i;
	cin >> n;
	vector<int> v(n);
	for(i = 0; i < v.size(); i++)
		cin >> v[i];

	cout << solution(v) << '\n';
	return 0;
}
