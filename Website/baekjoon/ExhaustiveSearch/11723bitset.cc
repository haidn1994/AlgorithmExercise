#include <cstdio>
#include <cstring>
using namespace std;

int bitset;
char inputs[100];

int main(void)
{
	int m, input_i;
	scanf("%d", &m);

	while(m--){
		// cin >> input_s >> input_i; <- 이렇게 코딩하면 중간에 프로그램이 종료해버린다. 뭐가 문제일까?
		// 그리고 iostream은 입출력이 느려서 채점에 통과하지 못한다. cstring을 사용하자.
		// 그리고 여기에 더해서 이진수도 배열과 마찬가지로 0부터 샌다는 사실도 잘 알고 있어야 한다.
		// 따라서 input_i--;코드가 반드시 들어가야 한다.
		scanf("%s", &inputs);
		if(!strcmp(inputs, "add")){
			scanf("%d", &input_i); input_i--;
			bitset |= (1 << input_i);
		}
		if(!strcmp(inputs, "remove")){
			scanf("%d", &input_i); input_i--;
			bitset &= ~(1 << input_i);
		}
		if(!strcmp(inputs, "check")){
			scanf("%d", &input_i); input_i--;
			printf("%d\n", ((bitset & (1 << input_i)) ? 1 : 0));
		}
		if(!strcmp(inputs, "toggle")){
			scanf("%d", &input_i); input_i--;
			bitset ^= (1 << input_i);
		}
		if(!strcmp(inputs, "all")){
			bitset = ((1 << 20) - 1);
		}
		if(!strcmp(inputs, "empty")){
			bitset = 0;
		}
	}

	return 0;
}
