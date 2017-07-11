#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s; ios_base::sync_with_stdio(false);
	int range;
	int lower, upper, number, blank, i;

	while(getline(cin, s)){
		range = s.size();
		lower = upper = number = blank = 0;
		for(i = 0; i < range; i++){
			if('a' <= s[i] && s[i] <= 'z')
				lower++;
			if('A' <= s[i] && s[i] <= 'Z')
				upper++;
			if('0' <= s[i] && s[i] <= '9')
				number++;
			if(s[i] == ' ')
				blank++;
		}
		printf("%d %d %d %d\n", lower, upper, number, blank);
	}

	return 0;
}
