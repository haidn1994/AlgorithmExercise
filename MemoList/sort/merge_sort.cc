#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void merge_two_area(vector<int> arr, int left, int mid, int right)
{
	int f_idx = left;
	int r_idx = mid + 1;
	int s_idx = left;
	vector<int> sort_arr(right+1);
	int i, j;

	while(f_idx <= mid && r_idx <= right){
		if(arr[f_idx] <= arr[r_idx])
			sort_arr[s_idx] = arr[f_idx++];
		else
			sort_arr[s_idx] = arr[r_idx++];
		s_idx++;
	}

	if(f_idx > mid)
		for(i = r_idx; i <= right; i++, s_idx++)
			sort_arr[s_idx] = arr[i];
	else
		for(i = f_idx; i <= mid; i++, s_idx++)
			sort_arr[s_idx] = arr[i];

	for(i = left; i <= right; i++)
		arr[i] = sort_arr[i];
	// 메모리 해제.
}
void merge_sort(vector<int> arr, int left, int right)
{
	int mid;

	while(left < right){
		mid = (left + right) / 2;

		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		merge_two_area(arr, left, mid, right);
	}
}



int main(void)
{
	vector<int> target = {3, 2, 4, 5, 1, 5, 1, 2, 5, 6, 7, 3, 62, 23, 1, 5};
	int left = 0, right = target.size() - 1;
	int i;

	for(i = 0; i < target.size(); i++)
		cout << target[i] << ' ';
	cout << '\n';
	merge_sort(target, left, right);

	for(i = 0; i < target.size(); i++)
		cout << target[i] << ' ';
	cout << '\n';
	return 0;
}
