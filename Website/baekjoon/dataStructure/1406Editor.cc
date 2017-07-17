#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

char a[600000];

int main(void)
{
	// 가끔 C스타일의 문자열이나 표준 입출력이 필요한 순간이 있으므로 익혀놓았다가 쓰도록 하자.
	int range, ins, i;
	scanf("%s", a);
	stack<int> left, right;
	range = strlen(a);
	for(i = 0; i < range; i++)
		left.push(a[i]);

	// 핵심
	scanf("%d", &ins);
	while(ins--){
		char input;
		scanf(" %c", &input);
		if(input == 'L'){
			if(!left.empty()){
				right.push(left.top());
				left.pop();
			}
		}
		if(input == 'D'){
			if(!right.empty()){
				left.push(right.top());
				right.pop();
			}
		}
		if(input == 'B'){
			if(!left.empty()){
				left.pop();
			}
		}
		if(input == 'P'){
			char c;
			scanf(" %c", &c);
			left.push(c);
		}
	}

	// 마무리
	while(!left.empty()){
		right.push(left.top());
		left.pop();
	}
	while(!right.empty()){
		printf("%c", right.top());
		right.pop();
	}
	printf("\n");
	return 0;
}
