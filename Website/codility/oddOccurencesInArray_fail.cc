/*
	일단 내가 처음 작성한 소스이다.

	역시나 내가 처음 한 방법은 틀렸다. 
	대신 다음 2가지 솔루션이 있다.

	1. xor 연산을 사용:
	이 문제의 궁극의 해결책이다.
	int result에 첫번째 원소를 집어넣고 모든 요소에 대해 xor을 해주는 
	반복문 한번 돌리면 짝이 있는 녀석들은 서로 xor을 짝수번 하기 때문에 덧셈에 대한 항등원인 0으로 돌아와 버린다.
	따라서 0에다가 배열 내부에 짝이 없는 수를 더한것과 같은 결과를 얻게 되는데, 이는 답과 같다.

	2. sort를 사용
	스택에 들어온 배열에다가 sort를 적용하면 같은 수는 서로 붙어있게 된다.
	붙어있게 된다는 특성을 사용하면 짝이 없는 녀석을 골라내는 일이 훨씬 쉽게 된다.
	대신 시간 복잡도는 장담할 수 없다. 한번 실험해 봐야겠다.
	
 */

int solution(vector<int> &A) {
	int range = A.size();
	int temp = 0, pair_idx, i;

	for(i = 0, pair_idx = 0; i < range; i++){
		if(A[i] == 0) continue;

		for(pair_idx = i; ;pair_idx += 2){
			if(pair_idx > range)
				goto result;
			if(temp != 0){
				if(temp == A[pair_idx]){ 
					A[pair_idx] = 0;
					temp =0;
					break;
				}
			}
			if(temp == 0 && A[pair_idx] != 0){
				temp = A[pair_idx];
			}
		}
	}

result:
	return temp;
}
