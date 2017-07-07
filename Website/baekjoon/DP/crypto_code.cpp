#include <iostream>
#include <string>
using namespace std;

// 1자리로 해석했을 경우와 2자리로 해석했을 경우 2가지로 나눠서 계산한다.
int d[5001][2];

int mod = 1000000;

int main(void)
{
	int r1_temp, r2_temp;
	int i, s_size, res;
	string cipher_text; ios_base::sync_with_stdio(false);
	cin >> cipher_text;


	d[1][0] = 1;
	// 음수일 가능성은 없음
	if((cipher_text[0] - '0')*10 + cipher_text[1] - '0' <= 26)
		d[1][1] = 1;
	else
		d[1][1] = 0;
	s_size = cipher_text.size();
	for(i = 1; i <= s_size; i++){
	}

	res = (d[s_size][0] + d[s_size][1]) % mod;
	cout << res << '\n'
	return 0;
}
