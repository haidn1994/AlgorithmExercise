#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A)
{
	int temp, range;
	int i, j;
	std::sort(A.begin(), A.end());

	range = A.size();
	for(i = 0; i < range; i+=2){
		temp = A[i];
		if(A[i] == A[i+1])
			continue;
		else
			break;
	}
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
