/*
 * Codility - binaryGap
 *
 * 문제의 설명은 코딜리티 홈페이지에 가서 찾아볼것
 * N을 이진수로 표현했을 때 1과 1사이에 있는 가장 긴 0-부분 비트스트링의 길이를 구하는 문제
 */

int BinaryGap(int N)
{
	int sizeChecker = 0x80000000;
	int maskingNum = 0x00000001;
	int size = 0, res = 0, res_candi = 0;
	int i;

	// pre-processing
	// 왼쪽 0-구간을 제외하기 위함
	
	// 잘 하면 이 부분의 루프를 없앨수 있을 것 같다.
	// 1. 오른쪽 0-구간을 1로 전부 바꿔치기 한다.
	// 2. N으로 표현된 비트스트링을 뒤집는다.(~등 비트 부정연산이 아니라 비트스트링을 회전해야 함)
	// 3. 회전된 비트스트링에 다시 1로 바꿔치기 하는 코드를 적용한다.
	// 4. 최대 binaryGap을 찾는 루프를 돌린다.
	while(!(sizeChecker & N)){
		size++;
		sizeChecker >>= 1;
	}
	// 오른쪽 0-구간을 제외하기 위함
	N = N | (N - 1);
	
	// 0-구간을 제외하면 예외처리가 쉬워지거나 할 필요가 없어진다.
	// 이 경우, 예외처리가 필요없어진다.
	for(i = 0; i <= 31 - size; i++, maskingNum <<= 1){
		if(!(maskingNum & N)){
			res_candi++;
		} else {
			if(res < res_candi)
				res = res_candi;
			res_cand = 0;
		}
	}

	return res;
}
