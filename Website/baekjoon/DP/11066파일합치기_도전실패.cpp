#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// /2017/07/07 실패: 조건이 1개 부족한것 같다.
// 다음날: 조건이 부족한 것이 아니고, 너무 복잡하게 나와서 틀린 줄 알았더니
// 그런것도 아닌가 보다.

// 젠장 한글로 번역된 문제설명에 누락된 조건이 있었다.
// 서로 인접한 파일만 합칠 수 있다. 
// 서로 인접한 파일 중에서 가장 작은 두 짝을 찾는 코드가 필요하다.

// 대충 어떻게 하는지는 알았는데, STL의 사용법 때문에 틀린것 같다.
// std::vector의 확실한 사용법을 익혀놓도록 하자!

// 파일의 크기는 10,000을 초과하지 않는다.
// 파일의 크기는 양의 정수이다.
int main(void)
{
	int tc, k; ios_base::sync_with_stdio(false);
	int i, j;
	// 가장 작은 두 짝을 찾는 문제이다!
	int smallest_pair_sum;
	std::vector<int>::iterator tempIt;
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
		// d[0] = *min_element(v.begin(), v.end());
		tempIt = v.begin()+1;
		smallest_pair_sum = v[0] + v[1];

		// v[0] + v[1]을 기본값으로 한다.
		for(j = 2; j < v.size(); j++)
			if(smallest_pair_sum > (v[j-1] + v[j])){
				smallest_pair_sum = (v[j-1] + v[j]);
				tempIt = v.begin()+j;
			}

		d[0] = smallest_pair_sum;
		
		for(i = 1; i < k; i++){
			/*
			smallest = *min_element(v.begin(), v.end());
			v.erase(min_element(v.begin(), v.end()));

			s_smallest = *min_element(v.begin(), v.end());
			*/

			// v[0] + v[1]을 기본값으로 한다.
			for(j = 2; j < v.size(); j++)
				if(smallest_pair_sum > (v[j-1] + v[j])){
					smallest_pair_sum = (v[j-1] + v[j]);
					tempIt = v.begin()+j;
				}

			for(i = 0; i < v.size(); i++)
				cout << "v[" << i << "]: " << v[i] << '\n';

			cout << "v[j-1]: " << v[j-1] << '\n';
			cout << "v[j]: " << v[j] << '\n';

			d[i] += d[i-1] + smallest_pair_sum;
			// 이 부분도 push_back이 아니라 다른 방법을 찾아야 한다.
			/*
			v.insert(min_element(v.begin(), v.end()), smallest_pair_sum);
			v.erase(min_element(v.begin(), v.end()));
			*/			
			v.erase(tempIt+1);
			tempIt = v.insert(tempIt, smallest_pair_sum);
			// v.erase(tempIt-1);

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

// 이터레이터로 찾아야 할 것 같다! 


// 뒤에 들어가는가? 앞에 들어가는가? 그것이 문제로다.
// "해당" 자리에 들어가 버린다.

