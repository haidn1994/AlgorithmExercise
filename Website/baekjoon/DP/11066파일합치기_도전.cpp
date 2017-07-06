#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// /2017/07/07 실패: 조건이 1개 부족한것 같다.

// 파일의 크기는 10,000을 초과하지 않는다.
// 파일의 크기는 양의 정수이다.
int main(void)
{
	int tc, k; ios_base::sync_with_stdio(false);
	int i, j;
	// 앞에서부터 제일 작음, 둘째로 작음
	int smallest, s_smallest;
	int res;

	cin >> tc;
	while(tc--){
		// 입력
		cin >> k;
		vector<int> v(k);

		for(i = 0; i < k; i++)
			cin >> v[i];
		vector<int> d(k);	

		// 핵심로직: 이 문제는 조건문이 상당히 복잡하게 나오는 것 같다.
		d[0] = *min_element(v.begin(), v.end());
		v.erase(min_element(v.begin(), v.end()));
		
		for(i = 1; i < k; i++){
			smallest = *min_element(v.begin(), v.end());
			if(v.size() > 0)
				v.erase(min_element(v.begin(), v.end()));
			cout << "smallest: " << smallest << '\n';

			s_smallest = *min_element(v.begin(), v.end());
			cout << "s_smallest: " << s_smallest << '\n';

			if(smallest < d[i-1] && s_smallest < d[i-1]){
				d[i] += d[i-1] + (smallest + s_smallest);
				if(v.size() > 0)
					v.erase(min_element(v.begin(), v.end()));
				v.push_back(smallest + s_smallest);
			} else {
				d[i] += d[i-1] + smallest + d[i-1];
				v.push_back(smallest + d[i-1]);
			}

			cout << "d[i]: " << d[i] << '\n';
		}
		

		// 출력: 1차원 배열만 있어도 충분한 문제로 보인다?
		// 벡터는 해당 스코프를 벗어나면 자동으로 소멸하는 것으로 알고 있다!
		//for(i = 1; i < k; i++)
		res = d[k-1] - d[0];
		cout << res << '\n';
	}

	return 0;
}
