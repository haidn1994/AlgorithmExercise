#include <iostream>
using namespace std;

// 붕어빵 개수 n에 대하여 얻을 수 있는 최대가격을 적어놓는다.
int d[1001];

// 붕어빵 세트메뉴 i개의 가격을 뜻한다. 
// 예를 들어, p[1] = 10이면 붕어빵 1개 세트메뉴의 가격은 10원
// p[2] = 15면 붕어빵 2개 세트메뉴의 가격은 15원이다.
int p[10001];

int max_price(int n)
{
	// 반복자 아님: get_max의 항을 나타내기 위함
	int idx;

	if(n == 0)
		return 0;
	if(d[n] > 0)
		return d[n];

	d[n] = get_max(&idx) + max_price(n - idx);
	return d(n);
}

int get_max(int *idx)
{	
	
}

int main(void)
{
	int n;
	cin >> n;
	// 여기에 한 라인을 받아서 쪼개주는 로직이 필요하다.
	cout << max_price(n) << '\n';

	return 0;
}
