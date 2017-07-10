#include <map>
#include <set>
#include <iostream>
using namespace std;

// map을 이용한 풀이
// 출처: http://doanhv.com/codefightsinterview-practice-firstduplicate/
int firstDuplicate(std::vector<int> a) {
	map<int, int> m;
	int range, i;

	range = a.size();
	for(i = 0; i < range; i++){
		if(m.find(a[i]) != m.end())
			return a[i];
		else
			m.insert(std::pair<int, int> (a[i], 1));
	}

	return -1;
}

// set을 이용한 풀이
// 출처: artashes_k - c++ 4등 풀이
int firstDuplicate(std::vector<int> a) {
	set<int> s;
	int r=-1;
	for(int x:a){
		if(s.find(x)!=s.end())
			return x;
		s.insert(x);
	}

	return r;
}


// abs()를 사용한 풀이
// theinbui - c++ 1등 풀이
int firstDuplicate(std::vector<int> a) {
	for(int i=0;i<a.size();i++){
		int v = abs(a[i]) -1;
		if(a[v] < 0) return v + 1;
		a[v] = -a[v];
	}
	return -1;
}

// 비트마스크를 이용한 풀이
// daren - C++ 2등 풀이
int firstDuplicate(std::vector<int> a) {
	for(int i:a) {
		i=i&0x7fffffff;
		if(a[i-1]>>31)
			return i;
		else
			a[i-1]|=1<<31;
	}
	return -1;
}


