#include <iostream>
using namespace std;

int v[1000];

// 이건 이렇게 푸는 문제가 아니다!
// 가장 긴 "부분"수열이라는 뜻이 괜히 있는 것이 아니다!
int main(void)
{
	int n; ios_base::sync_with_stdio(false);
	int max_temp, length = 1;
	int i;
	cin >> n;
	for(i = 0; i < n; i++)
		cin >> v[i];
	max_temp = v[0];

	for(i = 1; i < n; i++){
		if(max_temp < v[i]){
			max_temp = v[i];
			length++;
		}
	}

	cout << length << '\n';
	return 0;
}
