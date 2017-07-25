#include <stdio.h>

int swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while(low <= high){
		while(pivot >= arr[low] && low <= right)
			low++;

		while(pivot <= arr[high] && high >= (left+1))
			high--;

		if(low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}

void quick_sort(int arr[], int left, int right)
{
	while(left <= right){
		int pivot = partition(arr, left, right);
		quick_sort(arr, left, pivot-1);
		quick_sort(arr, pivot+1, right);
	}
}

int main(void)
{
}
