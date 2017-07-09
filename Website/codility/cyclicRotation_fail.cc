/*
 * 꽤나 충격적인 결과인데, 아무래도 내가 배열 회전에 대해서 좀 잘못 알고 있었던것 같다.
 * 이번 로 제대로 알아보도록 하자.
 */ 

// 틑린 코드

#include <vector>
#include <iostream>
using namespace std;

vector<int> cyclicRotation(vector<int> &A, int K)
{
	vector<int> temp(K);
	int range;
	int i;

	for(i = 0; i < K; i++)
		temp[i] = A[i+K-1];
	range = (A.size()-K)+1
	for(i = 0; i < range; i++)
		A[i+K] = A[i];
	range = temp.size();
	for(i = 0; i < range; i++)
		A[i] = temp[i];

	return A;
}

