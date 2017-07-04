#include <iostream>
using namespace std;

// length자리 이친수의 개수를 여기에 집어넣는다.
int d[91];

// 검사에 필요한 몇가지 변수들
int input;
bool is_before1 = false;

int vinary(int length)
{
	if(length == 1)
		return 1;
	if(d[length] > 0)
		return d[length];

	// 맨앞쪽 문자를 뜻하는가?
	if(length == input)
		d[length] = vinary(length-1);
	// 바로 뒤쪽 문자와 현재 문자가 전부 1인가?
	else if(is_before1){
		d[length] = vinary(length-1);
		is_before1 = false;
	// 이친수가 맞으므로 숫자를 하나 올려준다.
	} else {
		d[length] = vinary(length-1) + vinary(length-1);
		is_before1 = true;
	}
	return d[length];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> input;
	cout << vinary(input) << '\n';

	return 0;
}
