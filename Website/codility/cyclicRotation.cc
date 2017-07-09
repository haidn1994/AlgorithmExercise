// 시간 복잡도 O(n)
// 공간 복잡도 O(n)의 코드, 처음 생각한 코드는 에러가 많이 난다.

vector<int> cyclicRotation(vector<int> &A, int K)
{
	int range = A.size();
	vector<int> temp(range);

	// 이게 좀 특이한 점이 있다, temp에 원형 큐를 응용한 식을 사용하면 에러가 안나는데,
	// A[]에 사용하면 에러가 뜬다. 왜일까?
	for(int i = 0; i < range; i++)
		temp[(i+K)%range] = A[i];
	return temp;
}
