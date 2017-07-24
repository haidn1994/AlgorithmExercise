/*
	이 문제는 어떻게 푸는 것이 좋은가?
	1. 가장 일찍 시작하는 회의부터? -> X
	2. 가장 짧은 회의부터? -> X
	3. 가장 일찍 끝나는 회의부터? -> O

	따라서 가장 일찍 끝나는 회의를 그때그때마다 고르면 가장 많은 회의를 할 수 있다는 사실을 증명해야 한다.
	i를 최적해j로 바꿔도 정답은 같다(?)는 것이 이미 증명되어 있으므로 증명을 마치면 단순한 정렬문제가 된다. 
	여기에 회의의 시작시간과 끝나는 시간이 같을 수도 있다는 점을 고려하도록하자.
 */
#include <cstdio>
#include <vector>
#include <algorithm> // 여기에 next_permutaion과 prev_permutation이 들어있다!
using namespace std;

struct Meeting{
	int begin, end;
};

// 회의의 시작시간과 끝나는 시간이 같을 수도 있기때문에 그점 유의해서 조심해서 작성해야 한다.
bool cmp(const Meeting &x, const Meeting &y){
	return (x.end == y.end) ? (x.begin < y.begin) : (x.end < y.end);
	/*
	if(x.end == y.end){
		return x.begin < y.begin;
	} else {
		return x.end < y.end;
	}
	*/
}

int main(void)
{
	int n, i;
	int res = 0;
	int cur = 0;
	scanf("%d", &n);
	vector<Meeting> Meetings(n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &Meetings[i].begin, &Meetings[i].end);
	// 컨테이너의 처음과 끝, 그리고 시스템 자료형이 아니라면 비교해주는 함수에 대한 함수포인터를 넘겨줘야 한다.
	sort(Meetings.begin(), Meetings.end(), cmp);
	for(i = 0; i < n; i++){
		// 회의 시작시간이 같은 것도 포함해야 한다!!!
		if(Meetings[i].begin >= cur){
			cur = Meetings[i].end;
			res++;
		}
	}

	printf("%d\n", res);
	return 0;
}
