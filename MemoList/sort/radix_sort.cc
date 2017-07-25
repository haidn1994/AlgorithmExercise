#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

void radix_sort(vector<int> &arr, int num, int max_len)
{
	// 매개변수 max_len에는 정렬대상 중 가장 긴 데이터의 길이 정보가 전달된다.
	queue<int> buckets[10];
	int bi, di;
	int pos;
	int divfac = 1;
	int radix;

	// 가장 긴 데이터의 길이만큼 반복한다.
	for(pos = 0; pos < max_len; pos++)
	{
		// 정렬 대상의 수만큼 반복한다.
		for(di = 0; di < num; di++){
			radix = (arr[di]/divfac) % 10;
			buckets[radix].push(arr[di]);
		}

		// 버킷 수만큼 반복한다.
		for(bi = 0, di = 0; bi < 10; bi++){
			while(!buckets[bi].empty()){
				arr[di++] = buckets[bi].front();
				buckets[bi].pop();
			}
		}

		divfac *= 10;
	}
}

int main(void)
{
	vector<int> arr = {13, 212, 13, 7141, 10987, 6, 15};

	int len = arr.size();
	int i;

	for(i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	radix_sort(arr, len, 5);

	for(i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}
